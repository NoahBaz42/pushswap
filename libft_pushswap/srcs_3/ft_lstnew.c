/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charlie <charlie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 21:56:27 by username         ##+#    #+#             */
/*   Updated: 2026/08/13 23:48:32 by charlie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_node	*ft_lstnew(int content)
{
	t_node	*new;

	new = ft_calloc(1, sizeof(t_node));
	if (!new)
		return (NULL);
	new->content = content;
	new->cost = -1;
	new->index = -1;
	new->size = -1;
	new->chunk_min = 1;
	return (new);
}

// t_node	*ft_lstnew(int content)
// {
// 	t_node	*new;

// 	new = malloc(sizeof(t_node));
// 	if (!new)
// 		return (NULL);
// 	new->content = content;
// 	new->next = NULL;
// 	return (new);
// }

// static void	del_it(void *content)
// {
// 	free(content);
// }

// int	main(int argc, char **argv)
// {
// 	char	*content;
// 	t_node	*ptr;

// 	if (argc < 2)
// 		return(printf("incorrect # of arguments\n"), 1);
// 	content = argv[1];
// 	ptr = ft_lstnew(content);
// 	printf("ft_lstnew:\ncontent: %s\nnode: %s\n",
// 			content, (char *)ptr->content);
// 	ft_lstclear(&ptr, del);
// 	return (0);
// }
