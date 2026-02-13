#include"push_swap.h"

void    print_ops(t_bench *bn)
{
    putstr_fd("[bench] sa: ", 2);
	putnbr_fd(bn->count[OP_SA], 2);
	putstr_fd(" sb: ", 2);
	putnbr_fd(bn->count[OP_SB], 2);
	putstr_fd(" ss: ", 2);
	putnbr_fd(bn->count[OP_SS], 2);
	putstr_fd(" pa: ", 2);
	putnbr_fd(bn->count[OP_PA], 2);
	putstr_fd(" pb: ", 2);
	putnbr_fd(bn->count[OP_PB], 2);
    putstr_fd("\n", 2);
	putstr_fd("[bench] ra: ", 2);
	putnbr_fd(bn->count[OP_RA], 2);
	putstr_fd(" rb: ", 2);
	putnbr_fd(bn->count[OP_RB], 2);
	putstr_fd(" rr: ", 2);
	putnbr_fd(bn->count[OP_RR], 2);
	putstr_fd(" rra: ", 2);
	putnbr_fd(bn->count[OP_RRA], 2);
	putstr_fd(" rrb :", 2);
	putnbr_fd(bn->count[OP_RRB], 2);
	putstr_fd(" rrr: ", 2);
	putnbr_fd(bn->count[OP_RRR], 2);
}

void	bench_print(t_bench *bn)
{
	long perc;
	
	perc = (long)(bn->disorder*10000.0 + 0.5);
	putstr_fd("[bench] disorder: ", 2);
	putnbr_fd(perc / 100, 2);
	write(2, ".", 1);
	if (perc % 100 < 10)
		write(2, "0", 1);
	putnbr_fd(perc % 100 ,2);
	putstr_fd("%\n",2);
	putstr_fd("[bench] strategy: ", 2);
	putstr_fd(bn->strategy_name, 2);
	putstr_fd(" / ", 2);
	putstr_fd(bn->complexity, 2);
	putstr_fd("\n", 2);
	putstr_fd("[bench] total_ops: ", 2);
	putnbr_fd(bn->total_ops, 2);
	putstr_fd("\n", 2);
    print_ops(bn);
    putstr_fd("\n", 2);
}