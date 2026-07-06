/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpassos- <bpassos-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 19:15:09 by bpassos-          #+#    #+#             */
/*   Updated: 2026/07/06 04:55:11 by bpassos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *)s;
	while (i < n)
	{
		str[i] = 0;
		i++;
	}
}

// static void	print_test(char *name, char *str, size_t n)
// {
// 	printf("\n%s\nstr: %s\nn: %zu\n",
// 		name,
// 		str,
// 		n);
// 		// ptr, (char *)ptr);
// }

// int	main(int argc, char **argv)
// {
// 	// char	*ptr;
// 	// char	*ft_ptr;
// 	char	*str;
// 	char	*str1;
// 	size_t	n;

// 	if (argc < 2)
// 		return (printf("incorrect # of arguments\n"), 1);
// 	str = strdup(argv[1]);
// 	str1 = strdup(argv[1]);
// 	n = ft_strlen(argv[1]);
// 	if (argv[2])
// 		n = atoi(argv[2]);
// 	bzero(str, n);
// 	ft_bzero(str1, n);
// 	print_test("ft_bzero", str1, n);
// 	print_test("bzero", str, n);
// 	return (0);
// }

// int	main(int argc, char **argv)
// {
// 	char	*str;
// 	// char	*str1;
// 	size_t	n;

// 	if (argc != 2)
// 		return (printf("incorrect # of arguments\n"), 1);
// 	str = strdup(argv[1]);
// 	n = strlen(str);
// 	printf("arg:\n%s\n---\n", str);
// 	ft_bzero(str, n);
// 	printf("arg after zero:\n%s\n", str);

// 	return (0);
// }