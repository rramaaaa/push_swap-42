#include "push_swap.h"

int pos_of_min_rank(t_node *a)
{
	int	pos;
	int	best_pos;
    int best;
    t_node  *temp;

    pos = 0;
    best_pos = 0;
    best = INT_MAX;
	temp = a;
    while (temp)
	{
		if (temp->rank < best)
        {
            best = a->rank;
            best_pos = pos;
        }
        pos++;
        temp = temp->next;
	}
	return (best_pos);
}

int	pos_of_rank(t_node *a, int rank)
{
	int	pos;
	t_node *temp;

	temp = a;
	while (temp)
	{
		if (temp->rank == rank)
			return (pos);
		pos++;
		temp = temp->next;
	}
	return (-1);
}

void	rotate_to_pos_a(t_node **a, int pos, t_bench *bn)
{
	
}