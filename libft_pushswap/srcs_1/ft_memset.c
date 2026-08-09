/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpassos- <bpassos-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 19:13:37 by bpassos-          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2026/07/16 08:08:39 by bpassos-         ###   ########.fr       */
=======
/*   Updated: 2026/07/06 04:55:11 by bpassos-         ###   ########.fr       */
>>>>>>> noah_parsing
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
<<<<<<< HEAD
=======
#include <stdio.h>
#include <string.h>
>>>>>>> noah_parsing

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *)s;
	while (i < n)
	{
		str[i] = c;
		i++;
	}
	return (str);
}

<<<<<<< HEAD
void	*ft_membreak(void *s, int c, size_t n)
{
	size_t			i;
	unsigned int	*str;

	i = 0;
	str = (unsigned int *)s;
	while (i < n)
	{
		str[i] = c;
		i++;
	}
	return (str);
}

=======
>>>>>>> noah_parsing
// static void	print_test(char *name, char *str,
// 				char c, size_t n, void *ptr)
// {
// 	printf("\n%s\nstr: %s\nc: '%c' (%d)\nn: %zu\nfound @ %p (%s)\n",
// 		name,
// 		str,
// 		c, c,
// 		n,
// 		ptr, (char *)ptr);
// }str

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
// 	ptr = memset(str, c, n);
// 	ft_ptr = ft_memset(str, c, n);
// 	print_test("FT_MEMCHR", str, c, n, ft_ptr);
// 	print_test("MEMCHR", str, c, n, ptr);
// 	return (0);
// }
