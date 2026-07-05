/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charlie <charlie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 21:56:13 by bpassos-          #+#    #+#             */
/*   Updated: 2026/05/29 19:27:41 by charlie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}

// static void	del_it(void *content)
// {
// 	free(content);
// }
// int main (int argc, char **argv)
// {
// 	int *x;
// 	int	i;
// 	t_list *node;
// 	t_list *new_node;
// 	t_list	*temp;

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
// 	ft_lstdelone(node, del_it);
// 	return (0);
// }