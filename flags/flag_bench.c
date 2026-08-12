/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_bench.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noah-baz <noah-baz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 08:52:33 by username         ##+#    #+#             */
/*   Updated: 2026/08/12 23:07:02 by noah-baz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

//------[Checks for the flag (--bench) on the 1st and 2nd args]-----------//
//------[gives error if there´s more then 1 bench flag]-------------------//
//------------(needs an error dealing revision)---------------------------//

void	flag_bench(t_flags *flags, char **argv)
{
	if (argv[1] && !ft_strcmp(argv[1], "--bench"))
		flags->has_bench = true;
	if (argv[2] && !ft_strcmp(argv[2], "--bench"))
	{
		if (flags->has_bench)
			give_error();
		flags->has_bench = true;
	}
}

//--------[returns true if arg is (--bench), false otherwise]-------------//

bool	is_bench_flags(char *flag)
{
	if (!ft_strcmp(flag, "--bench"))
		return (true);
	return (false);
}

//----------[checks the disorder of the stack]----------------------------//

float	disorder(t_node *stack)
{
	t_node	*node1;
	t_node	*node2;
	int		count;
	int		total_pairs;

	if (ft_lstsize(stack) <= 1)
		return (0);
	node1 = stack;
	count = 0;
	total_pairs = 0;
	while (node1)
	{
		node2 = node1->next;
		while (node1 != node2 && node2)
		{
			total_pairs++;
			if (node1->content > node2->content)
				count++;
			node2 = node2->next;
		}
		node1 = node1->next;
	}
	return ((float) count / (float) total_pairs);
}

//----------[defines difficulty based on disorder level]--------------------//

void	ft_resolve_strategy(t_flags *flag, float disorder)
{
	if (disorder < 0.2)
		flag->difficulty = DIFF_SIMPLE;
	else if (disorder < 0.5)
		flag->difficulty = DIFF_MEDIUM;
	else
		flag->difficulty = DIFF_COMPLEX;
}

//----------[Prints the benchmark]--------------------//

void	output_bench(t_stack *stk_a, t_op_count *op_count, t_flags *flags)
{
	const char	*names[4] = {"Adaptive", "Simple", "Medium", "Complex"};
	const char	*complex[4] = {"__", "O(n2)", "O(n√n)", "O(n log n)"};

	ft_printf(2, "[bench] disorder: %d", (int)(disorder(*stk_a) * 100));
	ft_printf(2, ".%d", ((int)(disorder(*stk_a) * 100) % 10));
	ft_printf(2, "%d\n", (((int)(disorder(*stk_a) * 100) % 10) % 10));
	ft_printf(2, "[bench] strategy: %s / %s\n", names[flags->difficulty],
		complex[flags->difficulty]);
	ft_printf(2, "[bench] total_ops: %d\n", op_count->total);
	ft_printf(2, "[bench] sa: %d sb: %d ss: %d pa: %d pb: %d\n", op_count->sa,
		op_count->sb, op_count->ss, op_count->pa, op_count->pb);
	ft_printf(2, "[bench] ra: %d rb: %d rr: %d rra: %d rrb: %d rrr: %d\n",
		op_count->ra, op_count->rb, op_count->rr, op_count->rra, op_count->rrb,
		op_count->rrr);
}
