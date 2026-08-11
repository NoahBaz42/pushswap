/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_is_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charlie <charlie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 02:29:57 by bpassos-          #+#    #+#             */
/*   Updated: 2026/08/11 06:07:13 by charlie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"
#include <strings.h>

t_node *ft_find_max(t_node *a)
{
	t_node	*max;
	t_node	*next;
	
	max = a;
	next = a;
	while (next && next->next)
	{
		if ((max->content) < (next->next->content))
			max = next->next;
		next = next->next;
	}
	return (max);
}

void	stack_is_3(t_stack *a, t_op_count *op_count)
{
	t_node	*highest_node;

	highest_node = ft_find_max(*a);
	if ((*a) == highest_node)
		rotate_stack(a, op_count, 'a');
	else if ((*a)->next == highest_node)
		rrotate_stack(a, op_count, 'a');
	if((*a)->content > (*a)->next->content)
		swap_stack(a, op_count, 'a');
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
// 	stk_is_3(stk_a, op_count);
// 	while (stk_a)
// 	{
// 		printf("%lu\n", stk_a->content);
// 		stk_a = stk_a->next;
// 	}
// 	return (0);
// }