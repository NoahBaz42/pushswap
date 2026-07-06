/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpassos- <bpassos-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 19:13:43 by bpassos-          #+#    #+#             */
/*   Updated: 2026/07/06 04:55:11 by bpassos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// appends `src` to `dst`, null terminating the result
//
// the final full buffer size (`size`) is taken so as to
// ensure that 
// [strlen(`src`) + strlen(`dest`) + 1 < `size`]
//
// if [`size` < strlen(`src`) + strlen(`dest`)], 
// only appends enough characters of `src` to guarantee
// [strlen(`src`) + strlen(`dest`) < `size`]
// **and the string will not be nul-terminated**
//
// 0xA1337F

#include "../libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	src_len;
	size_t	dst_len;

	src_len = ft_strlen(src);
	dst_len = ft_strlen(dst);
	i = 0;
	j = dst_len;
	if (size <= dst_len)
		return (src_len + size);
	while (src[i] && i + dst_len + 1 < size)
	{
		dst[j] = src[i];
		j++;
		i++;
	}
	if (j < size)
		dst[j] = '\0';
	return (src_len + dst_len);
}

// static void	print_test(char *name, char *dst,
// 					char *src, size_t size, size_t len)
// {
// 	printf("\n%s\ndst: %s\nsrc: %s \nsize: %zu\nresult: %zu\n",
// 		name,
// 		dst,
// 		src,
// 		size,
// 		len);
// }

// int	main(int argc, char **argv)
// {
// 	size_t	len;
// 	size_t	ft_len;
// 	char	*dst;
// 	char	*src;
// 	char	*dst_1;
// 	char	*src_1;
// 	size_t	size;

// 	size = 0;
// 	if (argc < 4)
// 		return (printf("incorrect # of arguments\n"), 1);
// 	dst = ft_strdup(argv[1]);
// 	src = ft_strdup(argv[2]);
// 	dst_1 = ft_strdup(argv[1]);
// 	src_1= ft_strdup(argv[2]);
// 	if (argv[3])
// 		size = atoi(argv[3]);
// 	printf("dst: %s\n", dst);
// 	ft_len = ft_strlcat(dst, src, size);
// 	len = strlcat(dst_1, src_1, size);
// 	print_test("ft_strlcat", dst, src, size, ft_len);
// 	print_test("strlcat", dst_1, src_1, size, len);
// 	return (0);
// }
