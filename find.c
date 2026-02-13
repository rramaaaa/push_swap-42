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
	pos = 0;
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
	int	size;

	size = list_size(*a);
	if(size <= 1 || pos <= 0)
		return ;
	if (pos <= size / 2)
		while (pos--)
			do_ra(a, bn);
	else
	{
		pos = size - pos;
		while (pos--)		
			do_rra(a,bn);
	}
	
}

void	rotate_min_to_top(t_node **a, t_bench *bn)
{
	int pos;	
    
    pos = pos_of_min_rank(*a);
	rotate_to_pos_a(a, pos, bn);
}