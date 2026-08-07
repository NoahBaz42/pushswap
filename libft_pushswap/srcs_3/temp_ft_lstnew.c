/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   temp_ft_lstnew.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpassos- <bpassos-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 21:56:27 by bpassos-          #+#    #+#             */
/*   Updated: 2026/08/03 22:51:29 by bpassos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_list	*ft_newlst(t_node *root)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->root = root;
	// new->root->prev = NULL;
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
