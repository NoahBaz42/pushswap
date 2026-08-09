/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charlie <charlie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 05:51:12 by bpassos-          #+#    #+#             */
/*   Updated: 2026/08/09 01:06:16 by charlie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_pushswap/libft.h"
#include "push_swap.h"
#include <stdint.h>
#include <stdio.h>

// static void ft_print_lst(t_stack *first)
// {
// 	t_node	*temp;
// 	int		num;
// 	int		i;

// 	i = 1;
// 	temp = *first;
// 	while (temp)
// 	{
// 		num = temp->content;
// 		printf("%d: %d\n", i, num);
// 		i++;
// 		temp = temp->next;
// 		if (i > 11)
// 			break ;
// 	}
// }

// int main (int argc, char **argv)
// {
// 	int *x;
// 	int	i;
// 	t_node *lst;

// 	i = 2;
// 	if (argc < 2)
// 		return (printf("incorrect # of arguments\n"), 1);
// 	x = malloc(sizeof(int));
// 	*x = ft_atoi(argv[1]);
// 	lst = ft_lstnew(x);
// 	while (i < argc)
// 	{
// 		x = malloc(sizeof(int));
// 		*x = ft_atoi(argv[i]);
// 		ft_lstadd_back(&lst, ft_lstnew(x));
// 		i++;
// 	}
// 	ft_print_lst(&lst);
// 	printf("\nSorted list:\n");
// 	ft_tiny_sort (&lst);
// 	ft_print_lst(&lst);
// 	return (0);
// }


// int	main(int argc,char **argv)
// {
// 	t_node	*top;
	
// 	int	i;

// 	i = 1;
// 	top = NULL;
// 	if (argc < 2)
// 		return (printf("incorrect # of arguments\n"), 1);
// 	printf("Unsorted:\n");
// 	while (i < argc)
// 	{
// 		ft_lstadd_back(&top, ft_lstnew(atoi( argv[i])));
// 		i++;
// 	}
// 	printf("Sorted:\n");
// 	ft_tiny_sort(&top);
// 	while (top)
// 	{
// 		printf("%d\n", top->content);
// 		top = top->next;
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
// 	printf("Unsorted:\n");
// 	while (i < argc)
// 	{
// 		ft_lstadd_back(&top, ft_lstnew(atoi( argv[i])));
// 		i++;
// 	}
// 	printf("Sorted:\n");
// 	ft_simple(&top);
// 	while (top)
// 	{
// 		printf("%d\n", top->content);
// 		top = top->next;
// 	}
// }


