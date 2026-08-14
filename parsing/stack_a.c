/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaz-sil <nbaz-sil@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 03:23:23 by nbaz-sil          #+#    #+#             */
/*   Updated: 2026/08/14 10:17:59 by nbaz-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*array_to_stk(char **array, size_t count)
{
	t_node	*stk_a;
	int		i;
	long	check;

	stk_a = NULL;
	i = 0;
	while (array[i])
	{
		check = ft_atol(array[i]);
		if (check == 1L + INT_MAX)
		{
			ft_free_array(array, count);
			exit_stack(&stk_a);
		}
		ft_lstadd_back(&stk_a, ft_lstnew(check));
		i++;
	}
	return (stk_a);
}

bool	dup_check(t_node *stack_a)
{
	t_node	*node1;
	t_node	*node2;

	if (!stack_a)
	{
		ft_free_node(stack_a);
		give_error();
	}
	node1 = stack_a;
	node2 = node1->next;
	while (node1)
	{
		node2 = node1->next;
		while (node2)
		{
			if (node1->content == node2->content)
				return (INVALID);
			node2 = node2->next;
		}
		node1 = node1->next;
	}
	return (VALID);
}
