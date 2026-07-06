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

#include "pushswap.h"

void	del_it(void *content)
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
void    ft_error(void)
{
    write(2, "Error", 5);
    exit (1);
}