#include "push_swap.h"

static int	find_min_pos(t_stack *a)
{
	int	min_pos;
	int	cur_pos;
	int	min_idx;

	min_pos = 0;
	cur_pos = 0;
	min_idx = a->index;
	while (a)
	{
		if (a->index < min_idx)
		{
			min_idx = a->index;
			min_pos = cur_pos;
		}
		cur_pos++;
		a = a->next;
	}
	return (min_pos);
}

static void	bring_min_to_top(t_context *ctx)
{
	int	pos;
	int	size;
	int	i;

	size = get_stack_size(*(ctx->a));
	pos = find_min_pos(*(ctx->a));
	i = 0;
	if (pos <= size / 2)
		while (i++ < pos)
			ft_ra(ctx->a, ctx->stats);
	else
		while (i++ < (size - pos))
			ft_rra(ctx->a, ctx->stats);
}

void	run_simple_algorithm(t_context *ctx)
{
	int	size;

	size = get_stack_size(*(ctx->a));
	if (size <= 1)
		return ;
	if (size <= 3)
		return (run_small_sort(ctx, size));
	while (*(ctx->a))
	{
		bring_min_to_top(ctx);
		ft_pb(ctx->b, ctx->a, ctx->stats);
	}
	while (*(ctx->b))
		ft_pa(ctx->a, ctx->b, ctx->stats);
}