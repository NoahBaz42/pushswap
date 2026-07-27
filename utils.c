/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpassos <bpassos@student.42.lisbon>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 04:50:30 by charlie           #+#    #+#             */
/*   Updated: 2026/07/06 04:50:30 by charlie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_pushswap/libft.h"
#include "push_swap.h"

void	ft_del_it(void *content)
{
	free(content);
}
int ft_disorder(t_node *stack)
{
    t_node  *temp;
    int     count;

    temp = stack;
    count = 0;
    while (temp->content < temp->next->content && temp)
    {
        if (temp->content > temp->next->content)
            count++;
        temp = temp->next;
    }
    return (count/ft_lstsize(stack));
}
void    ft_give_error(void)
{
    write(2, "Error", 5);
    exit (1);
}
void    ft_pushall_b(t_node *b, t_node *a)
{
    while (b)
    {
        ft_pstack(b, a);
    }
}