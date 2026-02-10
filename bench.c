#include "push_swap.h"

void		bench_initial(t_bench *bn, int enabled)
{
	int	i;

	bn->enabled = enabled;
	bn->disorder = 0.0;
	bn->strategy = STR_ADAPTIVE;
	bn->strategy_name = "Adaprive";
	bn->complexity = "";
	bn->total_ops = 0;
	while (i < OP_COUNT)
	{
		bn->count[i] = 0;
		i++;
	}
}

void	bench_set(t_bench *bn, t_strategy st, const char *sname, const char *compx)
{
	bn->startegy = st;
	bn->strategy_name = sname;
	bn->complexity = compx;
}

static	void putstr_fd(const char *s, int fd)
{
	write(fd, s, ft_strlen(s));
}

static void		putnbr_fd(long number, int fd)
{
	char    buf[42];
	int i;
	long	n;
	
	n = number;
	if(n == 0)
    {
		write(fd, "0", 1);
		return ;
    }
	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	while (n)
    {
        buf[i++] = (n % 10) + '0';
        n = n /10;
    }
    while (i--)
        write(fd, &buf[i], 1);
}

void	bench_print(t_bench *bn)
{
	
}