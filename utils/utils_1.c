/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaz-sil <nbaz-sil@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 10:21:54 by nbaz-sil          #+#    #+#             */
/*   Updated: 2026/08/14 10:22:10 by nbaz-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	stk_is_sorted(t_node *stack)
{
	t_node	*temp;

	temp = stack;
	while (temp && temp->next)
	{
		if (temp->content > temp->next->content)
			return (NOT_SORTED);
		temp = temp->next;
	}
	return (SORTED);
}

void	ft_push(t_stack *top, t_node *new)
{
	if (!top)
		return ;
	if (!*top)
	{
		*top = new;
		(*top)->prev = NULL;
		(*top)->next = NULL;
		return ;
	}
	new->next = *top;
	(*top)->prev = new;
	new->prev = NULL;
	*top = new;
}

t_node	*ft_pop(t_stack *top)
{
	t_node	*popped;

	if (!top || !*top)
		return (NULL);
	popped = *top;
	*top = (*top)->next;
	if (*top)
		(*top)->prev = NULL;
	popped->next = NULL;
	return (popped);
}

void	ft_print_lst(t_node *top)
{
	t_node	*stack;

	stack = top;
	while (stack)
	{
		printf("% 5ld: %3ld @ %1ld\n", stack->content, stack->index,
			stack->cost);
		stack = stack->next;
	}
}

int	ft_abs(ssize_t num)
{
	if (num < 0)
		return (num * -1);
	return (num);
}
