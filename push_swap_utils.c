/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noah-baz <noah-baz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 19:26:22 by noah-baz          #+#    #+#             */
/*   Updated: 2026/07/27 18:06:11 by noah-baz         ###   ########.fr       */
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

//----[unused function: needs further update on previous functions]-------//
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