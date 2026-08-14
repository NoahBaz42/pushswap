/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaz-sil <nbaz-sil@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 14:42:23 by bpassos-          #+#    #+#             */
/*   Updated: 2026/08/14 10:51:15 by nbaz-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate_stack(t_stack *stk, t_op_count *op_count, char stk_name)
{
	t_node	*new_start;
	t_node	*last;

	if (!stk || !*stk)
		return ;
	new_start = (*stk)->next;
	last = ft_lstlast(*stk);
	last->next = ft_pop(stk);
	last->next->prev = last;
	*stk = new_start;
	new_start->prev = NULL;
	if (stk_name == 'a')
		op_count->ra++;
	else
		op_count->rb++;
	op_count->total++;
	if (!op_count->checker)
		ft_printf(1, "r%c\n", stk_name);
}

void	op_rr(t_stack *a, t_stack *b, t_op_count *op_count)
{
	if (a && *a)
		rotate_stack(a, op_count, 'a');
	if (b && *b)
		rotate_stack(b, op_count, 'b');
}
