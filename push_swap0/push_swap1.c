#include "push_swap.h"

void	ft_algorithm(double disorder, t_context *ctx)
{
	int size;
	
	size = get_stack_size(*(ctx->a));
    if (size <= 1)
        return;
    if (size <= 3)
    {
        run_small_sort(ctx, size);
        return;
    }
    if (size <= 5)
    {
        run_simple_algorithm(ctx);
        return;
    }
	if (ctx->mode_flag == 0)
	{
		if (disorder < 0.2)
			run_simple_algorithm(ctx);
		else if (disorder < 0.5)
			run_medium_algorithm(ctx);
		else
			run_complex_algorithm(ctx);
	}
	else if (ctx->mode_flag == 1)
		run_simple_algorithm(ctx);
	else if (ctx->mode_flag == 2)
		run_medium_algorithm(ctx);
	else if (ctx->mode_flag == 3)
		run_complex_algorithm(ctx);
}

static void	parse_flags(char *arg, t_context *ctx, int *bench)
{
	if (ft_strncmp(arg, "--simple", 8) == 0)
		ctx->mode_flag = 1;
	else if (ft_strncmp(arg, "--medium", 8) == 0)
		ctx->mode_flag = 2;
	else if (ft_strncmp(arg, "--complex", 9) == 0)
		ctx->mode_flag = 3;
	else if (ft_strncmp(arg, "--adaptive", 10) == 0)
		ctx->mode_flag = 0;
	else if (ft_strncmp(arg, "--bench", 7) == 0)
		*bench = 1;
	else
		error_exit(*(ctx->a), *(ctx->b));
}

static void	parse_arguments(int argc, char **argv, t_context *ctx, int *bench)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (ft_strncmp(argv[i], "--", 2) == 0)
			parse_flags(argv[i], ctx, bench);
		else
		{
			if (ft_strchr(argv[i], ' '))
				*(ctx->a) = parse_and_add(argv[i], *(ctx->a), *(ctx->b));
			else
			{
				if (!is_valid_integer(argv[i]) || is_duplicate(*(ctx->a), ft_atoi(argv[i])))
					error_exit(*(ctx->a), *(ctx->b));
				*(ctx->a) = add_to_end(*(ctx->a), ft_atoi(argv[i]));
			}
		}
		i++;
	}
}

static void	init_all(t_stack **a, t_stack **b, t_stats *stats, t_context *ctx)
{
	*a = NULL;
	*b = NULL;
	*stats = (t_stats){0};
	ctx->a = a;
	ctx->b = b;
	ctx->stats = stats;
	ctx->mode_flag = 0;
}

int	push_swap(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;
	t_stats		stats;
	t_context	ctx;
	int			bench;

	init_all(&a, &b, &stats, &ctx);
	bench = 0;
	parse_arguments(argc, argv, &ctx, &bench);
	ft_run(&ctx, bench);
	return (0);
}