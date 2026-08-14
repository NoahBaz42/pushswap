/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_exit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaz-sil <nbaz-sil@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 03:45:57 by nbaz-sil          #+#    #+#             */
/*   Updated: 2026/08/14 10:51:48 by nbaz-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	give_error(void)
{
	ft_printf(2, "Error\n");
	exit(1);
}

void	ft_free_array(char **array, size_t size)
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

void	exit_array(char **array, size_t size)
{
	ft_free_array(array, size);
	give_error();
}

void	exit_stack(t_stack *stack)
{
	ft_free_stack(stack);
	give_error();
}
