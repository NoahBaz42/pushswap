/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charlie <charlie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 23:17:25 by bpassos-          #+#    #+#             */
/*   Updated: 2026/08/11 07:43:09 by charlie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

static bool	optimize_check(t_node *stk_a, t_node *node)
{
	size_t	i;
	size_t	size;
	t_node *next;

	i = 0;
	size = ft_lstsize(stk_a);
	while (i < size)
	{
		next = node->next;
		if (node->next == NULL)
				next = stk_a;
		if (node->index < next->index)
			node = next;
		else
			break ;
		i++;
	}
	if (node == ft_find_max(stk_a))
		return (SORTED);
	return (NOT_SORTED);
}
bool	optimize(t_stack *stk_a, t_stack *stk_b, t_op_count *op_count)
{
	t_node *min;

	min = ft_find_min(*stk_a);
	if (optimize_check(*stk_a, min) == SORTED)
	{
		while (*stk_a != min)
		{
			if (get_target_half(*stk_a, min) == TOP_HALF)
				rotate_stack(stk_a, op_count, 'a');
			else
				rrotate_stack(stk_a, op_count, 'a');
			// i++;
		}
	}
	if (stk_is_sorted(*stk_a))
	{
		op_pushall_a(stk_b, stk_a, op_count, 'a');
		return (SORTED);
	}
	return (NOT_SORTED);
}
// int	main(int argc,char **argv)
// {
// 	t_node		*stk_a;
// 	t_node		*stk_b;
// 	t_op_count	*op_count;
// 	int	i;

// 	i = 1;
// 	stk_a = NULL;
// 	stk_b = NULL;
// 	op_count = ft_calloc(1, sizeof(t_op_count));
// 	if (argc < 1)
// 		return (printf("incorrect # of arguments\n"), 1);
// 	printf("Unsorted:\n");
// 	while (i < argc)
// 	{
// 		ft_lstadd_back(&stk_a, ft_lstnew(atoi( argv[i])));
// 		i++;
// 	}
// 	printf("Sorted:\n");
// 	index_stack(stk_a);
// 	optimize(&stk_a, &stk_b, op_count);
// 	while (stk_a)
// 	{
// 		printf("%lu\n", stk_a->content);
// 		stk_a = stk_a->next;
// 	}
// 	return (0);
// }