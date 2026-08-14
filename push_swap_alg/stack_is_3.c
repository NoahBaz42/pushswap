/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_is_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaz-sil <nbaz-sil@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 02:29:57 by bpassos-          #+#    #+#             */
/*   Updated: 2026/08/14 10:17:19 by nbaz-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <strings.h>

t_node	*ft_find_max(t_node *a)
{
	t_node	*max;
	t_node	*next;

	max = a;
	next = a;
	while (next && next->next)
	{
		if ((max->content) < (next->next->content))
			max = next->next;
		next = next->next;
	}
	return (max);
}

void	stack_is_3(t_stack *a, t_op_count *op_count)
{
	t_node	*highest_node;

	highest_node = ft_find_max(*a);
	if ((*a) == highest_node)
		rotate_stack(a, op_count, 'a');
	else if ((*a)->next == highest_node)
		rrotate_stack(a, op_count, 'a');
	if ((*a)->content > (*a)->next->content)
		swap_stack(a, op_count, 'a');
}
