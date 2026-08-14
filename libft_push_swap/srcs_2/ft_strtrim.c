/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpassos- <bpassos-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 21:56:02 by bpassos-          #+#    #+#             */
/*   Updated: 2026/07/16 08:07:49 by bpassos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_cmp(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i++] == c)
			return (1);
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	start;
	size_t	end;

	start = 0;
	end = ft_strlen(s1);
	while (s1[start] && ft_cmp(s1[start], set))
		start++;
	while (end > 0 && s1[end - 1] && ft_cmp(s1[end - 1], set))
		end--;
	if (start > end)
		return (ft_strdup(""));
	str = malloc(sizeof(char) * (end - start + 1));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1 + start, end - start + 1);
	return (str);
}

// int main(void)
// {
// 	char *s1 = "  \t \t \n   \n\n\n\t";
//  	char *s2 = "";
//  	char *ret = ft_strtrim(s1, " \n\t");
//  	if (!strcmp(ret, s2))
//  		exit(0);
//  	exit(1);
// }

// int	main(int argc, char **argv)
// {
// 	const char	*str;
// 	const char	*set;

// 	if (argc < 2)
// 		return (printf("Incorrect # of arguments\n"), 1);
// 	str = argv[1];
// 	set = argv[2];
// 	printf("\nft_strtrim\nOriginal string:%s\nsetstr:
// %s\ntrimstr: %s\n", str, set, ft_strtrim(str, set));
// 	return (0);
// }
