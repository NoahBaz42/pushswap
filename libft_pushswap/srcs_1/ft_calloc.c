/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpassos- <bpassos-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 14:47:24 by bpassos-          #+#    #+#             */
/*   Updated: 2026/07/06 04:55:11 by bpassos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (size == 0 || nmemb == 0)
		return (malloc(0));
	if (nmemb > ULONG_MAX / size)
		return (NULL);
	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, size * nmemb);
	return (ptr);
}

// static	void ft_print_test(char *name, size_t nmeb,
// 					size_t size, void *ptr)
// {
// 	printf("\n\n%s\nnumber of elements:
// 				%zu\nsize of the emelents: %zu\narray: %p (%s)\n",
// 		name,
// 		nmeb,
// 		size,
// 		ptr,
// 		(char *)ptr);
// }

// int	main(int argc, char **argv)
// {
// 	void	*ft_ptr;
// 	void	*ptr;
// 	size_t	nmeb;
// 	size_t	size;

// 	if (argc < 3)
// 		return (printf("incorrect # of arguments\n"), 1);
// 	nmeb = atoi(argv[1]);
// 	size = atoi(argv[2]);
// 	ft_ptr = ft_calloc(nmeb, size);
// 	ptr = calloc(nmeb, size);
// 	ft_print_test("ft_calloc:", nmeb, size, ft_ptr);
// 	ft_print_test("calloc:", nmeb, size, ptr);
// 	free(ft_ptr);
// 	free(ptr);
// 	return (0);
// }
