/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rajarada <rajarada@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 12:44:13 by rajarada          #+#    #+#             */
/*   Updated: 2026/02/02 13:34:35 by rajarada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*node_new(int value)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = value;
	node->rank = 0;
	node->next = NULL;
	return (node);
}

void	list_free(t_node **a)
{
	if (!*a)
		return ;
	while (*a)
		pop(a);
	*a = NULL;
}

int	list_size(t_node *a)
{
	t_node	*tmp;
	int		i;

	i = 0;
	tmp = a;
	if (!a)
		return (0);
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

int	is_sorted(t_node *a)
{
	t_node	*tmp;

	tmp = a;
	if (!a || !a->next)
		return (1);
	while (tmp)
	{
		if (tmp->value > tmp->next->value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	breaks_count(t_node *a)
{
	t_node	*tmp;
	int		breaks;

	breaks = 0;
	tmp = a;
	while (tmp && tmp->next)
	{
		if (tmp->value > tmp->next->value)
			breaks++;
		tmp = tmp->next;
	}
	return (breaks);
}
