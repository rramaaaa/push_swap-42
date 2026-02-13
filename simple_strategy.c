#include"push_swap.h"

void	simple_strategy(t_node **a,t_node **b, t_bench *bn)
{
	while (*a)
	{
		int		pos;
		
		pos = pos_of_min_rank(*a);
		rotate_to_pos_a(a, pos, bn);
		do_pb(a, b, bn);
	}
	while (*b)
	{
		do_pa(a, b, bn);
	}
}
