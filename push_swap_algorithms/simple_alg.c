/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_alg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charlie <charlie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 19:26:09 by bpassos-          #+#    #+#             */
/*   Updated: 2026/08/08 04:44:33 by charlie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_simple(t_stack *a)
{
	t_node *b;
	t_node *min;
	int		half;

	b = NULL;
	while (stk_is_sorted(*a) == NOT_SORTED)
	{
		min = ft_find_min(*a);
		half = get_target_half(*a);
		while ((*a)->content != min->content)
		{
			if (half == TOP_HALF)
				ft_rstack(a);
			else
				ft_rrstack(a);
		}
		ft_pstack(a, &b);
	}
	ft_pushall_a(&b, a);
}
// void ft_print_lst(t_node *top)
// {
// 	t_node	*stack;

// 	stack = top;
// 		while (stack)
// 	{
// 		printf("% 5d: %3ld @ %1ld\n", stack->content, stack->index, stack->cost);
// 		stack = stack->next;
// 	}
// }
//-----------find_max----------//
// int	main(int argc,char **argv)
// {
	// t_node	*top;
	// int		i;
// 
	// i = 1;
	// top = NULL;
	// if (argc < 2)
		// return (printf("incorrect # of arguments\n"), 1);
	// printf("list:\n");
	// while (i < argc)
	// {
		// ft_lstadd_back(&top, ft_lstnew(atoi( argv[i])));
		// i++;
	// }
	// ft_simple(&top);
	// ft_print_lst(top);
	// return (0);
// }