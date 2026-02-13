/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rajarada <rajarada@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 16:24:46 by rajarada          #+#    #+#             */
/*   Updated: 2026/02/09 15:49:05 by rajarada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	strequal(const char *a, const char *b)
{
	int	i;

	i = 0;
	while (a[i] && b[i] && a[i] == b[i])
		i++;
	if (a[i] == 0 && b[i] == 0)
		return (1);
	return (0);
}

int	is_flag(const char *str)
{
	if (strequal(str, "--simple") || strequal(str, "--medium"))
		return (1);
	if (strequal(str, "--complex"))
		return (1);
	if (strequal(str, "--adaptive") || strequal(str, "--bench"))
		return (1);
	return (0);
}

int	set_flag(const char *s, t_strategy *strategy, int *bench)
{
	if (!is_flag(s))
		return (0);
	else
	{
		if (strequal(s, "--bench"))
			*bench = 1;
		if (strequal(s, "--simple"))
			*strategy = SIMPLE;
		if (strequal(s, "--medium"))
			*strategy = MEDIUM;
		if (strequal(s, "--complex"))
			*strategy = COMPLEX;
		if (strequal(s, "--adaptive"))
			*strategy = ADAPTIVE;
		return (1);
	}
}

int	parse_int_strict(const char *s, int *out)
{
	int		sign;
	long	result;

	sign = 1;
	result = 0;
	if (!s || !*s)
		return (0);
	if (*s == '-' || *s == '+')
	{
		if (*s++ == '-')
			sign = -1;
	}
	if (!*s)
		return (0);
	while (*s)
	{
		if (*s < '0' || *s > '9')
			return (0);
		result = (result * 10) + (*s++ - '0');
		if (result * sign > INT_MAX || result * sign < INT_MIN)
			return (0);
	}
	*out = (int)(sign * result);
	return (1);
}