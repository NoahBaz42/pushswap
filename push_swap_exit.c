/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_exit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaz-sil <nbaz-sil@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 03:45:57 by nbaz-sil          #+#    #+#             */
/*   Updated: 2026/08/07 07:10:44 by nbaz-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h" 

void ft_give_error(void)
{
    write(2, "Error\n", 6);
    exit(1);
}

void	ft_free_array(char **array, int size)
{
	if (!array)
		return ;
	while (size > 0)
	{
		size--;
		free(array[size]);
	}
	free(array);
	ft_give_error();
}
void	ft_exit_array(char **array, int size)
{
	ft_free_array(array, size);
	ft_give_error();
}
//----[with help of temp, we free every node and then the stack]----------//

void ft_free_stack(t_list **stack)
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
        free(temp);
    }
    free(*stack);
    *stack = NULL;
}
void	ft_exit_stack(t_list **stack)
{
	ft_free_stack(stack);
	ft_give_error();
}