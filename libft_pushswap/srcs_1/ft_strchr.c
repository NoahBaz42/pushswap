/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charlie <charlie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 19:13:40 by bpassos-          #+#    #+#             */
/*   Updated: 2026/08/09 02:28:05 by charlie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	ch;

	ch = (char)c;
	i = 0;
	while (s[i] && s[i] != ch)
		i++;
	if (s[i] == ch)
		return ((char *)s + i);
	return (0);
}

// static void	ft_print_test(char *name, int len,
// 				const char *str, int c, void *ptr)
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
// 	ft_ptr = ft_strchr(str, c);
// 	ptr = strchr(str, c);
// 	ft_print_test("ft_strchr:", len, str, c, ft_ptr);
// 	ft_print_test("strchr:", len, str, c, ptr);
// 	return (0);
// }
