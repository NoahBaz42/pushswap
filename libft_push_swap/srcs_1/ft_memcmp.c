/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charlie <charlie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 14:04:21 by bpassos-          #+#    #+#             */
/*   Updated: 2026/08/09 02:27:21 by charlie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	const u_char	*str1;
	const u_char	*str2;

	str1 = (const u_char *)s1;
	str2 = (const u_char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (str1[i] == str2[i] && i + 1 < n)
		i++;
	return (str1[i] - str2[i]);
}

// static void	print_test(char *name, const char *str,
// 					const char *str2, size_t n, int func)
// {
// 	printf("\n%s\nfirst_str: %s\nsecond_str:
// 			%s\nn: %zu\nstr comaprison: %d\n",
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
// 	ptr = memcmp(s1, s2, n);
// 	print_test("ft_memcmp:", s1, s2, n, ft_ptr);
// 	print_test("memcmp:", s1, s2, n, ptr);
// }