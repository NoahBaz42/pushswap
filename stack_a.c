/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noah-baz <noah-baz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 21:31:36 by noah-baz          #+#    #+#             */
/*   Updated: 2026/07/27 17:47:58 by noah-baz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h" 

/*-------[ adds a new node to stack_a, and updates prev ]----------*/

static void	ft_add_node(t_list *stack_a, int value)
{
	t_node	*new;
	t_node	*last;
	int		*content;

	content = malloc(sizeof(int));
	if (!content)
		ft_give_error();
	*content = value;
	new = ft_lstnew(content);
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
			if (*(int *)i->content == *(int *)j->content)
				ft_give_error();
			j = j->next;
		}
		i = i->next;
	}
}
/*[------------------!!!NEEDS REVISION!!!!------------------------- ]*/
/*[ ps: DOES NOT give a valid error: must free BEFORE exiting.. ]*/
