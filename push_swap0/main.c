#include "push_swap.h"

int main(int argc, char **argv)
{
	if (argc < 2)
		return (0);
	return (push_swap(argc, argv));
}


char *get_complexity(int mode_flag, double disorder)
{
	if (mode_flag == 1 || (mode_flag == 0 && disorder < 0.2))
		return ("O(n^2)");
	else if (mode_flag == 2 || (mode_flag == 0 && disorder < 0.5))
		return ("O(n√n)");
	return ("O(n log n)");
}
