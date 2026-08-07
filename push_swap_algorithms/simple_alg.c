/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_alg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charlie <charlie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 19:26:09 by bpassos-          #+#    #+#             */
/*   Updated: 2026/08/06 21:21:51 by charlie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_simple(t_node **a)
{
	t_node *b;
	t_node *min;

	b = NULL;
	while (!ft_is_sorted(*a))
	{
		min = ft_find_min(*a);
		if (ft_small_path_min(*a))
			while ((*a)->content != min->content)
				ft_rstack(a);
		else
			while((*a)->content != min->content)
				ft_rrstack(a);
		ft_pstack(a, &b);
	}
	ft_pushall_a(&b, a);
}
// -----------find_max----------//
// int	main(int argc,char **argv)
// {
// 	t_node	*top;
// 	int		i;

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
// 	ft_simple(&top);
// }