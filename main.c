#include "push_swap.h"

static int build_list(t_node **head, t_node **tail,t_node *node)
{
    if (!node)
	{
		list_free(&head);
		return (0);
	}
	if (!head)
	{
		*head = node;
		*tail = node;
	}
	else
	{
		(*tail)->next = node;
		*tail = node;
	}
    return(1);
}

static void	build_list_from_vals(t_node **a, int *vals, int size)
{
	int		i;
	t_node	*head;
	t_node	*tail;
	t_node	*node;

	head = NULL;
	tail = NULL;
	i = 0;
	while (i < size)
	{
		node = node_new(vals[i]);
        if (!build_list(&head, &tail, node))
            return ;
		i++;
	}
	*a = head;
}

static void	run_forced(t_parse *p, t_node **a,
			t_node **b, t_bench *bn)
{
	if (p->forced == SIMPLE)
	{
		bench_set(bn, SIMPLE, "Simple", "O(n^2)");
		strategy_simple(a, b, bn);
	}
	else if (p->forced == MEDIUM)
	{
		bench_set(bn, MEDIUM, "Medium", "O(n√n)");
		strategy_medium(a, b, bn);
	}
	else if (p->forced == COMPLEX)
	{
		bench_set(bn, COMPLEX, "Complex", "O(n log n)");
		strategy_complex(a, b, bn);
	}
	else
		strategy_adaptive(a, b, bn);
}

static int handle_error(void)
{
		write(2, "Error\n", 6);
		return (1);
}

int	main(int argc, char **argv)
{
	t_node		*a;
	t_node		*b;
	t_bench		bn;
	t_parse		p;

	if (argc <= 1)
		return (0);
	if (!parse_args(argc, argv, &p))
        return (handle_error());
	if (p.num == 0)
		return (0);
	a = NULL; b = NULL;
	build_list_from_vals(&a, p.vals, p.num);
	free(p.vals);
	if (!a)
         return (handle_error());
	assign_ranks(a, p.num);
	bench_init(&bn, p.bench);
	bn.disorder = compute_disorder(a);
	if (!is_sorted(a))
		run_forced(&p, &a, &b, &bn);
	if (bn.enabled)
		bench_print(&bn);
	list_free(&a); list_free(&b);
	return (0);
}