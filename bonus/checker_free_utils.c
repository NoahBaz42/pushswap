/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_free_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charlie <charlie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/13 22:54:45 by charlie           #+#    #+#             */
/*   Updated: 2026/08/13 22:58:15 by charlie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	free_op_node(t_op_lst *node)
{
	if (!node)
		return ;
	free(node);
}

void	free_one_op_node(t_op_lst *lst, void (*del)(t_op_lst *))
{
	if (!lst || !del)
		return ;
	del(lst);
	free(lst);
}

void	free_op_lst(t_op_lst **lst, void (*del)(t_op_lst *))
{
	t_op_lst	*head;
	t_op_lst	*node;

	if (!lst || !*lst || !del)
		return ;
	node = *lst;
	while (node)
	{
		head = node->next;
		free_one_op_node(node, del);
		node = head;
	}
	lst = NULL;
}

