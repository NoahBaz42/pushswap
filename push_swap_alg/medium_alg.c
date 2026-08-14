/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_alg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaz-sil <nbaz-sil@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 08:24:42 by nbaz-sil          #+#    #+#             */
/*   Updated: 2026/08/14 10:50:41 by nbaz-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	set_stack_costs(t_stack *a)
{
	ssize_t	idx;
	ssize_t	mid;
	ssize_t	size;
	t_node	*node;

	node = *a;
	idx = 0;
	size = (ssize_t) ft_lstsize(node);
	mid = size / 2;
	while (node)
	{
		if (idx <= mid)
			(node)->cost = mid - ft_abs((mid - idx)) + 1;
		else
			(node)->cost = size - idx + 1;
		idx++;
		node = (node)->next;
	}
}

static t_node	*node_fetch(t_stack *stk, int index)
{
	t_node	*node;

	node = *stk;
	while (node)
	{
		if (node->index == index)
			return (node);
		node = node->next;
	}
	return (NULL);
}

static t_node	*find_cheapest_node(t_stack *a, ssize_t chunk_size)
{
	ssize_t	i;
	t_node	*node;
	t_node	*target;
	ssize_t	chunk;

	i = ft_find_min(*a)->index;
	target = NULL;
	chunk = chunk_size;
	while (i >= chunk)
		chunk += chunk_size;
	while (i < chunk)
	{
		node = node_fetch(a, i);
		if (node && (!target || node->cost < target->cost))
			target = node;
		i++;
	}
	if (!target)
		return (NULL);
	return (node_fetch(a, target->index));
}

static void	rot_target_node(t_stack *src, char name, t_node *target,
		t_op_count	*op_count)
{
	int		target_half;
	t_node	*head;

	head = *src;
	target_half = get_target_half(head, target);
	while (target != head && target && *src)
	{
		if (target_half == TOP_HALF)
			rotate_stack(src, op_count, name);
		else
			rrotate_stack(src, op_count, name);
		head = *src;
	}
}

void	chunk_sort(t_stack *a, t_stack *b, t_op_count *op_count)
{
	size_t	chunk_size;

	chunk_size = ft_sqrt(ft_lstsize(*a));
	while (*a)
	{
		set_stack_costs(a);
		rot_target_node(a, 'a', find_cheapest_node(a, chunk_size), op_count);
		push_stack(a, b, op_count, 'b');
	}
	while (*b)
	{
		rot_target_node(b, 'b', ft_find_max(*b), op_count);
		push_stack(b, a, op_count, 'a');
	}
}
