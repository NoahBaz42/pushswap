/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpassos- <bpassos-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 21:56:10 by bpassos-          #+#    #+#             */
/*   Updated: 2026/06/02 17:02:48 by bpassos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	ft_lstlast(*lst)->next = new;
}

// static void	del_it(void *content)
// {
// 	free(content);
// }

// static void ft_print_lst(t_list *first)
// {
// 	t_list	*temp;
// 	int		num;
// 	int		i;

// 	i = 1;
// 	temp = first;
// 	while (temp)
// 	{
// 		num = *(int *)temp->content;
// 		printf("%d: %d\n", i, num);
// 		i++;
// 		temp = temp->next;
// 		if (i > 11)
// 			break ;
// 	}
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
// 		ft_lstadd_back( &temp, new_node);
// 		// printf("---\nnew node [%d] data: [%p] %d start @ [%p] %d\n",
// 		// 	i - 1,
// 		// 	temp->next, *(int *)temp->next->content,
// 		// 	node, *(int *)node->content
// 		// );
// 		temp = temp->next;
// 	}
// 	ft_print_lst(temp);
//	ft_lstclear(&temp, del_it);
// 	return (0);
// }