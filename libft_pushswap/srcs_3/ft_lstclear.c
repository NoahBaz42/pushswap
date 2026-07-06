/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpassos- <bpassos-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 21:56:18 by bpassos-          #+#    #+#             */
/*   Updated: 2026/07/06 05:04:43 by bpassos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

// static void	del_it(void *lst)
// {
// 	t_list	*node;

// 	node = lst;
// 	printf("deleting node content at memory address %p\n", node->content);
// }

void	ft_lstclear(t_node *lst, void (*del)(void *))
{
	t_node	*head;
	t_node	*node;

	if (!lst || !*lst || !del)
		return ;
	node = *lst;
	while (node)
	{
		head = node->next;
		ft_lstdelone(node, del);
		node = head;
	}
	*lst = NULL;
}

// int main (int argc, char **argv)
// {
// 	int *x;
// 	int	i;
// 	t_node *node;
// 	t_node *new_node;
// 	t_node	*temp;

// 	i = 1;
// 	if (argc < 2)
// 		return (printf("incorrect # of arguments\n"), 1);
// 	x = malloc(sizeof(x));
// 	*x = ft_atoi(argv[i++]);
// 	node = ft_lstnew(x);
// 	temp = node;
// 	while (i < argc)
// 	{
// 		x = malloc(sizeof(x));
// 		*x = ft_atoi(argv[i++]);
// 		new_node = ft_lstnew(x);
// 		ft_lstadd_back( &node, new_node);
// 		// printf("---\nnew node [%d] data: [%p] %d start @ [%p] %d\n",
// 		// 	i - 1,
// 		// 	temp->next, *(int *)temp->next->content,
// 		// 	node, *(int *)node->content
// 		// );
// 		temp = temp->next;
// 	}
// 	ft_lstclear(&node, del_it);
// 	return (0);
// }