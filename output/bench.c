/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charlie <charlie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 14:41:02 by noah-baz          #+#    #+#             */
/*   Updated: 2026/08/12 03:48:05 by charlie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//----------[!!!!!!!!!  FUNCTIONS NOT TESTED  !!!!!!]---------------------//

//----------[checks the disorder of the stack]----------------------------//
//----------[EDITED: while was confusing, made a cleaner one]-------------//
//----------[EDITED: Deleted the function call in return: added size]-----//
//----------[EDITED: size used to check 1 number case]--------------------//
//----------[EDITED: disorder returns a float, needed casting]---------//

#include "../pushswap.h"

float disorder(t_node *stack)
{
    t_node  *node1;
	t_node  *node2;
    int     count;
    int     total_pairs;

    if (ft_lstsize(stack) <= 1)
        return (0);
    node1 = stack;
    count = 0;
	total_pairs = 0;
    while (node1)
    {
		node2 = node1->next;
		while(node1 != node2 && node2)
		{
			total_pairs++;
			if (node1->content > node2->content)
            	count++;
        	node2 = node2->next;
		}
        node1 = node1->next;
    }
    return ((float)count / (float) total_pairs);
}

//----------[defines difficulty based on disorder level]--------------------//


void ft_resolve_strategy(t_flags *flag, float disorder)
{
    if (disorder < 0.2)
        flag->difficulty = DIFF_SIMPLE;
    else if (disorder < 0.5)
        flag->difficulty = DIFF_MEDIUM;
    else
        flag->difficulty = DIFF_COMPLEX;

}

//----------[Prints the benchmark]--------------------//
//----------[t_diff used for adaptive difficulty]-----//
//----------[adaptive: we check disorder level 1st]---//
//----------[adaptive: we set the diff qualified]-----//
//----------[prints all the modes and its values]-----//
//----------[returns nothing. only prints]------------//

void output_bench(t_stack *stk_a, t_op_count *op_count, t_flags *flags)
{
    const char *names[4] = {"Adaptive", "Simple", "Medium", "Complex"};
    const char *complex[4] = {"__", "O(n2)", "O(n√n)", "O(n log n)"};
    t_diff      used;

    used = flags->difficulty;
    ft_printf(2, "[bench] disorder: %d", (int)(disorder(*stk_a) * 100));
	ft_printf(2, ".%d", ((int)(disorder(*stk_a) * 100) % 10));
	ft_printf(2, "%d\n", (((int)(disorder(*stk_a) * 100) % 10) % 10));
    ft_printf(2, "[bench] strategy: %s / %s\n",
             names[flags->difficulty], complex[used]);
    ft_printf(2, "[bench] total_ops: %d\n", op_count->total);
    ft_printf(2, "[bench] sa: %d sb: %d ss: %d pa: %d pb: %d\n",
             op_count->sa, op_count->sb, op_count->ss, op_count->pa, op_count->pb);
    ft_printf(2, "[bench] ra: %d rb: %d rr: %d rra: %d rrb: %d rrr: %d\n",
             op_count->ra, op_count->rb, op_count->rr, op_count->rra, op_count->rrb, op_count->rrr);
}

int	operations_output(t_op_count *bench)
{
	int	smallest_op;

	smallest_op = bench->total;
	if (bench->sa < bench->sb)
		smallest_op = bench->sb;
	if (bench->sa < bench->ss)
		smallest_op = bench->ss;
	if (bench->sa < bench->pa)
		smallest_op = bench->pa;
	if (bench->sa < bench->pb)
		smallest_op = bench->pb;
	if (bench->sa < bench->ra)
		smallest_op = bench->ra;
	if (bench->sa < bench->rb)
		smallest_op = bench->rb;
	if (bench->sa < bench->rr)
		smallest_op = bench->rr;
	if (bench->sa < bench->rra)
		smallest_op = bench->rra;
	if (bench->sa < bench->rrb)
		smallest_op = bench->rrb;
	if (bench->sa < bench->rrr)
		smallest_op = bench->rrr;
	return (smallest_op);
}

/* void	ft_output(t_node *stack, t_op_count *bench, t_flags *flags)
{
	const char *ops[11] = {"sa", "sb", "ss", "pa", "pb", "ra", "rb", "rr", "rra", "rrb", "rrr"};
	
	if (flags->has_bench == true)
	{
		float	disorder;
		disorder = disorder(stack);
		output_bench(bench, flags, disorder);
		return ;
	}
	while (bench->total_ops > 0)
	{
		
	}
} */