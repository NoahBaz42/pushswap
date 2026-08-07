/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_5.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpassos- <bpassos-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 23:16:50 by bpassos-          #+#    #+#             */
/*   Updated: 2026/08/05 01:42:26 by bpassos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_stack_is_5(t_node **a)
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
			if(!ft_small_path_min(*a))
				ft_rrstack(a);
			else
				ft_rstack(a);
			min = ft_find_min(*a);
		}
		ft_pstack(&*a,&b);
		i++;
	}
	if(ft_lstsize(*a) == 3)
	{
		ft_tiny_sort(&*a);
		ft_pushall_a(&b, a);
	}
	else 
		ft_give_error();
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
// 	ft_stack_is_5(&top);
// 	printf("Sorted:\n");
// 	while (top)
// 	{
// 		printf("%d\n", top->content);
// 		top = top->next;
// 	}
// }