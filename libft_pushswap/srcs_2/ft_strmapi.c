/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charlie <charlie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 21:55:59 by bpassos-          #+#    #+#             */
/*   Updated: 2026/08/09 02:30:21 by charlie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	int		i;

	str = ft_strdup(s);
	if (!str || !f)
		return (NULL);
	i = -1;
	while (str[++i])
		str[i] = f(i, s[i]);
	return (str);
}

// static char	ft_putb(unsigned int i, char c)
// {
// 	return (c + i);
// }

// int	main(int argc, char **argv)
// {
// 	char	*str;

// 	if (argc < 2)
// 		return (printf("Incorrect # of arguments\n"), 1);
// 	str = argv[1];
// 	printf("\n%s\n", ft_strmapi(str, ft_putb));
// 	return (0);
// }
