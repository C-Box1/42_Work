#include "push_swap.h"


void ft_pa(t_stack** a, t_stack** b, t_stats *stats)
{
	t_stack	*tmp;

	if (!*b)
		return;
	tmp = *b;
	*b = (*b)->next;
	tmp->next = *a;
	*a = tmp;
	if (stats)
	{
		stats->pa_count++;
		stats->total++;
	}
	ft_putstr("pa\n");
}


void ft_pb(t_stack** b, t_stack** a, t_stats *stats)
{
	t_stack	*tmp;

	if (!*a)
		return;
	tmp = *a;
	*a = (*a)->next;
	tmp->next = *b;
	*b = tmp;
	if (stats)
	{ 
		stats->pb_count++;
		stats->total++;
	}
	ft_putstr("pb\n");
}