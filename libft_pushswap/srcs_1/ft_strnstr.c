/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpassos- <bpassos-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 19:13:50 by bpassos-          #+#    #+#             */
/*   Updated: 2026/07/06 04:55:11 by bpassos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdio.h>
#include <string.h>

// char *str = "hello"
// ft_strnstr(str, str, strlen(str))

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;

	i = 0;
	if (!*little)
		return ((char *)big);
	while (big[i] && i < len)
	{
		if (ft_strncmp(big + i, little, ft_strlen(little)) == 0
			&& len - i >= ft_strlen(little))
			return ((char *)big + i);
		i++;
	}
	return (NULL);
}
// int main(void)
// {
// 	char *x;
// 	char *y;
// 	char *str1;
// 	char *str2;
// 	str1 = strdup("sphynx");
// 	str2 = strdup("sphynx");
// 	x = strnstr(str1, str2, strlen("sphynx"));
// 	y = ft_strnstr(str1, str2, strlen("sphynx"));
// 	if (x != y)
// 		return (printf("error\n"));
// 	return (printf("success\n"));
// }

// static void	print_test(char *name, const char *str,
// 			const char *substr, size_t len, char *func)
// {
// 	printf("\n%s\n\nstring: %s\nsubstring: %s\nlen: %zu\nfound_string: %s",
// 		name,
// 		str,
// 		substr,
// 		len,
// 		func);
// }

// int	main(int argc, char  **argv)
// {
// 	char	*str;
// 	char	*substr;
// 	size_t	len;
// 	char	*ft_ptr;
// 	char	*ptr;

// 	if (argc < 3)
// 		return (printf("incorrect # of arguments\n"), 1);
// 	str = argv[1];
// 	substr = argv[2];
// 	len = ft_atoi(argv[3]);
// 	if (!argv[3])
// 		len = ft_strlen(str);
// 	ft_ptr = ft_strdup(str);
// 	ptr = strdup(str);
// 	print_test("ft_strnstr:", str, substr, len, ft_ptr);
// 	print_test("strnstr:", str, substr, len, ptr);
// }
