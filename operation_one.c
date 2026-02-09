/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_one.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rajarada <rajarada@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 10:31:12 by rajarada          #+#    #+#             */
/*   Updated: 2026/01/11 11:21:56 by rajarada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_node **a)
{
	t_node	*is_last;
	t_node	*first;

	if (!a || !*a || !(*a)->next)
		return ;
	is_last = *a;
	first = *a;
	while (is_last->next)
		is_last = is_last->next;
	is_last->next = *a;
	*a = (*a)->next;
	first->next = NULL;
}

void	rb(t_node **b)
{
	t_node	*is_last;
	t_node	*first;

	if (!b || !*b || !(*b)->next)
		return ;
	is_last = *b;
	first = *b;
	while (is_last->next)
		is_last = is_last->next;
	is_last->next = *b;
	*b = (*b)->next;
	first->next = NULL;
}

void	rr(t_node **a, t_node **b)
{
	ra(a);
	rb(b);
}

void	rra(t_node **a)
{
	t_node	*is_last;
	t_node	*back;

	if (!a || !*a || !(*a)->next)
		return ;
	is_last = *a;
	back = NULL;
	while (is_last->next)
	{
		if (back == NULL)
			back = *a;
		else
			back = back->next;
		is_last = is_last->next;
	}
	is_last->next = *a;
	*a = is_last;
	back->next = NULL;
}

void	rrb(t_node **b)
{
	t_node	*is_last;
	t_node	*back;

	if (!b || !*b || !(*b)->next)
		return ;
	is_last = *b;
	back = NULL;
	while (is_last->next)
	{
		if (back == NULL)
			back = *b;
		else
			back = back->next;
		is_last = is_last->next;
	}
	is_last->next = *b;
	*b = is_last;
	back->next = NULL;
}
