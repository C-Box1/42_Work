#include "push_swap.h"

t_stack *new_node(int val)
{
	t_stack *node;

	node = (t_stack *)malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->val = val;
	node->index = -1;
	node->next = NULL;
	return (node);
}

t_stack *add_to_end(t_stack* head,int val)
{
	t_stack *tmp;
	t_stack *node;

	node = new_node(val);
	if (!node)
	{
		free_stack(head);
		return (NULL);
	}
	if (!head)
		return (node);
	tmp = head;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = node;
	return (head);
}

void ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

void ft_index(t_stack *a, int stack_size)
{
	t_stack	*ptr;
	t_stack	*highest;
	long	val;

	while (--stack_size >= 0)
	{
		ptr = a;
		highest = NULL;
		val = -2147483649;
		while (ptr)
		{
			if (ptr->val > val && ptr->index == -1)
			{
				val = ptr->val;
				highest = ptr;
			}
			ptr = ptr->next;
		}
		if (highest)
			highest->index = stack_size;
	}
}