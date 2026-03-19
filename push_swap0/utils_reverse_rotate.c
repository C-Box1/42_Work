#include "push_swap.h"

void ft_rra(t_stack** a, t_stats *stats)
{
	t_stack	*tmp;
	t_stack	*last;

	if (!a || !(*a)->next)
		return;
	tmp = *a;
	while (tmp->next->next)
		tmp = tmp->next;
	last = tmp->next;
	tmp->next = NULL;
	last->next = *a;
	*a = last;
	if (stats)
	{
		stats->rra_count++;
		stats->total++;
	}
	ft_putstr("rra\n");
}

void ft_rrb(t_stack** b, t_stats *stats)
{
	t_stack	*tmp;
	t_stack	*last;

	if (!b || !(*b)->next)
		return;
	tmp = *b;
	while (tmp->next->next)
		tmp = tmp->next;
	last = tmp->next;
	tmp->next = NULL;
	last->next = *b;
	*b = last;
	if (stats)
	{ 
		stats->rrb_count++;
		stats->total++;
	}
	ft_putstr("rrb\n");
}

void ft_rrr(t_stack** a, t_stack** b, t_stats *stats)
{
	ft_rra(a, NULL);
	ft_rrb(b, NULL);
	if (stats)
	{ 
		stats->rrr_count++;
		stats->total++;
	}
	ft_putstr("rrr\n");
}