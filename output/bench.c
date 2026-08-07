/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaz-sil <nbaz-sil@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 14:41:02 by noah-baz          #+#    #+#             */
/*   Updated: 2026/08/07 09:30:03 by nbaz-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//----------[!!!!!!!!!  FUNCTIONS NOT TESTED  !!!!!!]---------------------//

//----------[checks the disorder of the stack]----------------------------//
//----------[EDITED: while was confusing, made a cleaner one]-------------//
//----------[EDITED: Deleted the function call in return: added size]-----//
//----------[EDITED: size used to check 1 number case]--------------------//
//----------[EDITED: ft_disorder returns a float, needed casting]---------//

#include "../push_swap.h"

float ft_disorder(t_node *stack)
{
    t_node  *temp;
    int     count;
    int     size;

    size = ft_lstsize(stack);
    if (size <= 1)
        return (0.0f);
    temp = stack;
    count = 0;
    while (temp && temp->next)
    {
        if (temp->content > temp->next->content)
            count++;
        temp = temp->next;
    }
    return ((float)count / (float)size);
}

//----------[defines difficulty based on disorder level]--------------------//


e_diff ft_resolve_strategy(float disorder)
{
    if (disorder < 0.2)
        return (DIFF_SIMPLE);
    else if (disorder < 0.5)
        return (DIFF_MEDIUM);
    else
        return (DIFF_COMPLEX);
}

//----------[Prints the benchmark]--------------------//
//----------[e_diff used for adaptive difficulty]-----//
//----------[adaptive: we check disorder level 1st]---//
//----------[adaptive: we set the diff qualified]-----//
//----------[prints all the modes and its values]-----//
//----------[returns nothing. only prints]------------//

void ft_print_bench(t_ops *bench, t_flags *flags, float disorder)
{
    const char *names[4] = {"Adaptive", "Simple", "Medium", "Complex"};
    const char *complex[4] = {"__", "O(n2)", "O(n√n)", "O(n log n)"};
    e_diff      used;

    if (flags->has_diff == false || flags->difficulty == DIFF_ADAPTIVE)
        used = ft_resolve_strategy(disorder);
    else
        used = flags->difficulty;
    ft_printf(2, "[bench] disorder: %.2f%%\n", disorder * 100);
    ft_printf(2, "[bench] strategy: %s / %s\n",
             names[flags->difficulty], complex[used]);
    ft_printf(2, "[bench] total_ops: %d\n", bench->total_ops);
    ft_printf(2, "[bench] sa: %d sb: %d ss: %d pa: %d pb: %d\n",
             bench->sa, bench->sb, bench->ss, bench->pa, bench->pb);
    ft_printf(2, "[bench] ra: %d rb: %d rr: %d rra: %d rrb: %d rrr: %d\n",
             bench->ra, bench->rb, bench->rr, bench->rra, bench->rrb, bench->rrr);
}

int	ft_operations_output(t_ops *bench)
{
	int	smallest_op;

	smallest_op = bench->total_ops;
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

/* void	ft_output(t_node *stack, t_ops *bench, t_flags *flags)
{
	const char *ops[11] = {"sa", "sb", "ss", "pa", "pb", "ra", "rb", "rr", "rra", "rrb", "rrr"};
	
	if (flags->has_bench == true)
	{
		float	disorder;
		disorder = ft_disorder(stack);
		ft_print_bench(bench, flags, disorder);
		return ;
	}
	while (bench->total_ops > 0)
	{
		
	}
} */