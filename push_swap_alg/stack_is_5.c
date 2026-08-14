/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_is_5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaz-sil <nbaz-sil@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 23:16:50 by bpassos-          #+#    #+#             */
/*   Updated: 2026/08/14 10:17:13 by nbaz-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	stk_5_is_3(t_stack *a, t_stack *b, t_op_count *op_count)
{
	if (ft_lstsize(*a) == 3)
	{
		stack_is_3(a, op_count);
		op_pushall_a(b, a, op_count);
	}
	else
		give_error();
}

void	stack_is_5(t_stack *a, t_stack *b, t_op_count *op_count)
{
	t_node	*min;
	int		i;

	i = 0;
	min = ft_find_min(*a);
	while (i < 2)
	{
		while (*a != min)
		{
			min = ft_find_min(*a);
			if (get_target_half(*a, min) == BOTTOM_HALF)
				rrotate_stack(a, op_count, 'a');
			else
				rotate_stack(a, op_count, 'a');
		}
		push_stack(a, b, op_count, 'b');
		i++;
	}
	stk_5_is_3(a, b, op_count);
}
