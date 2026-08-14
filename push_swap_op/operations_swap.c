/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaz-sil <nbaz-sil@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 14:31:47 by bpassos-          #+#    #+#             */
/*   Updated: 2026/08/14 10:51:27 by nbaz-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap_stack(t_stack *stk, t_op_count *op_count, char stk_name)
{
	int	temp;

	if (ft_lstsize(*stk) == 1)
		return ;
	if (!*stk)
	{
		ft_free_stack(stk);
		give_error();
	}
	temp = (*stk)->content;
	(*stk)->content = (*stk)->next->content;
	(*stk)->next->content = temp;
	if (stk_name == 'a')
		op_count->sa++;
	else
		op_count->sb++;
	op_count->total++;
	if (!op_count->checker)
		ft_printf(1, "s%c\n", stk_name);
}

void	op_ss(t_stack *a, t_stack *b, t_op_count *op_count)
{
	if (a && *a)
		swap_stack(a, op_count, 'a');
	if (b && *b)
		swap_stack(b, op_count, 'b');
}
