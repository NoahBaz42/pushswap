/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charlie <charlie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/01 21:09:30 by bpassos-          #+#    #+#             */
/*   Updated: 2026/08/09 08:10:21 by charlie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_pushswap/libft.h"
#include "pushswap.h"

static int	ft_get_min(t_node *a)
{
	int		min;
	static int	index = 0;

	min = INT_MAX;
	while (a)
	{
		if (min > a->content)
		{
			min = a->content;
			a->indexed = true;
			a->index = index;
		}
		a = a->next;
	}
	index++;
	return (min);
}

static int	ft_get_next_min(t_node *a, int ref)
{
	long		min;
	static int	index = 1;

	min = LONG_MAX;
	while (a)
	{
		if (min > a->content && a->content > ref)
		{
			min = a->content;
			a->indexed = true;
			a->index = index;
		}
		a = a->next;
	}
	index++;
	return (min);
}

void index_stack(t_node *a)
{
	size_t		size;
	size_t		i;
	int			ref;
	static bool	executed;

	i = 0;
	if (executed)
	{
		printf("ERR: index called twice!\n");
		give_error();
	}
	executed = true;
	size = ft_lstsize(a);
	ref = ft_get_min(a);
	while (i < size)
	{
		ref = ft_get_next_min(a, ref);
		i++;
	}
}
