#include "push_swap.h"

void initial_vals(t_parse *p)
{
	p->num = 0;
	p->vals = NULL;
	p->bench = 0;
	p->forced = ADAPTIVE;
}

int parse_helper(int argc, char **argv, t_parse *p, int i)
{
    int v;

    v = 0;
    while (i < argc)
	{
		if (set_flag(argv[i], &p->forced, &p->bench));
		else if (parse_int_strict(argv[i], &v))
			p->vals[p->num++] = v;
		else 
		{
			free(p->vals);
			p->vals = NULL;
			p->num = 0;
			return (0);
		}
        i++;
	}
	if (has_dup(p->vals, p->num))
	{
		free(p->vals);
		p->vals = NULL;
		p->num = 0;
		return (0);
	}
    return (1);
}

int	parse_args(int argc, char **argv, t_parse *p)
{
	int	i;
	int	n;
    int res;

	i = 1;
	n = 0;
	if (!p)
		return (0);
    initial_vals(p);
	while (i++ < argc)
	{
		if (!is_flag(argv[i]))
			n++;
	}
	if (n == 0)
		return (1);
	p->vals = malloc(sizeof(int) * n);
	if (!p->vals)
		return (0);
    i = 1;
    res = parse_helper(argc, argv, p, i);
    if (!res)
        return (0);
	return (1);
}