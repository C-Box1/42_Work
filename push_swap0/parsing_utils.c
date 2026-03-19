#include "push_swap.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	const unsigned char	*s1_str;
	const unsigned char	*s2_str;
	size_t				i;

	s1_str = (const unsigned char *)s1;
	s2_str = (const unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (s1_str[i] != s2_str[i])
			return ((int)(s1_str[i] - s2_str[i]));
		i++;
	}
	return (0);
}

int ft_atoi(const char *str)
{
	long nb;
	int flag;
	int i;

	nb = 0;
	flag = 1;
	i = 0;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		flag *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = (nb * 10) + (str[i] - '0');
		i++;
	}
	return ((int)(nb * flag));
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if ((unsigned char) s[i] == (unsigned char)c)
			return ((char *)(&s[i]));
		i++;
	}
	if (c == 0)
		return ((char *)(&s[i]));
	return (NULL);
}

int is_duplicate(t_stack *stack, int val)
{
	t_stack	*cur;

	cur = stack;
	while (cur)
	{
		if (cur->val == val)
			return (1);
		cur = cur->next;
	}
	return (0);
}
