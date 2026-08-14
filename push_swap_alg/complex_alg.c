/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_alg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaz-sil <nbaz-sil@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 08:24:39 by nbaz-sil          #+#    #+#             */
/*   Updated: 2026/08/14 10:50:34 by nbaz-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static bool	bit_is_zero(int index, int bit)
{
	return (!(index & bit));
}

void	radix_sort(t_stack *a, t_stack *b, t_op_count *op_count)
{
	int		bit;
	int		n;
	t_node	*node;

	bit = 1;
	while (stk_is_sorted(*a) == NOT_SORTED)
	{
		n = ft_lstsize(*a);
		while (n > 0)
		{
			node = *a;
			if (bit_is_zero(node->index, bit))
				push_stack(a, b, op_count, 'b');
			else
				rotate_stack(a, op_count, 'a');
			n--;
		}
		op_pushall_a(b, a, op_count);
		bit *= 2;
	}
}
