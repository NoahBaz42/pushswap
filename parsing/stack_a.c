/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charlie <charlie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 03:23:23 by nbaz-sil          #+#    #+#             */
/*   Updated: 2026/08/13 20:25:39 by charlie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_node	*array_to_stk(char **array)
{
	t_node	*stk_a;
	int		i;

	stk_a = NULL;
	i = 0;
	while (array[i])
	{
		ft_lstadd_back(&stk_a, ft_lstnew(ft_atol(array[i])));
		i++;
	}
	return (stk_a);
}

/*[ checks for duplicates in stack_a (it sees "05, 5, +5" as equal) ]*/
/*[ line 75: its just hard to look bc in struct content is a void * ]*/
/*[ would be easier if it was an int butIm not changing ts rn alone ]*/

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
// int	main(int argc,char **argv)
// {
// 	t_node	*stk_a;

// 	stk_a = NULL;
// 	if (argc < 2)
// 		return (printf("incorrect # of arguments\n"), 1);
// 	stk_a = array_to_stk(argv);
// 	printf("Stack_a:\n");
// 	ft_print_lst(stk_a);
// 	return (0);
// }