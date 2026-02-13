#include "push_swap.h"

static int	binary_search(int *sorted,int size, int v)
{
	int left;
    int	right;
    int mid;

	left = 0;
	right = size - 1;
	while (left <= right)
	{
		mid = left + (right - left) / 2;
        if (sorted[mid] == v)
            return (mid);
        if (sorted[mid] < v)
            left = mid + 1;
        else
            right = mid - 1;
	}
	return (-1);
}

void 	ranks(t_node *a, int size)
{
	int		*arr;
	int		i;
	t_node *temp;

	arr = (int *)malloc(sizeof(int) * size);
	if (!arr)
		return ;
	temp = a;
	i = 0;
	while (temp && i < size)
	{
		arr[i] = temp->value;
		i++;
		temp = temp->next;
	}
	if (size > 1)
        quick_sort(arr, 0, size - 1);
    temp = a;
    while (temp)
    {
        temp->rank = binary_search(arr, size, temp->value);
        temp = temp->next;
    }
    free(arr);
}