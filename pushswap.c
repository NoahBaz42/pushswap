/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charlie <charlie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 08:27:51 by bpassos-          #+#    #+#             */
/*   Updated: 2026/08/09 08:07:04 by charlie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include "C_algorithm/libft_pushswap/libft.h"
#include <stddef.h>

void	diff_selection(t_node *stk_a, t_node *stk_b, t_flags *flags)
{
	size_t	stack_size;

	stack_size = ft_lstsize(stk_a);
	if (stack_size == 3)
		return (stack_is_3(&stk_a));
	if (stack_size == 5)
		return (stack_is_5(&stk_a));
	if (flags->has_diff == false || flags->difficulty == DIFF_ADAPTIVE)
		ft_resolve_strategy(flags, ft_disorder(stk_a));
	if (flags->difficulty == DIFF_SIMPLE)
		return (ft_simple(&stk_a, stk_b));
	else if (flags->difficulty == DIFF_MEDIUM)
		return (chunk_sort(&stk_a, &stk_b));
	else
	 	return (radix_sort(&stk_a, &stk_b));		
}

void	pushswap(char **argv)
{
	t_node		*stk_b;
	t_flags		*flags;
    t_op_count	*op_count;
	t_node		*stk_a;

	stk_a = NULL;
	stk_b = NULL;
	flags = NULL;
	op_count = NULL;
	stk_a = parsing(argv);
	index_stack(stk_a);
	diff_selection(stk_a, stk_b, flags);
	if (flags->has_bench == true)
		output_bench(op_count, flags);
	ft_free_stack(&stk_a);
	ft_free_stack(&stk_b);

}
