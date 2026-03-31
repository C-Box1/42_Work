#include "push_swap.h"

static void push_chunk_to_b(t_context *ctx, int min, int max)
{
    while (still_in_chunk(*(ctx->a), min, max))
    {
        if ((*(ctx->a))->index >= min && (*(ctx->a))->index <= max)
        {
            ft_pb(ctx->b, ctx->a, ctx->stats);
            if ((*(ctx->b))->index < (min + max) / 2)
                ft_rb(ctx->b, ctx->stats);
        }
        else
            ft_ra(ctx->a, ctx->stats);
    }
}

static void rotate_b_to_top(t_context *ctx, int max_idx)
{
	int		pos;
	int		size;
	int		i;
	t_stack	*ptr;

	pos = 0;
	size = get_stack_size(*(ctx->b));
	i = 0;
	ptr = *(ctx->b);
	while (ptr && ptr->index != max_idx)
	{
		pos++;
		ptr = ptr->next;
	}
	if (pos <= size / 2)
		while (i++ < pos)
			ft_rb(ctx->b, ctx->stats);
	else
		while (i++ < (size - pos))
			ft_rrb(ctx->b, ctx->stats);
}

static void	push_sorted_back(t_context *ctx)
{
	int	max_idx;

	while (*(ctx->b))
	{
		max_idx = find_max_index(*(ctx->b));
		rotate_b_to_top(ctx, max_idx);
		ft_pa(ctx->a, ctx->b, ctx->stats);
	}
}

static void	chunk_sort(t_context *ctx, int total, int chunk_count)
{
	int	chunk_size;
	int	i;
	int	min;
	int	max;

	chunk_size = (total + chunk_count - 1) / chunk_count;
	i = 0;
	while (i < chunk_count)
	{
		min = i * chunk_size;
		max = min + chunk_size - 1;
		if (max >= total)
			max = total - 1;
		push_chunk_to_b(ctx, min, max);
		i++;
	}
	while (*(ctx->a))
		ft_pb(ctx->b, ctx->a, ctx->stats);
	push_sorted_back(ctx);
}

void run_medium_algorithm(t_context *ctx)
{
	int size;
	int chunk_count;

	size = get_stack_size(*(ctx->a));
	if (size <= 10)
		chunk_count = 2;
	else if (size <= 100)
		chunk_count = 5;
	else if (size <= 500)
    	chunk_count = 11;
	else
    	chunk_count = size / 45;
        
	chunk_sort(ctx, size, chunk_count);
}
