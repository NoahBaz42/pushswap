/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charlie <charlie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 21:56:15 by bpassos-          #+#    #+#             */
/*   Updated: 2026/08/09 02:30:41 by charlie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_lstadd_front(t_node **lst, t_node *new)
{
	if (!new || !lst)
		return ;
	if (!*lst)
		new->next = *lst;
	*lst = new;
	new->prev = NULL;
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
