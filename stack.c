/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rajarada <rajarada@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 12:41:27 by rajarada          #+#    #+#             */
/*   Updated: 2026/01/11 11:57:27 by rajarada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_full(void)
{
	void	*tmp;

	tmp = malloc(sizeof(t_node));
	if (!tmp)
		return (1);
	free(tmp);
	return (0);
}

int	is_empty(t_node *stack)
{
	return (stack == NULL);
}

void	push(t_node **stack, int value)
{
	t_node	*new_node;

	if (is_full(stack))
	{
		write(1, "OVERFLOW\n", 9);
		return ;
	}
	else
	{
		new_node = malloc(sizeof(t_node));
		if (!new_node)
			return ;
		new_node->value = value;
		new_node->next = *stack;
		*stack = new_node;
	}
}

int	pop(t_node **stack)
{
	t_node	*tmp;
	int		val;

	if (is_empty(*stack))
	{
		write(1, "UNDERFLOW\n", 10);
		return (-1);
	}
	temp = *stack;
	val = temp->value;
	*stack = temp->next;
	free(temp);
	return (val);
}

int	peek(t_node *stack)
{
	if (is_empty(stack))
	{
		write(1, "EMPTYSTACK\n", 11);
		return (-1);
	}
	return (stack->value);
}
