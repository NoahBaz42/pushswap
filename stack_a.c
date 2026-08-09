/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaz-sil <nbaz-sil@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 03:23:23 by nbaz-sil          #+#    #+#             */
/*   Updated: 2026/08/09 03:39:42 by nbaz-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*-------[ adds a new node to stack_a, and updates prev ]----------*/

static void	ft_add_node(t_stack *stack_a, int value)
{
	t_node	*new;
	t_node	*last;

	new = ft_lstnew(value);
	if (!new)
		ft_give_error();
	if (!stack_a->home)
		stack_a->home = new;
	else
	{
		last = ft_lstlast(stack_a->home);
		ft_lstadd_back(stack_a->home, new);
		new->prev = last;
	}
}

/*-------[ main function: ft_array_to_stack ]----------*/
/*-------[ adds every node with atol, long int ]-------*/

t_list	*ft_array_to_stack(char **array)
{
	t_list	*stack_a;
	int		i;

	stack_a = malloc(sizeof(t_list));
	if (!stack_a)
		ft_give_error();
	stack_a->home = NULL;
	i = 0;
	while (array[i])
	{
		ft_add_node(stack_a, ft_atol(array[i]));
		i++;
	}
	return (stack_a);
}

/*[ checks for duplicates in stack_a (it sees "05, 5, +5" as equal) ]*/
/*[ line 75: its just hard to look bc in struct content is a void * ]*/
/*[ would be easier if it was an int butIm not changing ts rn alone ]*/

void	ft_is_it_duplicate(t_list *stack_a)
{
	t_node	*i;
	t_node	*j;

	i = stack_a->home;
	while (i)
	{
		j = i->next;
		while (j)
		{
			if (i->content == j->content)
				ft_give_error();
			j = j->next;
		}
		i = i->next;
	}
}