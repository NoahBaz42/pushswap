/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noah-baz <noah-baz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 19:26:22 by noah-baz          #+#    #+#             */
/*   Updated: 2026/06/30 21:14:10 by noah-baz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h" 


void give_error(void)
{
    write(2, "Error\n", 6);
    exit(1);
}

void free_array(char **array)
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

void free_list(t_list list)
{
    if(!list)
        return;
    while(list->head)
    
}