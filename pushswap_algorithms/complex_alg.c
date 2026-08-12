/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_alg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charlie <charlie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 08:24:39 by bpassos-          #+#    #+#             */
/*   Updated: 2026/08/11 09:24:05 by charlie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

static bool	bit_is_zero(int index, int bit)
{
	return (!(index & bit));
}

void	radix_sort(t_stack *a, t_stack *b, t_op_count	*op_count)
{
	int		bit;
	int		n;
	t_node	*node;

	bit = 1;
	while (stk_is_sorted(*a) == NOT_SORTED)
	{
		n = ft_lstsize(*a);
		while (n > 0)
		{
			node = *a;
			if (bit_is_zero(node->index, bit))
				push_stack(a, b, op_count, 'b');
			else
				rotate_stack(a, op_count, 'a');
			n--;
		}
		op_pushall_a(b, a, op_count);
		bit *= 2;
	}
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
// int	main(int argc,char **argv)
// {
// 	t_node	*stk_a;
// 	t_node	*stk_b;
	
// 	int	i;

// 	i = 1;
// 	stk_a = NULL;
// 	stk_b = NULL;
// 	if (argc < 2)
// 		return (printf("incorrect # of arguments\n"), 1);
// 	while (i < argc)
// 	{
// 		ft_lstadd_back(&stk_a, ft_lstnew(atoi( argv[i])));
// 		i++;
// 	}
// 	index_stack(stk_a);
// 	printf("Original list:\n");
// 	ft_print_lst(stk_a);
// 	printf("\n------------\n");
// 	radix_sort(&stk_a, &stk_b);
// 	printf("Sorted stack list:\n");
// 	ft_print_lst(stk_a);
// 	return (0);
// }