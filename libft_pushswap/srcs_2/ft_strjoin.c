/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charlie <charlie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 21:55:57 by bpassos-          #+#    #+#             */
/*   Updated: 2026/08/09 02:30:17 by charlie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	size;
	char	*str;

	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	str = ft_calloc(sizeof(char), size);
	if (!str)
		return (NULL);
	i = ft_strlcpy(str, s1, ft_strlen(s1) + 1);
	ft_strlcpy(str + i, s2, ft_strlen(s2) + 1);
	return (str);
}

// int	main(int argc, char **argv)
// {
// 	char const	*s1;
// 	char const	*s2;
// 	char 		*str;

// 	if (argc < 3)
// 		return(printf("incorrect # of arguments\n"), 1);
// 	s1 = argv[1];
// 	s2 = argv[2];
// 	str = ft_strjoin(s1, s2);
// 	printf("\n\nft_strjoin:\ns1: '%s'\ns2: '%s'\nstr: '%s'\n",
// 				s1, s2, str);
// 	free(str);
// 	return (0);
// }
