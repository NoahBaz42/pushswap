/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charlie <charlie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 21:56:25 by bpassos-          #+#    #+#             */
/*   Updated: 2026/08/13 23:04:47 by charlie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_node	*ft_lstmap(t_node *lst, int (*f)(int), void (*del)(long))
{
	t_node	*nlst;
	t_node	*new;

	if (!lst || !f || !del)
		return (NULL);
	nlst = NULL;
	while (lst)
	{
		new = ft_lstnew(f(lst->content));
		if (!new)
		{
			ft_lstclear(&new, del);
			return (NULL);
		}
		ft_lstadd_back(&nlst, new);
		lst = lst->next;
	}
	return (nlst);
}

// static void	del_it(void *content)
// {
// 	free(content);
// }

// static void *ft_testlst(void *content)
// {
// 	int	*x;

// 	x = malloc(sizeof(int));
// 	*x = (*(int *)content);
// 	printf("old [%d]\n", *x);
// 	*x *= 10;
// 	printf("new [%d]\n", *x);
// 	return (x);
// }

// int main (int argc, char **argv)
// {
// 	int		i;
// 	int 	*x;
// 	t_node	*lst;
// 	t_node	*new_lst;
// 	t_node	*node;

// 	i = 1;
// 	if (argc < 2)
// 		return (printf("incorrect # of arguments\n"), 1);
// 	x = malloc(sizeof(x));
// 	*x = ft_atoi(argv[i++]);
// 	lst = ft_lstnew(x);
// 	while (i < argc)
// 	{
// 		x = malloc(sizeof(int));
// 		*x = ft_atoi(argv[i++]);
// 		node = ft_lstnew(x);
// 		ft_lstadd_back(&lst, node);
// 	}
// 	new_lst = ft_lstmap(lst , ft_testlst, del_it);
// 	ft_lstclear(&lst, del_it);
// 	ft_lstclear(&new_lst, del_it);
// 	return (0);
// }