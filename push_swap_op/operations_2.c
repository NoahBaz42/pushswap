/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpassos- <bpassos-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 22:00:56 by bpassos-          #+#    #+#             */
/*   Updated: 2026/07/16 08:26:31 by bpassos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void    ft_rrstack(t_node *stack)
{
    ft_lstadd_back(ft_lstlast(stack->content), stack->content);
    ft_lstdelone(stack, ft_del_it);
}
void    ft_rrr(t_node *stack_a, t_node *stack_b)
{
    ft_rrstack(stack_a);
    ft_rrstack(stack_b);
}