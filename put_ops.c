/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_ops.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rajarada <rajarada@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 13:42:56 by rajarada          #+#    #+#             */
/*   Updated: 2026/02/04 12:13:47 by rajarada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(char *op)
{
	size_t	i;

	i = 0;
	while (op[i])
		i++;
	return (i);
}

void	put_op(const char *op)
{
	write(1, op, ft_strlen(op));
	write(1, "\n", 1);
}

void	count_op(t_bench *bn, t_op op)
{
	if (!bn || !bn->enabled)
		return ;
	bn->count[op]++;
	bn->total_ops++;
}

void	do_sa(t_node **a, t_bench *bn)
{
	sa(a);
	put_op("sa");
	count_op(bn, OP_SA);
}

void	do_sb(t_node **b, t_bench *bn)
{
	sb(b);
	put_op("sb");
	count_op(bn, OP_SB);
}
