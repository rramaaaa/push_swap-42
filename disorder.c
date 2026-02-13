#include "push_swap.h"

double	compute_disorder(t_node *a)
{
	long	mistakes;
    long    total;
    t_node  *i;
    t_node  *j;
	
	mistakes = 0;
	total = 0;
	if (!a || !a->next)
		return (0.0);
    i = a->next;
    j = a;
    while (i)
    {
        if (i->value < j->value)
                mistakes++;
        total++;
        i = i->next;
        j = j->next;
    }
    if (total == 0)
        return (0.0);
    return ((double)mistaks / (double)total);
}