/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_is_5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charlie <charlie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 23:16:50 by bpassos-          #+#    #+#             */
/*   Updated: 2026/08/09 16:07:29 by charlie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	stack_is_5(t_stack *a, t_op_count	*op_count)
{
	t_node	*b;
	t_node	*min;
	int		i;

	b = NULL;
	i = 0;
	min = ft_find_min(*a);
	while (i < 2)
	{
		while (*a != min)
		{
			if (get_target_half(*a) == BOTTOM_HALF)
				op_rra_stack(a, op_count);
			else
				op_ra_stack(a, op_count);
			min = ft_find_min(*a);
		}
		op_pb_stack(&*a,&b, op_count);
		i++;
	}
	if(ft_lstsize(*a) == 3)
	{
		stack_is_3(&*a, op_count);
		ft_pushall_a(&b, a, op_count);
	}
	else 
		give_error();
}
// int	main(int argc,char **argv)
// {
// 	t_node	*top;
	
// 	int	i;

// 	i = 1;
// 	top = NULL;
// 	if (argc < 2)
// 		return (printf("incorrect # of arguments\n"), 1);
// 	while (i < argc)
// 	{
// 		ft_lstadd_back(&top, ft_lstnew(atoi( argv[i])));
// 		i++;
// 	}
// 	stack_is_5(&top);
// 	printf("Sorted:\n");
// 	while (top)
// 	{
// 		printf("%d\n", top->content);
// 		top = top->next;
// 	}
// }