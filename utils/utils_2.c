/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charlie <charlie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 01:20:12 by bpassos-          #+#    #+#             */
/*   Updated: 2026/08/06 04:00:44 by charlie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
t_node *ft_find_min(t_node *a)
{
	t_node	*min;
	t_node	*node;
	
	min = a;
	node = a;
	while (node && node->next)
	{
		if ((min->content) > (node->next->content))
			min = node->next;
		node = node->next;
	}
	return (min);
}

int ft_small_path_min(t_node *a)
{
	size_t	count;
	t_node	*min;

	count = 0;
	min = ft_find_min(a);
	while(a != min)
	{
		count++;
		a = a->next;
	}
	if (count > (ft_lstsize(a) / 2))
		return (0);
	return (1);
}

int	ft_sqrt(int nb)
{
	int	i;

	i = 0;
	while ((i * i) <= nb)
		i++;
	if ((i * i) > nb)
		i--;
	return (i);
}