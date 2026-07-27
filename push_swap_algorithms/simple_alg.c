/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_alg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpassos- <bpassos-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 19:26:09 by bpassos-          #+#    #+#             */
/*   Updated: 2026/07/16 11:22:37 by bpassos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void    ft_selection_sort(t_node *a)
{
    t_node  *b;
    t_node  *temp;

    b = ft_lstnew(NULL);
    while (a)
    {
        while(a)
        {
            temp->content = a->content;
            if (temp->content < a->next->content)
               temp->content = a->next->content;
        a = a->next;
        }
        ft_pstack(temp->content, b->content);
    }
    ft_pushall_b(b, a);
}