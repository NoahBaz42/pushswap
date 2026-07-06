/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpassos- <bpassos-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 19:15:12 by bpassos-          #+#    #+#             */
/*   Updated: 2026/07/06 04:55:11 by bpassos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
	{
		return (1);
	}
	return (0);
}

// int	main (void)
// {
// 	int i = 0;
// 	while (i <= 100)
// 	{
//		printf("----------------------\n");
// 		printf("the character %c, %d, is %d\n", i, i, ft_isprint(i));
// 		printf("the character %c, %d, is %d\n", i, i, isprint(i));
// 		i++;
// 	}
// 	return (0);
// }