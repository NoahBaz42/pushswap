/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charlie <charlie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 19:12:18 by bpassos-          #+#    #+#             */
/*   Updated: 2026/08/09 02:26:51 by charlie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
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
// 		printf("----------------------\n");
// 		print_test("ft_isalpha:", c, ft_int);
// 		print_test("isalpha:", c, o_int);
// 		c++;
// 	}
// 	return (0);
// }
