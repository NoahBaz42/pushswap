/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charlie <charlie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 21:55:39 by bpassos-          #+#    #+#             */
/*   Updated: 2026/08/09 02:30:00 by charlie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_allocate(int n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		i = 1;
		n = -n;
	}
	while (n >= 10)
	{
		n = n / 10;
		i++;
	}
	return (++i);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		i;

	if (n == INT_MIN)
		return (ft_strdup("-2147483648"));
	i = ft_allocate(n);
	str = malloc((sizeof(char) * (i + 1)));
	if (!str)
		return (NULL);
	str[i--] = '\0';
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	while (str[i] != '-' && i >= 0)
	{
		str[i--] = (n % 10) + 48;
		n = n / 10;
	}
	return (str);
}

// int	main(int argc, char **argv)
// {
// 	int		n;
// 	char	*str;

// 	n = 0;
// 	if (argc < 2)
// 		return (printf("incorrect # of arguments\n"), 1);
// 	if (!strcmp(argv[1], "INT_MAX"))
// 		n = INT_MAX;
// 	else if (!strcmp(argv[1], "INT_MIN"))
// 		n = INT_MIN;
// 	else
// 		n = atoi(argv[1]);
// 	str = ft_itoa(n);
// 	printf("\n\nft_itoa: The integer [%d] is now a string '%s'\n\n", n, str);
// 	free(str);
// 	return (0);
// }
