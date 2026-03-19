#include "push_swap.h"

static int	ft_parse_sign(char *s, int *i)
{
	int	sign;

	sign = 1;
	while (s[*i] == ' ' || (s[*i] >= 9 && s[*i] <= 13))
		(*i)++;
	if (s[*i] == '+' || s[*i] == '-')
	{
		if (s[*i] == '-')
			sign = -1;
		(*i)++;
	}
	return (sign);
}

int	is_valid_integer(char *s)
{
	int		i;
	long	result;
	int		sign;

	i = 0;
	result = 0;
	sign = ft_parse_sign(s, &i);
	if (s[i] < '0' || s[i] > '9')
		return (0);
	while (s[i] >= '0' && s[i] <= '9')
	{
		result = result * 10 + (s[i] - '0');
		if ((result * sign) > 2147483647 || (result * sign) < -2147483648)
			return (0);
		i++;
	}
	if (s[i] != '\0')
		return (0);
	return (1);
}
