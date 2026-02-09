/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_ops_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rajarada <rajarada@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 15:17:05 by rajarada          #+#    #+#             */
/*   Updated: 2026/02/02 15:26:14 by rajarada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_ss(t_node **a, t_node **b, bench *bn)
{
	ss(a, b);
	put_op("ss");
	count_op(bn, OP_SS);
}

void	do_pa(t_node **a, bench *bn)
{
	pa(a);
	put_op("pa");
	count_op(bn, OP_PA);
}

void	do_pb(t_node **b, bench *bn)
{
	pb(b);
	put_op("pb");
	count_op(bn, OP_PB);
}

void	do_ra(t_node **a, bench *bn)
{
	ra(a);
	put_op("ra");
	count_op(bn, OP_RA);
}

void	do_rb(t_node **b, bench *bn)
{
	rb(b);
	put_op("rb");
	count_op(bn, OP_RB);
}
