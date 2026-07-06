/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpassos- <bpassos-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 15:16:30 by bpassos-          #+#    #+#             */
/*   Updated: 2026/07/06 04:55:11 by bpassos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strdup(const char *src)
{
	int		i;
	char	*new;

	i = 0;
	new = malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (!new)
		return (NULL);
	while (*src)
		new[i++] = *src++;
	new[i] = '\0';
	return (new);
}

// static void	print_test(char *name,
// 					const char *str, char *func)
// {
// 	printf("\n%s\nstr: %s\nstring: %s\nlocated in: (%p)",
// 		name,
// 		str,
// 		func, func);
// }

// int	main(int argc, char  **argv)
// {
// 	char	*s;
// 	char	*ft_ptr;
// 	char	*ptr;

// 	if (argc < 2)
// 		return (printf("incorrect # of arguments\n"), 1);
// 	s = argv[1];
// 	ft_ptr = ft_strdup(s);
// 	ptr = strdup(s);
// 	print_test("ft_strdup:", s, ft_ptr);
// 	print_test("strdup:", s, ptr);
//	free(ft_ptr);
//	free(ptr);
//	return (0);
// }