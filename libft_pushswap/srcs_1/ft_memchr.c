/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charlie <charlie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 19:13:27 by bpassos-          #+#    #+#             */
/*   Updated: 2026/08/09 02:27:00 by charlie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;
	void			*ptr;

	i = 0;
	str = (unsigned char *)s;
	if (n == 0)
		return (NULL);
	while (str[i] != (unsigned char)c && i + 1 < n)
		i++;
	if (str[i] != (unsigned char)c)
		return (NULL);
	ptr = &str[i];
	return (ptr);
}

// static void	print_test(char *name, char *str, char c, size_t n, void *ptr)
// {
// 	printf("\n%s\nstr: %s\nc: '%c' (%d)\nn: %zu\nfound @ %p (%s)\n",
// 		name,
// 		str,
// 		c, c,
// 		n,
// 		ptr, (char *)ptr);
// }

// int	main(int argc, char **argv)
// {
// 	void	*ptr;
// 	void	*ft_ptr;
// 	char	*str;
// 	char	c;
// 	size_t	n;

// 	if (argc < 3)
// 		return (printf("incorrect # of arguments\n"), 1);
// 	str = argv[1];
// 	c = *argv[2];
// 	if (!strcmp(argv[2], "NULL"))
// 		c = '\0';
// 	n = strlen(str);
// 	if (argv[3])
// 		n = atoi(argv[3]);
// 	ptr = memchr(str, c, n);
// 	ft_ptr = ft_memchr(str, c, n);
// 	print_test("FT_MEMCHR", str, c, n, ft_ptr);
// 	print_test("MEMCHR", str, c, n, ptr);
// 	return (0);
// }
