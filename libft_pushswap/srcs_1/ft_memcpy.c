/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpassos- <bpassos-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 19:13:35 by bpassos-          #+#    #+#             */
/*   Updated: 2026/07/06 04:55:11 by bpassos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*dest_str;
	const unsigned char	*src_str;

	i = 0;
	dest_str = (unsigned char *)dest;
	src_str = (const unsigned char *)src;
	while (i < n)
	{
		dest_str[i] = src_str[i];
		i++;
	}
	return (dest_str);
}

// #include <string.h>
// #include <stdio.h>

// static void	print_test(char *name, char *dest,
// 				char *src, size_t n, void *ptr)
// {
// 	printf("\n%s\ndest: %s\nsrc: %s \nn: %zu\nfound @ %p (%s)\n",
// 		name,
// 		dest,
// 		src,
// 		n,
// 		ptr, (char *)ptr);
// }

// int	main(int argc, char **argv)
// {
// 	void	*ptr;
// 	void	*ft_ptr;
// 	char	*dest;
// 	char	*src;
// 	size_t	n;

// 	if (argc < 4)
// 		return (printf("incorrect # of arguments\n"), 1);
// 	dest = argv[1];
// 	src = argv[2];
// 	n = ft_strlen(src);
// 	if (argv[3])
// 		n = atoi(argv[3]);
// 	ft_ptr = ft_memcpy(dest, src, n);
// 	ptr = memcpy(dest, src, n);
// 	print_test("ft_memcpy", dest, src, n, ft_ptr);
// 	print_test("memcpy", dest, src, n, ptr);
// 	return (0);
// }
