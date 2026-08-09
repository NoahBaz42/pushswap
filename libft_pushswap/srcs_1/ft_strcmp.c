/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: bpassos- <bpassos-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 19:13:47 by bpassos-          #+#    #+#             */
/*   Updated: 2026/07/16 09:37:05 by bpassos-         ###   ########.fr       */
=======
/*   By: noah-baz <noah-baz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 19:13:47 by bpassos-          #+#    #+#             */
/*   Updated: 2026/07/09 04:50:31 by noah-baz         ###   ########.fr       */
>>>>>>> noah_parsing
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
<<<<<<< HEAD
=======
#include <stddef.h>
>>>>>>> noah_parsing

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while ((unsigned char *)s1
		&& (unsigned char)s1[i]
		&& (unsigned char)s1[i] == (unsigned char)s2[i]
		&& i + 1 < n)
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
<<<<<<< HEAD
=======


>>>>>>> noah_parsing
int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while ((unsigned char *)s1
		&& (unsigned char)s1[i]
		&& (unsigned char)s1[i] == (unsigned char)s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

<<<<<<< HEAD
=======
/* ft_strncmp test */
>>>>>>> noah_parsing
// static void	print_test(char *name, const char *str,
// 					const char *str2, size_t n, int func)
// {
// /* note: include backslash below */
// printf("\n%s\nfirst_str: %s\nsecond_str:
// %s\nn: %zu\nstr comaprison: %d\n",
// 		name,
// 		str,
// 		str2,
// 		n,
// 		func);
// }

// int	main(int argc, char  **argv)
// {
// 	char	*s1;
// 	char	*s2;
// 	size_t	n;
// 	int		ft_ptr;
// 	int 	ptr;

// 	if (argc < 4)
// 		return (printf("incorrect # of arguments\n"), 1);
// 	s1 = argv[1];
// 	s2 = argv[2];
// 	n = ft_atoi(argv[3]);
// 	ft_ptr = ft_strncmp(s1, s2, n);
// 	ptr = strncmp(s1, s2, n);
// 	print_test("ft_strncmp:", s1, s2, n, ft_ptr);
// 	print_test("strncmp:", s1, s2, n, ptr);
// }
<<<<<<< HEAD
=======

/* ft_strcmp test */
// static void	print_test(char *name, const char *str,
// 					const char *str2, int func)
// {
// /* note: include backslash below */
// printf("\n%s\nfirst_str: %s\nsecond_str:\
// %s\n\nstr comaprison: %d\n",
// 		name,
// 		str,
// 		str2,
// 		func);
// }

// int	main(int argc, char  **argv)
// {
// 	char	*s1;
// 	char	*s2;
// 	int		ft_ptr;
// 	int 	ptr;

// 	if (argc < 3)
// 		return (printf("incorrect # of arguments\n"), 1);
// 	s1 = argv[1];
// 	s2 = argv[2];
// 	ft_ptr = ft_strcmp(s1, s2);
// 	ptr = strcmp(s1, s2);
// 	print_test("ft_strcmp:", s1, s2, ft_ptr);
// 	print_test("strcmp:", s1, s2, ptr);
// }
>>>>>>> noah_parsing
