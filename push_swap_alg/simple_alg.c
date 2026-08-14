/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_alg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaz-sil <nbaz-sil@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 19:26:09 by nbaz-sil          #+#    #+#             */
/*   Updated: 2026/08/14 10:50:46 by nbaz-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_simple(t_stack *a, t_stack *b, t_op_count *op_count)
{
	t_node	*min;
	int		half;

	while (stk_is_sorted(*a) == NOT_SORTED)
	{
		min = ft_find_min(*a);
		half = get_target_half(*a, min);
		while ((*a)->content != min->content)
		{
			if (half == TOP_HALF)
				rotate_stack(a, op_count, 'a');
			else
				rrotate_stack(a, op_count, 'a');
		}
		push_stack(a, b, op_count, 'b');
	}
	op_pushall_a(b, a, op_count);
}
