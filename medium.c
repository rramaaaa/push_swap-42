/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rajarad <rajarad@learner.42.tech>          #+#  +:+       +#+        */
/*                                               +#+  +:+       +#+           */
/*   Created: 2026/02/13 18:11:36 by rajarad           #+#    #+#             */
/*   Updated: 2026/02/13 18:11:36 by rajarad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

typedef struct s_bucket_ctx
{
	t_node		**a;
	t_node		**b;
	t_bench		*bn;
	int			lo;
	int			hi;
	int			bucket_size;
}	t_bucket_ctx;

static void	push_bucket(t_bucket_ctx *c)
{
	int	pos;
	int	pushed;

	pushed = 0;
	while (*(c->a) && pushed < c->bucket_size)
	{
		pos = find_pos_in_range(*(c->a), c->lo, c->hi);
		if (pos < 0)
			return ;
		rotate_to_pos_a(c->a, pos, c->bn);
		do_pb(c->a, c->b, c->bn);
		if (*(c->b) && (*(c->b))->next
			&& (*(c->b))->rank < (c->lo + c->hi) / 2)
			do_rb(c->b, c->bn);
		pushed++;
	}
}

void	strategy_medium(t_node **a, t_node **b, t_bench *bn)
{
	int			size;
	int			root;
	int			bucket_size;
	int			i;
	t_bucket_ctx	c;

	size = list_size(*a);
	root = int_sqrt(size);
	if (root <= 0)
		return ;
	bucket_size = (size + root - 1) / root;
	c.a = a;
	c.b = b;
	c.bn = bn;
	c.bucket_size = bucket_size;
	i = 0;
	while (i < root)
	{
		c.lo = i * bucket_size;
		c.hi = c.lo + bucket_size;
		push_bucket(&c);
		i++;
	}
	pull_back_max(a, b, bn);
	rotate_min_to_top(a, bn);
}
