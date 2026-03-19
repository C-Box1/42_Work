#include "push_swap.h"

static void	sort_three_max_mid(t_context *ctx, int a, int c)
{
	if (a < c)
	{
		ft_rra(ctx->a, ctx->stats);
		ft_sa(ctx->a, ctx->stats);
	}
	else
		ft_rra(ctx->a, ctx->stats);
}

static void	sort_three(t_context *ctx)
{
	int	a;
	int	b;
	int	c;

	a = (*(ctx->a))->index;
	b = (*(ctx->a))->next->index;
	c = (*(ctx->a))->next->next->index;
	if (a < b && b < c)
		return ;
	if (a > b && b < c)
	{
		if (a < c)
			ft_sa(ctx->a, ctx->stats);
		else
			ft_ra(ctx->a, ctx->stats);
	}
	else if (a > b)
	{
		ft_sa(ctx->a, ctx->stats);
		ft_rra(ctx->a, ctx->stats);
	}
	else
		sort_three_max_mid(ctx, a, c);
}

static void	sort_two(t_context *ctx)
{
	if ((*(ctx->a))->index > (*(ctx->a))->next->index)
		ft_sa(ctx->a, ctx->stats);
}

void	run_small_sort(t_context *ctx, int size)
{
	if (size == 2)
		sort_two(ctx);
	else if (size == 3)
		sort_three(ctx);
}