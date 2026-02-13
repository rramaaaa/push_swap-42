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
int		ft_strlen(char *op);
int		is_empty(t_node *stack);
void	push(t_node **stack, int value);
int		pop(t_node **stack);
int		peek(t_node *stack);
void	putop(const char *op);
void	count_op(t_bench *bn, t_op op);
void	do_sa(t_node **a, t_bench *bn);
void	do_sb(t_node **b, t_bench *bn);
void	do_ss(t_node **a, t_node **b, bench *bn);
void	do_pa(t_node **a, bench *bn);
void	do_pb(t_node **b, bench *bn);
void	do_ra(t_node **a, bench *bn);
void	do_rb(t_node **b, bench *bn);
void	do_rr(t_node **a, t_node **b, bench *bn);
void	do_rra(t_node **a, bench *bn);
void	do_rrb(t_node **a, bench *bn);
void	do_rrr(t_node **a, t_node **b, bench *bn);
t_node	*node_new(int value);
void	list_free(t_node **a);
int		list_size(t_node *a);
int		is_sorted(t_node *a);
int		breaks_count(t_node *a);

#endif
