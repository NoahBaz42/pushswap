/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rrotate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaz-sil <nbaz-sil@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 22:00:56 by bpassos-          #+#    #+#             */
/*   Updated: 2026/08/14 10:15:33 by nbaz-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rrotate_stack(t_stack *stk, t_op_count *op_count, char stk_name)
{
	t_node	*new_top;

	if (!stk || !*stk)
	{
		printf("rrs\n");
		ft_free_stack(stk);
		give_error();
	}
	new_top = ft_lstlast(*stk);
	new_top->prev->next = NULL;
	new_top->prev = NULL;
	new_top->next = *stk;
	new_top->next->prev = new_top;
	(*stk) = new_top;
	if (stk_name == 'a')
		op_count->rra++;
	else
		op_count->rrb++;
	op_count->total++;
	if (!op_count->checker)
		ft_printf(1, "rr%c\n", stk_name);
}

void	op_rrr(t_stack *a, t_stack *b, t_op_count *op_count)
{
	if (a && *a)
		rrotate_stack(a, op_count, 'a');
	if (b && *b)
		rrotate_stack(b, op_count, 'b');
}
