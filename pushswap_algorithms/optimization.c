/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charlie <charlie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 23:17:25 by bpassos-          #+#    #+#             */
/*   Updated: 2026/08/09 08:10:21 by charlie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"
#include <stddef.h>
#include <sys/types.h>

//TODO: rewrite this code remember start at min

// bool check_sort_rot(t_node *stk_a)
// {
// 	size_t		i;
// 	t_node	*min;
// 	size_t	size;

// 	i = 0;
// 	min = ft_find_min(stk_a);
// 	size = ft_lstsize(stk_a);
// 	while (i < size)
// 	{
// 		if(min > min->next)
// 		{
// 			return(0)
// 		}
		
// 	}
	
// }
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
// 	rotate_sort(top);
// 	while (top)
// 	{
// 		printf("%d\n", top->content);
// 		top = top->next;
// 	}
// printf("Sorted:%s\n", stk_is_sorted(top) ? "TRUE" : "FALSE");
// }