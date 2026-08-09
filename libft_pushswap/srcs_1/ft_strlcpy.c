/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charlie <charlie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 15:16:34 by bpassos-          #+#    #+#             */
/*   Updated: 2026/08/09 02:29:02 by charlie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (src[i] && i + 1 < size)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}

// int	main(int argc, char **argv)
// {
// 	char	dst[1024] = {0};
// 	size_t	n;
// 	size_t	ft_len;
// 	size_t	len;

// 	if (argc < 2)
// 	{
// 		printf("not enough arguments\n");
// 		return (1);
// 	}
// 	n = ft_strlen(argv[1]) + 1;
// 	if (argc == 3)
// 		n = atoi(argv[2]);
// 	printf("len: %zu\n\n", n);
// 	ft_len = ft_strlcpy(dst, argv[1], n);
// 	len = strlcpy(dst, argv[1], n);
// 	printf("\nFT_STRLEN\nsrc:  %s\ndest: %s\nlen:%zu\n",
// 		argv[1], dst, ft_len);
// 	printf("\nSTRLEN\nsrc:  %s\ndest: %s\nlen:%zu\n",
// 		argv[1], dst, len);
// 	return (0);
// }
