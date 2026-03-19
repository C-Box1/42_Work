#include "push_swap.h"


static void print_disorder(double disorder)
{
	int	int_part;
	int	frac_part;

	int_part = (int)(disorder * 100);
	frac_part = (int)(disorder * 10000.0) % 100;
	write(2, "[bench] disorder:  ", 19);
	ft_putnbr_fd(int_part, 2);
	write(2, ".", 1);
	if (frac_part < 10)
		write(2, "0", 1);
	ft_putnbr_fd(frac_part, 2);
	write(2, "%\n", 2);
}

static void helper_strategy_total(char *strategy, char *complexity, int total)
{
	write(2, "[bench] strategy:  ", 19);
	write(2, strategy, ft_strlen(strategy));
	write(2, " / ", 3);
	write(2, complexity, ft_strlen(complexity));
	write(2, "\n", 1);
	write(2, "[bench] total_ops: ", 19);
	ft_putnbr_fd(total, 2);
	write(2, "\n", 1);
}

static void helper_op1(t_stats *stats)
{
	write(2, "[bench] sa: ", 12);
	ft_putnbr_fd(stats->sa_count, 2);
	write(2, "  sb: ", 6);
	ft_putnbr_fd(stats->sb_count, 2);
	write(2, "  ss: ", 6);
	ft_putnbr_fd(stats->ss_count, 2);
	write(2, "  pa: ", 6);
	ft_putnbr_fd(stats->pa_count, 2);
	write(2, "  pb: ", 6);
	ft_putnbr_fd(stats->pb_count, 2);
	write(2, "\n", 1);
}

static void helper_op2(t_stats *stats)
{
	write(2, "[bench] ra: ", 12);
	ft_putnbr_fd(stats->ra_count, 2);
	write(2, "  rb: ", 6);
	ft_putnbr_fd(stats->rb_count, 2);
	write(2, "  rr: ", 6);
	ft_putnbr_fd(stats->rr_count, 2);
	write(2, "  rra: ", 7);
	ft_putnbr_fd(stats->rra_count, 2);
	write(2, "  rrb: ", 7);
	ft_putnbr_fd(stats->rrb_count, 2);
	write(2, "  rrr: ", 7);
	ft_putnbr_fd(stats->rrr_count, 2);
	write(2, "\n", 1);
}

void print_benchmarks(double disorder, int mode_flag, t_stats *stats)
{
	char	*strategy;
	char	*complexity;

	if (mode_flag == 0)
		strategy = "adaptive";
	else if (mode_flag == 1)
		strategy = "simple";
	else if (mode_flag == 2)
		strategy = "medium";
	else
		strategy = "complex";
	complexity = get_complexity(mode_flag, disorder);
	print_disorder(disorder);
	helper_strategy_total(strategy, complexity, stats->total);
	helper_op1(stats);
	helper_op2(stats);
}
