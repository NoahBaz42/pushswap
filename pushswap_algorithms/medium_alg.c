/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_alg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charlie <charlie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 08:24:42 by bpassos-          #+#    #+#             */
/*   Updated: 2026/08/09 16:10:45 by charlie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

/**
 * TODO:
 *  - NOW --- Figure out the target node
 * 	- review cost calculation
 * 
 * 
 */

int	ft_abs(ssize_t num)
{
	if (num < 0)
		return(num * -1);
	return(num);
}

static void set_stack_costs(t_stack *a)
{
	ssize_t	idx;
	ssize_t	mid;
	ssize_t size;
	t_node	*node;
	
	node = *a;
	idx = 0;
	size = (ssize_t)ft_lstsize(node);
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

static void get_cheapest(t_node *node, ssize_t *target_index, ssize_t *min_cost)
{
	if (*min_cost == -1 || *min_cost > node->cost)
	{
		*target_index = node->index;
		*min_cost = node->cost;
	}
}

static bool	set_cheapest(t_node *target_node, ssize_t *target_index, ssize_t i)
{
	ssize_t min_cost;

	min_cost = -1;
	if (target_node->index == i)
	{
		get_cheapest(target_node, target_index, &min_cost);
		return (FOUND);
	}
	return (NOT_FOUND);
}

static t_node *iterate_node(t_node *target_node, ssize_t target_index)
{
	t_node *node;

	node = target_node;
	while (node)
	{
		if (node->index == target_index)
			return (node);
		node = node->next;
	}
	return (NULL);
}

static t_node *find_cheapest_node(t_stack *a, ssize_t chunk_size)
{
	ssize_t		target_index;
	t_node		*node;
	t_node		*head;
	int			ret;
	static int	i = 0;
	
	chunk_size += i;
	target_index = -1;
	head = *a;
	node = head;
	while (i < chunk_size && node)
	{
		ret = set_cheapest(node, &target_index, i);
		if (ret == FOUND)
			node = head;
		else
			node = node->next;
		i += ret;
	}
	node = head;
	return (iterate_node(node, target_index));
}

static void	push_target_node(t_stack *src, t_stack *dest,
						t_node *target,t_op_count	*op_count)
{
	int		target_half;
	t_node	*head;

	head = *src;
	target_half = get_target_half(head);
	while (target != head && target)
	{
		if (target_half == TOP_HALF)
			op_ra_stack(src, op_count);
		else
			op_rra_stack(src, op_count);
		head = *src;
	}
	op_pb_stack(src, dest, op_count);

}

void	chunk_sort(t_stack *a, t_stack *b, t_op_count	*op_count)
{
	ssize_t	chunk_size;

	chunk_size = ft_sqrt(ft_lstsize(*a));
	while (*a)
	{
		set_stack_costs(a);
		push_target_node(a, b, find_cheapest_node(a, chunk_size), op_count);
	}
	while (*b)
		push_target_node(b, a, ft_find_max(*b), op_count);
}

void ft_print_lst(t_node *top)
{
	t_node	*stack;

	stack = top;
		while (stack)
	{
		printf("% 5ld: %3ld @ %1ld\n", stack->content, stack->index, stack->cost);
		stack = stack->next;
	}
}
//-------cost-------//
// int	main(int argc,char **argv)
// {
// 	t_node	*top;
// 	t_node	*head;
// 	t_node	*cheapest;
	
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
// 	ft_index(top);
// 	stk_set_costs(&top);
// 	head = top;
// 	while (top)
// 	{
// 		printf("% 5d: %3lu @ %1lu\n", top->content, top->index, top->cost);
// 		top = top->next;
// 	}
// 	top = head;
// 	cheapest = find_cheapest_node(&top, ft_sqrt(ft_lstsize(top)));
// 	printf ("\n###Cheapest node = %d###\n",
// 		cheapest->content);
// 	return (0);
// }
//-------chunk_sort------//
// int	main(int argc,char **argv)
// {
// 	int	i;
// 	t_node	*stk_a;
// 	t_node	*stk_b;

// 	i = 1;
// 	stk_a = NULL;
// 	stk_b = NULL;
// 	if (argc < 2)
// 		return (printf("incorrect # of arguments\n"), 1);
// 	while (i < argc)
// 	{
// 		ft_lstadd_back(&stk_a, ft_lstnew(atoi( argv[i])));
// 		i++;
// 	}
// 	index_stack(stk_a);
// 	printf("Original list:\n");
// 	ft_print_lst(stk_a);
// 	printf("\n------------\n");
// 	chunk_sort(&stk_a, &stk_b);
// 	printf("Sorted stack list:\n");
// 	ft_print_lst(stk_a);
// 	return (0);
// }