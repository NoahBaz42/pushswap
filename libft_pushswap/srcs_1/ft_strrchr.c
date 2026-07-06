/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpassos- <bpassos-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 15:16:22 by bpassos-          #+#    #+#             */
/*   Updated: 2026/07/06 04:55:11 by bpassos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	ch;

	ch = (char)c;
	i = ft_strlen(s);
	while (i >= 0 && s[i] != ch)
		i--;
	if (i < 0)
		return (NULL);
	return ((char *)s + i);
}

// static void	ft_print_test(char *name, int len,
// 					const char *str, int c, void *ptr)
// {
// 	printf("\n%s\nlen: %d\nstr: %s\nc: '%c' (%d)\nptr: %p (%s)\n\n",
// 		name,
// 		len,
// 		str,
// 		c,
// 		c,
// 		ptr,
// 		(char *)ptr);
// }

// int	main(int argc, char **argv)
// {
// 	char		*str;
// 	char		c;
// 	char		*ft_ptr;
// 	char		*ptr;
// 	int			len;

// 	if (argc < 3)
// 		return (printf("incorrect # of arguments\n"));
// 	str = argv[1];
// 	c = *argv[2];
// 	if (!strcmp(argv[2], "NULL"))
// 		c = 0;

// 	len = ft_strlen(str);
// 	ft_ptr = ft_strrchr(str, c);
// 	ptr = strrchr(str, c);
// 	ft_print_test("ft_strrchr:", len, str, c, ft_ptr);
// 	ft_print_test("strrchr:", len, str, c, ptr);
// 	return (0);
// }
