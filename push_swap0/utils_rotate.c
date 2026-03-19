#include "push_swap.h"

void ft_ra(t_stack** a, t_stats *stats)
{
	t_stack	*tmp;
	t_stack	*last;

	if (!a || !(*a)->next)
		return;
	tmp = *a;
	*a = (*a)->next;
	tmp->next = NULL;
	last = *a;
	while (last->next)
		last = last->next;
	last->next = tmp;
	if (stats)
	{ 
		stats->ra_count++;
		stats->total++;
	}
	ft_putstr("ra\n");
}

void ft_rb(t_stack** b, t_stats *stats)
{
	t_stack	*tmp;
	t_stack	*last;

	if (!b || !(*b)->next)
		return;
	tmp = *b;
	*b = (*b)->next;
	tmp->next = NULL;
	last = *b;
	while (last->next)
		last = last->next;
	last->next = tmp;
	if (stats)
	{ 
		stats->rb_count++;
		stats->total++;
	}
	ft_putstr("rb\n");
}

void ft_rr(t_stack** a, t_stack** b, t_stats *stats)
{
	ft_ra(a, NULL);
	ft_rb(b, NULL);
	if (stats)
	{ 
		stats->rr_count++;
		stats->total++;
	}
	ft_putstr("rr\n");
}