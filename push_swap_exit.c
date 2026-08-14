/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   push_swap_exit.c                                   :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: username <username@student.42tokyo.jp>    #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/08/07 03:45:57 by username         #+#    #+#              */
/*   Updated: 2026/08/12 21:38:55 by username        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	give_error(void)
{
	ft_printf(2, "Error\n");
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
}

void	exit_array(char **array, int size)
{
	ft_free_array(array, size);
	give_error();
}

//----[with help of temp, we free every node and then the stack]----------//

void	exit_stack(t_stack *stack)
{
	ft_free_stack(stack);
	give_error();
}
