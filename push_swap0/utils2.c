#include "push_swap.h"

int get_stack_size(t_stack *stack)
{
    int size;
    t_stack *current;

    size = 0;
    current = stack;
    while (current)
    {
        size++;
        current = current->next;
    }
    return (size);
}

size_t	ft_strlen(const char *s)
{
	size_t i;
	
	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_putnbr_fd(int n, int fd)
{
	long nb;
	char c;

	nb = n;
	if (nb < 0)
	{
		write(fd, "-", 1);
		nb = -nb;
	}
	if (nb >= 10)
		ft_putnbr_fd(nb / 10, fd);
	c = (nb % 10) + '0';
	write(fd, &c, 1);
}