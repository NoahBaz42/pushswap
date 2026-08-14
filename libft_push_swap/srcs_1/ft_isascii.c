/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charlie <charlie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 19:12:41 by bpassos-          #+#    #+#             */
/*   Updated: 2026/08/09 02:26:53 by charlie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_isascii(int c)
{
	return ((((c) & ~0x7f) == 0));
}

// static void	print_test(char *name, char c, int true)
// {
// 	printf("\n%s\nis the character: %d (%c)\nascii: %d\n",
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

// 	c = 100;
// 	while (c < 200)
// 	{
// 		ft_int = ft_isascii(c);
// 		o_int = isascii(c);
// 		printf("----------------------\n");
// 		print_test("ft_isascii:", c, ft_int);
// 		print_test("isascii:", c, o_int);
// 		c++;
// 	}
// 	return (0);
// }
