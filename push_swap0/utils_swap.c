#include "push_swap.h"

void ft_sa(t_stack** a, t_stats *stats)
{
	t_stack	*tmp;

	if (!a || !(*a)->next)
		return;
	tmp = *a;
	*a = (*a)->next;
	tmp->next = (*a)->next;
	(*a)->next = tmp;
	if (stats)
	{
		stats->sa_count++;
		stats->total++;
	}
	ft_putstr("sa\n");
}

void ft_sb(t_stack** b, t_stats *stats)
{
	t_stack	*tmp;

	if (!b || !(*b)->next)
		return;
	tmp = *b;
	*b = (*b)->next;
	tmp->next = (*b)->next;
	(*b)->next = tmp;
	if (stats)
	{ 
		stats->sb_count++;
		stats->total++;
	}
	ft_putstr("sb\n");
}

void ft_ss(t_stack** a, t_stack** b, t_stats *stats)
{
	ft_sa(a, NULL);
	ft_sb(b, NULL);
	if (stats)
	{ 
		stats->ss_count++;
		stats->total++;
	}
	ft_putstr("ss\n");
}