#include"push_swap.h"

static int  max_bits(int max_rank)
{
    int bit;

    bit = 0;
    while((max_rank >> bits) != 0)
        bits++;
    return (bits);
}

void	complex_strategy(t_node **a, t_node **b, t_bench *bn)
{
	int	size;
	int	bits;
	int	pass;
	int	i;
	int	rank;

	size = list_size(*a);
	bits = max_bits(size - 1);
	pass = 0;
	while (pass < bits)
	{
		i = 0;
		while (i < size)
		{
			rank = (*a)->rank;
			if (((rank >> pass) & 1) == 0)
				do_pb(a, b, bn);
			else
				do_ra(a, bn);
			i++;
		}
		while (*b)
			do_pa(a, b, bn);
		pass++;
	}
}