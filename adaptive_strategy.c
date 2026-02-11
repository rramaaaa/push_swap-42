#include"push_swap.h"

void	adaptive(t_node **a, t_node **b, t_bench *bn)
{
	double	dis;

	dis = bn->disorder;
	if (dis < 0.2)
    {
        bench_set(bn, ADAPTIVE, "Adaptive", "O(n)");
        if (is_sorted(*a))
            return ;
        if (breaks_count(*a) <= 1)
        {
            meidum_strategy(a, b, bn);
            return ;
        }
        bench_set(bn, ADAPTIVE, "Adaptive", "O(n√n)");
        medium_strategy(a, b, bn);
        return ;
	}
	if(dis < 0.5)
	{
		bench_set(bn, ADAPTIVE, "Adaptive", "O(n√n)");
		medium_strategy(a, b, bn);
		return ;
	}
    bench_set(bn, ADAPYIVE, "Adaptive", "O(n log n)");
	complex_strategy(a, b, n);
}