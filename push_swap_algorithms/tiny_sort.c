/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charlie <charlie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 02:29:57 by bpassos-          #+#    #+#             */
/*   Updated: 2026/08/07 06:02:22 by charlie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

void	ft_tiny_sort(t_stack *a)
{
	t_node	*highest_node;

	highest_node = ft_find_max(*a);
	if ((*a) == highest_node)
		ft_rstack(a);
	else if ((*a)->next == highest_node)
		ft_rrstack(a);
	if((*a)->content > (*a)->next->content)
		ft_sstack(a);
}
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