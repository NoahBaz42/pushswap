/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaz-sil <nbaz-sil@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 21:56:27 by bpassos-          #+#    #+#             */
/*   Updated: 2026/08/07 05:40:00 by nbaz-sil         ###   ########.fr       */
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
