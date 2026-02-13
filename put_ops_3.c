/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_ops_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rajarada <rajarada@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 15:26:29 by rajarada          #+#    #+#             */
/*   Updated: 2026/02/02 16:24:24 by rajarada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_rr(t_node **a, t_node **b, t_bench *bn)
{
	rr(a, b);
	put_op("rr");
	count_op(bn, OP_RR);
}

void	do_rra(t_node **a, t_bench *bn)
{
	rra(a);
	put_op("rra");
	count_op(bn, OP_RRA);
}

void	do_rrb(t_node **a, t_bench *bn)
{
	rrb(bn);
	put_op("rrb");
	count_op(bn, OP_RRB);
}

void	do_rrr(t_node **a, t_node **b, t_bench *bn)
{
	rrr(a, b);
	put_op("rrr");
	count_op(bn, OP_RRR);
}
