/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charlie <charlie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 03:23:23 by nbaz-sil          #+#    #+#             */
/*   Updated: 2026/08/09 08:10:21 by charlie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_node	*array_to_stk(char **array)
{
	t_node	*stack_a;
	int		i;

	stack_a = NULL;
	i = 0;
	while (array[i])
	{
		ft_lstadd_back(&stack_a, ft_lstnew(ft_atol(array[i])));
		i++;
	}
	return (stack_a);
}

/*[ checks for duplicates in stack_a (it sees "05, 5, +5" as equal) ]*/
/*[ line 75: its just hard to look bc in struct content is a void * ]*/
/*[ would be easier if it was an int butIm not changing ts rn alone ]*/

bool	int_check(t_node *stack_a)
{
	t_node	*node;

	if (!stack_a)
	{
		ft_free_node(stack_a);
		give_error();
	}
	node = stack_a;
	while (node && node->next)
	{
		if (node->content == node->next->content
			 || node->content > INT_MAX || node->content < INT_MIN)
			return (INVALID);
		node = node->next;
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