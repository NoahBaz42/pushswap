/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpassos- <bpassos-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 21:56:05 by bpassos-          #+#    #+#             */
/*   Updated: 2026/07/16 08:07:52 by bpassos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	lensub;
	char	*str;

	i = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	lensub = ft_strlen(s) - start;
	if (len < lensub)
		lensub = len;
	str = malloc(sizeof(char) * (lensub + 1));
	if (!str)
		return (NULL);
	while (s[i] && i < lensub)
	{
		str[i] = s[i + start];
		i++;
	}
	str[i] = '\0';
	return (str);
}

// static void	ft_print_test(char const *name, char const *s,
// 					unsigned int start, size_t len, char	*ptr)
// {
// 	printf("\n%s\nstring s: %s\nstart: %d\nlen: %zu\npointer %p (%s)\n",
// 		name,
// 		s,
// 		start,
// 		len,
// 		ptr,
// 		ptr);
// }

// int	main(int argc, char **argv)
// {
// 	char	*ptr;
// 	char	*s;
// 	int		start;
// 	size_t	len;

// 	if (argc < 4)
// 		return (printf("incorrect # of arguments\n"), 1);
// 	s = argv[1];
// 	start = atoi(argv[2]);
// 	len = atoi(argv[3]);
// 	ptr = ft_substr(s, start, len);
// 	ft_print_test("ft_substr:", s, start, len, ptr);
// 	free(ptr);
// }
