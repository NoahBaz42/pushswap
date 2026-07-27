/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpassos- <bpassos-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 02:29:57 by bpassos-          #+#    #+#             */
/*   Updated: 2026/07/16 09:35:31 by bpassos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static t_node *ft_find_highest(t_node *a)
{
	while (a->content < a->next->content)
	{
		a->content = a->next->content;
	}
	return (a);
}

void	ft_tiny_sort(t_node *stack_a)
{
	t_node	*highest_node;
	highest_node = ft_find_highest(stack_a);
	if (stack_a == highest_node)
		ft_rstack(stack_a);
	else if (stack_a->next == highest_node)
		ft_rrstack(stack_a);
	if(stack_a->content > stack_a->next->content)
	 ft_sstack(stack_a);
}