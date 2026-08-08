/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charlie <charlie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 23:17:25 by bpassos-          #+#    #+#             */
/*   Updated: 2026/08/08 01:30:23 by charlie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "libft_pushswap/libft.h"
#include <stddef.h>
#include <sys/types.h>

//TODO: rewrite this code remember start at min

// bool rotate_sort(t_node *original)
// {
// 	ssize_t	i;
// 	ssize_t	size;
// 	t_node *test;
// 	int half;

// 	i = 0;
// 	test = stk_dup(original);
// 	size = ft_lstsize(original);
// 	half = get_target_half(ft_find_min(original));
// 	if (rotate_sort(test) == SORTED)
// 		test = original;
// 	while (stk_is_sorted(test) == NOT_SORTED && i < size)
// 	{
// 		if(half == TOP_HALF)
// 			ft_rstack(&test);
// 		else
// 			ft_rrstack(&test);
// 		i++;
// 	}
// 	if (stk_is_sorted(test) == SORTED)
// 		return(SORTED);
// 	return(NOT_SORTED);
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