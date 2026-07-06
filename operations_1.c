/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpassos- <bpassos-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 22:01:00 by bpassos-          #+#    #+#             */
/*   Updated: 2026/07/06 06:16:17 by bpassos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_pushswap/libft.h"
#include "pushswap.h"

void    ft_sstack(t_node *stack)
{
    t_node  *temp;

    if (ft_lstsize(stack) == 1)
        return ;
    if (!stack)
        ft_error();
    temp = stack->content;
    stack->content = stack->next->content;
    stack->next->content = stack->content;
}
void    ft_ss(t_node *stack_a, t_node *stack_b)
{
    ft_sstack(stack_a);
    ft_sstack(stack_b);
}
void    ft_pstack(t_node *top, t_node *add_top)
{
    if (!top || !add_top)
        ft_error();
    if (add_top->content == NULL)
        return ;
    ft_lstadd_front(top->content, add_top->content);
}
void    ft_rstack(t_node *stack)
{
    t_node  *last;

    if (!stack)
        ft_error();
    last = ft_lstlast(stack);
    ft_lstadd_front(stack->content, ft_lstlast(stack->content));
    ft_lstdelone(last, ft_del_it);
}
void    ft_rr(t_node *stack_a, t_node *stack_b)
{
    if (!stack_a || !stack_b)
        ft_error();
    ft_rstack(stack_a);
    ft_rstack(stack_b);
}