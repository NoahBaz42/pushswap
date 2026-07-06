/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpassos- <bpassos-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 19:12:46 by bpassos-          #+#    #+#             */
/*   Updated: 2026/07/06 04:55:11 by bpassos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

// static void	print_test(char *name, char c, int true)
// {
// 	printf("\n%s\nis the character: %d (%c)\nalpha: %d\n",
// 		name,
// 		c,
// 		c,
// 		true);
// }

// int	main(void)
// {
// 	int		ft_int;
// 	int		o_int;
// 	int		c;

// 	c = 0;
// 	while (c < 100)
// 	{
// 		ft_int = ft_isalpha(c);
// 		o_int = isalpha(c);
//		printf("----------------------\n");
// 		print_test("ft_isdigit:", c, ft_int);
// 		print_test("isdigit:", c, o_int);
// 		c++;
// 	}
// 	return (0);
// }
