#include "push_swap.h"

void free_stack(t_stack *stack)
{
	t_stack *cur;
	while (stack)
	{
		cur = stack->next;
		free(stack);
		stack = cur;
	}
}

double compute_disorder(t_stack *a)
{
	long mistakes;
	long total;
	t_stack *i;
	t_stack *j;

	mistakes = 0;
	total = 0;
	i = a;
	while (i)
	{
		j = i->next;
		while (j)
		{
			total++;
			if (i->val > j->val)
				mistakes++;
			j = j->next;
		}
		i = i->next;
	}
	if (total == 0)
		return (0.0);
	return ((double)mistakes / (double)total);
}

t_stack *parse_and_add(char *arg, t_stack *a, t_stack *b)
{
	char    **split_args;
	int     j;

	split_args = ft_split(arg, ' ');
	if (!split_args)
		error_exit(a, b);
	j = 0;
	while (split_args[j])
	{
		if (!is_valid_integer(split_args[j]) ||	is_duplicate(a, ft_atoi(split_args[j])))
		{
			free_split(split_args);
			error_exit(a, b);
		}
		a = add_to_end(a, ft_atoi(split_args[j]));
		j++;
	}
	free_split(split_args);
	return (a);
}

void error_exit(t_stack *a, t_stack *b)
{
	free_stack(a);
	free_stack(b);
	write(2, "Error\n", 6);
	exit(1);
}

void free_split(char **arr)
{
	int i;

	i = 0;
	if (!arr)
		return;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}
