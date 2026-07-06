/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpassos- <bpassos-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 21:56:15 by bpassos-          #+#    #+#             */
/*   Updated: 2026/07/06 05:04:36 by bpassos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_lstadd_front(t_node *lst, t_node *new)
{
	if (!lst || !new)
		return ;
	if (*lst)
		new->next = *lst;
	*lst = new;
}

// static void	del_it(void *content)
// {
// 	free(content);
// }

// static void ft_print_lst(t_node *first)
// {
// 	t_node	*temp;
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
// 	int x;
// 	int	i;
// 	t_node *lst;
// 	t_node *node;

// 	i = 2;
// 	if (argc < 2)
// 		return (printf("incorrect # of arguments\n"), 1);
// 	x = ft_atoi(argv[1]);
// 	lst = ft_lstnew(&x);
// 	node = lst;
// 	while (i < argc && node)
// 	{
// 		x = ft_atoi(argv[i]);
// 		ft_lstadd_front(&node, ft_lstnew(&x));
// 		node = node->next;
// 		i++;
// 	}
// 	ft_print_lst(lst);
// 	ft_lstclear(&lst, del_it);
// 	return (0);
// }
