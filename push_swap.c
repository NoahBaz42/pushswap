/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaz-sil <nbaz-sil@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 08:27:51 by bpassos-          #+#    #+#             */
/*   Updated: 2026/08/14 10:51:57 by nbaz-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	diff_selection(t_stack *stk_a, t_stack *stk_b, t_flags *flags,
	t_op_count	*op_count)
{
	size_t	stack_size;

	stack_size = ft_lstsize(*stk_a);
	flags->chosen = flags->difficulty;
	if (stack_size == 3)
	{
		flags->difficulty = DIFF_SIMPLE;
		return (stack_is_3(stk_a, op_count));
	}
	if (stack_size == 5)
	{
		flags->difficulty = DIFF_SIMPLE;
		return (stack_is_5(stk_a, stk_b, op_count));
	}
	if (flags->has_diff == false || flags->difficulty == DIFF_ADAPTIVE)
		ft_resolve_strategy(flags, disorder(*stk_a));
	if (flags->difficulty == DIFF_SIMPLE)
		return (ft_simple(stk_a, stk_b, op_count));
	else if (flags->difficulty == DIFF_MEDIUM)
		return (chunk_sort(stk_a, stk_b, op_count));
	else
		return (radix_sort(stk_a, stk_b, op_count));
}

static void	free_all(t_stack *stk_a, t_stack *stk_b)
{
	ft_free_stack(stk_a);
	ft_free_stack(stk_b);
}

void	push_swap(char **argv)
{
	t_node		*stk_a;
	t_node		*stk_b;
	t_flags		flags;
	t_op_count	op_count;
	float		dis_level;

	stk_a = NULL;
	stk_b = NULL;
	flags = (t_flags){0};
	op_count = (t_op_count){0};
	stk_a = parsing(argv, &flags);
	dis_level = disorder(stk_a);
	index_stack(&stk_a);
	diff_selection(&stk_a, &stk_b, &flags, &op_count);
	if (flags.has_bench == true)
		output_bench(&op_count, &flags, dis_level);
	free_all(&stk_a, &stk_b);
}

int	main(int argc, char **argv)
{
	if (argc < 2)
		return (0);
	push_swap(argv);
	return (0);
}
