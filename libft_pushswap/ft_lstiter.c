/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charlie <charlie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 21:56:20 by bpassos-          #+#    #+#             */
/*   Updated: 2026/05/29 18:58:48 by charlie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*temp;

	if (!lst || !f)
		return ;
	temp = lst;
	while (temp)
	{
		f(temp->content);
		temp = temp->next;
	}
}

// static void	del_it(void *content)
// {
// 	free(content);
// }

// static void ft_testlst(void *content)
// {
// 	printf("%d\n", ( * (int *)content) + 2);
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
// 		temp->next = new_node;
// 		// printf("---\nnew node [%d] data: [%p] %d start @ [%p] %d\n",
// 		// 	i - 1,
// 		// 	temp->next, *(int *)temp->next->content,
// 		// 	node, *(int *)node->content
// 		// );
// 		temp = temp->next;
// 	}
// 	ft_lstiter(node , ft_testlst);
//	ft_lstclear(&node, del_it);
// 	return (0);
// }
