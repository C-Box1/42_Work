#include "push_swap.h"

static int get_max_bits(int n)
{
	int	bits;

	bits = 0;
	while (n >> bits)
		bits++;
	return (bits);
}

static void radix_sort(t_context *ctx)
{
	int	i;
	int	j;
	int	size;
	int	max_bits;

	size = get_stack_size(*(ctx->a));
	max_bits = get_max_bits(size - 1);
	for (i = 0; i < max_bits; i++)
	{
		j = 0;
		while (j < size)
		{
			if ( ((*(ctx->a))->index >> i) & 1 )
				ft_ra(ctx->a, ctx->stats);
			else
				ft_pb(ctx->b, ctx->a, ctx->stats);
			j++;
		}
		while (*(ctx->b))
			ft_pa(ctx->a, ctx->b, ctx->stats);
	}
}

void	run_complex_algorithm(t_context *ctx)
{
	radix_sort(ctx);
}

int find_max_index(t_stack *b)
{
    int max_idx; 
	
	max_idx = -1;
    while (b)
    {
        if (b->index > max_idx)
            max_idx = b->index;
        b = b->next;
    }
    return (max_idx);
}
