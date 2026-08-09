/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: charlie <charlie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 21:56:30 by bpassos-          #+#    #+#             */
/*   Updated: 2026/08/06 19:05:47 by charlie          ###   ########.fr       */
=======
/*   By: bpassos- <bpassos-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 21:56:30 by bpassos-          #+#    #+#             */
/*   Updated: 2026/07/06 04:55:11 by bpassos-         ###   ########.fr       */
>>>>>>> noah_parsing
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

<<<<<<< HEAD
size_t	ft_lstsize(t_node *lst)
=======
int	ft_lstsize(t_node *lst)
>>>>>>> noah_parsing
{
	int	size;

	if (!lst)
		return (0);
	size = 0;
	while (lst)
	{
		lst = lst->next;
		size++;
	}
	return (size);
}

// static void	del_it(void *content)
// {
// 	free(content);
// }

// int main (int argc, char **argv)
// {
// 	int x;
// 	int	i;
// 	t_node *lst;
// 	t_node *node;

// 	i = 2;
// 	(void)argv;
// 	if (argc < 2)
// 		return (printf("incorrect # of arguments\n"), 1);
// 	x = ft_atoi(argv[1]);
// 	lst = ft_lstnew(&x);
// 	node = lst;
// 	while (i < argc && node)
// 	{
// 		x = ft_atoi(argv[i]);
// 		node->next = ft_lstnew(&x);
// 		node = node->next;
// 		i++;
// 	}
// 	printf("%d\n", ft_lstsize(lst));
// 	ft_lstclear(&lst, del);
// 	return (0);
// }