#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>

typedef struct stack
{
	int			val;
	int			index;
	struct stack   *next;
} t_stack;

typedef struct s_stats
{
	int	sa_count;
	int	sb_count;
	int	ss_count;
	int	pa_count;
	int	pb_count;
	int	ra_count;
	int	rb_count;
	int	rr_count;
	int	rra_count;
	int	rrb_count;
	int	rrr_count;
	int	total;
} t_stats;

typedef struct s_context
{
	t_stack	**a;
	t_stack	**b;
	t_stats	*stats;
	int	mode_flag;
} t_context;

/*Operation prototypes updated to accept t_stats* */
void	ft_sa(t_stack **a, t_stats *stats);
void	ft_sb(t_stack **b, t_stats *stats);
void	ft_ss(t_stack **a, t_stack **b, t_stats *stats);
void	ft_pa(t_stack **a, t_stack **b, t_stats *stats);
void	ft_pb(t_stack **b, t_stack **a, t_stats *stats);
void	ft_ra(t_stack **a, t_stats *stats);
void	ft_rb(t_stack **b, t_stats *stats);
void	ft_rr(t_stack **a, t_stack **b, t_stats *stats);
void	ft_rra(t_stack **a, t_stats *stats);
void	ft_rrb(t_stack **b, t_stats *stats);
void	ft_rrr(t_stack **a, t_stack **b, t_stats *stats);

/* Stack operations */
t_stack *new_node(int val);
t_stack *add_to_end(t_stack* head,int val);

/* Parsing utilities */
int		push_swap(int argc, char **argv);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_atoi(const char *str);
char	*ft_strchr(const char *s, int c);
int		is_valid_integer(char *s);
int		is_duplicate(t_stack *stack, int val);
void	free_stack(t_stack *stack);
double	compute_disorder(t_stack *stack);
char	**ft_split(char const *s, char c);
t_stack	*parse_and_add(char *arg, t_stack *a, t_stack *b);
void	error_exit(t_stack *a, t_stack *b);
void	free_split(char **arr);
int		get_stack_size(t_stack *stack);
void	ft_index(t_stack *a, int stack_size);
size_t	ft_strlen(const char *s);
void	ft_putnbr_fd(int n, int fd);
char	*get_complexity(int mode_flag, double disorder);


/* Output helper */
void	ft_putstr(char *str);

/* Sorting algorithms */
void	ft_run(t_context *ctx, int bench);
void	ft_algorithm(double disorder, t_context *ctx);
void	run_small_sort(t_context* ctx, int size);
void	run_simple_algorithm(t_context* ctx);
void	run_medium_algorithm(t_context* ctx);
void	run_complex_algorithm(t_context* ctx);
void	print_benchmarks(double disorder, int mode_flag, t_stats *stats);
int		find_max_index(t_stack *b);
#endif