/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpassos- <bpassos-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 19:13:47 by bpassos-          #+#    #+#             */
/*   Updated: 2026/07/06 04:55:11 by bpassos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stddef.h>

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
