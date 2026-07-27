/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noah-baz <noah-baz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 14:41:02 by noah-baz          #+#    #+#             */
/*   Updated: 2026/07/27 23:11:34 by noah-baz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//----------[!!!!!!!!!  FUNCTIONS NOT TESTED  !!!!!!]---------------------//

//----------[checks the disorder of the stack]----------------------------//
//----------[EDITED: while was confusing, made a cleaner one]-------------//
//----------[EDITED: Deleted the function call in return: added size]-----//
//----------[EDITED: size used to check 1 number case]--------------------//
//----------[EDITED: ft_disorder returns a float, needed casting]---------//

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


e_diff resolve_strategy(float disorder)
{
    if (disorder < 0.2)
        return (SIMPLE);
    else if (disorder < 0.5)
        return (MEDIUM);
    else
        return (COMPLEX);
}

//----------[Prints the benchmark]--------------------//
//----------[e_diff used for adaptive difficulty]-----//
//----------[adaptive: we check disorder level 1st]---//
//----------[adaptive: we set the diff qualified]-----//
//----------[prints all the modes and its values]-----//
//----------[returns nothing. only prints]------------//

void print_bench(t_ops *bench, t_flags *flags, float disorder)
{
    const char *names = {"Adaptive", "Simple", "Medium", "Complex"};
    const char *complex = {"__", "O(n2)", "O(n√n)", "O(n log n)"};
    e_diff      used;

    if (flags->difficulty == ADAPTIVE)
        used = resolve_strategy(disorder);
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