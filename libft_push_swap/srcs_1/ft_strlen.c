/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charlie <charlie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 20:59:47 by bpassos-          #+#    #+#             */
/*   Updated: 2026/08/09 02:29:08 by charlie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

// static void	print_test(char *name, const char *str, size_t func)
// {
// 	printf("\n%s\nstr: %s\nlength: %zu\n",
// 		name,
// 		str,
// 		func);
// }

// int	main(int argc, char  **argv)
// {
// 	const char	*s;
// 	size_t		ft;
// 	size_t		og;

// 	if (argc < 2)
// 		return (printf("incorrect # of arguments\n"), 1);
// 	s = argv[1];
// 	ft = ft_strlen(s);
// 	og = strlen(s);
// 	print_test("ft_strlen:", s, ft);
// 	print_test("strlen:", s, og);
// }
