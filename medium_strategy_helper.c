/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_startegy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rajarada <rajarada@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 09:56:32 by rajarada          #+#    #+#             */
/*   Updated: 2026/02/02 12:43:54 by rajarada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	int_sqrt(int n)
{
	int	x;
	
	x = 1;
	if (n <= 0)
		return (0);
	while ((x + 1) * (x + 1) <= n)
		x++;
	return (x);
}

int	in_range(int r, int lo, int hi)
{
	if (lo <= r && r < hi)
		return (1);
	return (0);
}

int	find_pos_in_range(t_node *a, int lo, int hi)
{
	int	pos;
	
	pos = 0;
	while (a) 
	{
		if (in_range(a->rank, lo, hi))
			return (pos);
		pos++;
		a = a->next;
	}
	return (-1);
}

void	pull_back_max(t_node **a, t_node **b, t_bench *bn)
{
	while (*b)
	{
		int	size;
		int	target;
		int	pos;
		
		size = list_size(*b);
		target = size - 1;
		pos = pos_of_rank(*b, target);
		if (pos <= size / 2)
		{
			while (pos--)
				do_rb(b, bn);
		}
		else
		{
			pos = size - pos;
			while (pos--)
				do_rrb(b, bn);
		}
		do_pa(a, b, bn);
	}
}