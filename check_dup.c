/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_dup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rajarada <rajarada@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 15:45:11 by rajarada          #+#    #+#             */
/*   Updated: 2026/02/09 14:12:59 by rajarada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static int	partition(int *arr, int left, int right)
{
	int	pivot;
	int	i;
	int	j;

	pivot = arr[(left + right) / 2];
	i = left;
	j = right;
	while (i <= j)
	{
		while (arr[i] < pivot)
			i++;
		while (arr[j] > pivot)
			j--;
		if (i <= j)
		{
			swap(&arr[i], &arr[j]);
			i++;
			j--;
		}
	}
	return (i);
}

void	quick_sort(int *arr, int left, int right)
{
	int	index;

	if (left >= right)
		return ;
	index = partition(arr, left, right);
	if (left < index - 1)
		quick_sort(arr, left, index - 1);
	if (index < right)
		quick_sort(arr, index, right);
}

int	sorted_copy(const int *arr, int size, int **out)
{
	int	*sorted;
	int	i;

	if (!out)
		return (0);
	*out = NULL;
	i = 0;
	if (!arr || size <= 0)
		return (1);
	sorted = malloc(sizeof(int) * size);
	if (!sorted)
		return (0);
	while (size > i)
	{
		sorted[i] = arr[i];
		i++;
	}
	quick_sort(sorted, 0, size - 1);
	*out = sorted;
	return (1);
}

int	has_dup(const int *arr, int size)
{
	int	*sorted;
	int	is_copy;

	if (!arr || size <= 1)
		return (0);
	sorted = NULL;
	is_copy = sorted_copy(arr, size, &sorted);
	if (is_copy == 0 || sorted == NULL)
		return (0);
	while (size >= 2)
	{
		if (sorted[size - 1] == sorted[size - 2])
		{
			free(sorted);
			return (1);
		}
		size--;
	}
	free(sorted);
	return (0);
}
