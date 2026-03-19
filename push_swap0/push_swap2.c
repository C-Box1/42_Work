#include "push_swap.h"

void	ft_run(t_context *ctx, int bench)
{
	double	disorder;
	int		stack_size;

	stack_size = get_stack_size(*(ctx->a));
	ft_index(*(ctx->a), stack_size);
	disorder = compute_disorder(*(ctx->a));
	if (disorder == 0.0)
	{
		free_stack(*(ctx->a));
		free_stack(*(ctx->b));
		return ;
	}
	ft_algorithm(disorder, ctx);
	if (bench)
		print_benchmarks(disorder, ctx->mode_flag, ctx->stats);
	free_stack(*(ctx->a));
	free_stack(*(ctx->b));
}