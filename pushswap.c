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

static void	diff_selection(t_stack *stk_a, t_stack *stk_b, t_flags *flags, t_op_count *op_count)
{
	size_t	stack_size;

	stack_size = ft_lstsize(*stk_a);
	if (stack_size == 3)
		return (stack_is_3(stk_a, op_count));
	if (stack_size == 5)
		return (stack_is_5(stk_a, stk_b, op_count));
	if (flags->has_diff == false || flags->difficulty == DIFF_ADAPTIVE)
		ft_resolve_strategy(flags, ft_disorder(*stk_a));
	if (flags->difficulty == DIFF_SIMPLE)
		return (ft_simple(stk_a, stk_b, op_count));
	else if (flags->difficulty == DIFF_MEDIUM)
		return (chunk_sort(stk_a, stk_b, op_count));
	else
	 	return (radix_sort(stk_a, stk_b, op_count));	
}

static void	free_all(t_stack *stk_a, t_stack *stk_b, t_flags *flags, t_op_count *op_count)
{
	ft_free_stack(stk_a);
	ft_free_stack(stk_b);
	free_flags(flags);
	free_op_count(op_count);
}

void	pushswap(char **argv)
{
	t_node		*stk_a;
	t_node		*stk_b;
	t_flags		*flags;
    t_op_count	*op_count;

	stk_a = NULL;
	stk_b = NULL;
	flags = ft_calloc(1, sizeof(t_flags));
	op_count = ft_calloc(1, sizeof(t_op_count));
	stk_a = parsing(argv);
	index_stack(&stk_a);
	diff_selection(&stk_a, &stk_b, flags, op_count);
	if (flags->has_bench == true)
		output_bench(&stk_a, op_count, flags);
	free_all(&stk_a, &stk_b, flags, op_count);
}
