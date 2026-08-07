/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charlie <charlie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/01 21:09:30 by bpassos-          #+#    #+#             */
/*   Updated: 2026/08/07 01:53:18 by charlie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_pushswap/libft.h"
#include "push_swap.h"
#include <limits.h>
#include <sys/types.h>

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
	int			min;
	static int	index = 1;

	min = INT_MAX;
	while (a)
	{
		if (min > a->content && a->content != ref && a->content > ref)
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
	size_t					size;
	size_t					i;
	int						ref;

	i = 0;
	size = ft_lstsize(a);
	ref = ft_get_min(a);
	while (i < size)
	{
		ref = ft_get_next_min(a, ref);
		i++;
	}
}
