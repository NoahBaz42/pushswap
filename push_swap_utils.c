/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaz-sil <nbaz-sil@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 19:26:22 by noah-baz          #+#    #+#             */
/*   Updated: 2026/08/04 14:28:30 by nbaz-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h" 


void ft_give_error(void)
{
    write(2, "Error\n", 6);
    exit(1);
}

void ft_free_array(char **array)
{
    int i;
    
    i = 0;
    while(array[i])
    {
        free(array[i]);
        i++;
    }
    free(array);
    return ;
}

//----[with help of temp, we free every node and then the stack]----------//

void free_stack(t_list **stack)
{
    t_node  *temp;
    t_node  *current;

    if (!stack || !*stack)
        return ;
    current = (*stack)->home;
    while (current)
    {
        temp = current;
        current = current->next;
        free(temp->content);
        free(temp);
    }
    free(*stack);
    *stack = NULL;
}