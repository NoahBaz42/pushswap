/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaz-sil <nbaz-sil@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 01:20:12 by bpassos-          #+#    #+#             */
/*   Updated: 2026/08/14 10:22:24 by nbaz-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_node	*ft_find_min(t_node *a)
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

int	get_target_half(t_node *a, t_node *target)
{
	t_node	*node;
	size_t	count;

	count = 0;
	node = a;
	if (!target)
		target = ft_find_min(a);
	while (node != target)
	{
		count++;
		node = node->next;
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

t_node	*stk_dup(t_node *stk)
{
	t_node	*new;

	while (stk)
	{
		ft_lstadd_back(&new, ft_lstnew(new->content));
		stk = stk->next;
	}
	return (stk);
}
