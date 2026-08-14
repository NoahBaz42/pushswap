/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaz-sil <nbaz-sil@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 14:37:15 by bpassos-          #+#    #+#             */
/*   Updated: 2026/08/14 10:51:04 by nbaz-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_stack(t_stack *src, t_stack *dest, t_op_count *op_count,
		char stk_name)
{
	t_node	*tmp;

	if (!src || !dest)
	{
		ft_free_stack(dest);
		ft_free_stack(src);
		give_error();
	}
	if (!*src)
		return ;
	tmp = ft_pop(src);
	ft_push(dest, tmp);
	if (stk_name == 'a')
		op_count->pa++;
	else
		op_count->pb++;
	op_count->total++;
	if (!op_count->checker)
		ft_printf(1, "p%c\n", stk_name);
}

void	op_pushall_a(t_stack *b, t_stack *a, t_op_count *op_count)
{
	while (*b && b)
	{
		push_stack(b, a, op_count, 'a');
	}
}
