/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rajarada <rajarada@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 11:59:53 by rajarada          #+#    #+#             */
/*   Updated: 2026/02/09 15:00:07 by rajarada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <unistd.h>

typedef enum s_strategy
{
	SIMPLE = 0,
	MEDIUM,
	COMPLEX,
	ADAPTIVE
}	t_strategy;

typedef struct s_node
{
	int				value;
	int				rank;
	struct s_node	*next;
}	t_node;

typedef struct s_parse
{
	int		num;
	int		*vals;
	t_strategy	forced;
	int		bench;
}	t_parse;

typedef enum e_op
{
	OP_SA = 0,
	OP_SB,
	OP_SS,
	OP_PA,
	OP_PB,
	OP_RA,
	OP_RB,
	OP_RR,
	OP_RRA,
	OP_RRB,
	OP_RRR,
	OP_COUNT
}	t_op;

typedef struct s_bench
{
	int	enabled;
	double	disorder;
	t_strategy	strategy;
	const char	*strategy_name;
	const char	*complexity;
	long 	total_ops;
	long	count[OP_COUNT];
}	t_bench;

typedef struct s_medium_bucket
{
        t_node          **a;
        t_node          **b;
        t_bench         *bn;
        int                     lo;
        int                     hi;
        int                     bucket_size;
}       t_medium_bucket;

void	sa(t_node **a);
void	sb(t_node **b);
void	ss(t_node **a, t_node **b);
void	pa(t_node **a, t_node **b);
void	pb(t_node **a, t_node **b);
void	ra(t_node **a);
void	rb(t_node **b);
void	rr(t_node **a, t_node **b);
void	rra(t_node **a);
void	rrb(t_node **b);
void	rrr(t_node **a, t_node **b);
int		is_full(void);
size_t		ft_strlen(char *op);
int		is_empty(t_node *stack);
void	push(t_node **stack, int value);
int		pop(t_node **stack);
int		peek(t_node *stack);
void	putop(const char *op);
void	count_op(t_bench *bn, t_op op);
void	do_sa(t_node **a, t_bench *bn);
void	do_sb(t_node **b, t_bench *bn);
void	do_ss(t_node **a, t_node **b, t_bench *bn);
void	do_pa(t_node **a, t_node **b, t_bench *bn);
void	do_pb(t_node **b, t_node **a,t_bench *bn);
void	do_ra(t_node **a, t_bench *bn);
void	do_rb(t_node **b, t_bench *bn);
void	do_rr(t_node **a, t_node **b, t_bench *bn);
void	do_rra(t_node **a, t_bench *bn);
void	do_rrb(t_node **a, t_bench *bn);
void	do_rrr(t_node **a, t_node **b, t_bench *bn);
t_node	*node_new(int value);
void	list_free(t_node **a);
int		list_size(t_node *a);
int		is_sorted(t_node *a);
int		breaks_count(t_node *a);
int	strequal(const char *a, const char *b);
int	is_flag(const char *str);
int	set_flag(const char *s, t_strategy *strategy, int *bench);
int	parse_int_strict(const char *s, int *out);
int	parse_args(int argc, char **argv, t_parse *p);
void 	ranks(t_node *a, int size);
void	simple_strategy(t_node **a,t_node **b, t_bench *bn);
void	bench_print(t_bench *bn);
void	medium_strategy(t_node **a, t_node **b, t_bench *bn);
int	int_sqrt(int n);
int	in_range(int r, int lo, int hi);
int	find_pos_in_range(t_node *a, int lo, int hi);
void	pull_back_max(t_node **a, t_node **b, t_bench *bn);
int	pos_of_rank(t_node *a, int rank);
int pos_of_min_rank(t_node *a);
void	rotate_to_pos_a(t_node **a, int pos, t_bench *bn);
void	rotate_min_to_top(t_node **a, t_bench *bn);
double	compute_disorder(t_node *a);
void	complex_strategy(t_node **a, t_node **b, t_bench *bn);
void	quick_sort(int *arr, int left, int right);
int	sorted_copy(const int *arr, int size, int **out);
int	has_dup(const int *arr, int size);
void		bench_initial(t_bench *bn, int enabled);
void	bench_set(t_bench *bn, t_strategy st, const char *sname, const char *compx);
void putstr_fd(const char *s, int fd);
void		putnbr_fd(long number, int fd);
void	adaptive(t_node **a, t_node **b, t_bench *bn);
void int handle_error(void);
int	main(int argc, char **argv);
#endif