/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charlie <charlie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/13 19:01:33 by charlie           #+#    #+#             */
/*   Updated: 2026/08/13 23:11:42 by charlie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"
#include "checker.h"

void	add_op(t_op_lst **lst, t_op_lst *new)
{
	t_op_lst	*last;

	if (!new || !lst)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last = op_last(*lst);
	last->next = new;
	new->prev = last;
}

t_op_lst	*op_last(t_op_lst *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
	{
		lst = lst->next;
	}
	return (lst);
}

t_op_lst	*op_new(char *op)
{
	t_op_lst	*new;

	new = ft_calloc(1, sizeof(t_op_lst));
	if (!new)
		return (NULL);
	new->op = op;
	return (new);
}
