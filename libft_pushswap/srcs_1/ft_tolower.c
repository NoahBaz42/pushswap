/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpassos- <bpassos-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 19:13:57 by bpassos-          #+#    #+#             */
/*   Updated: 2026/07/06 04:55:12 by bpassos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_tolower(int c)
{
	int	lower;

	lower = 0;
	if (c >= 'A' && c <= 'Z')
	{
		lower = c + CASE_DIFF;
		return (lower);
	}
	return (c);
}

// static void	print_test(char *name, int c, int func)
// {
// 	printf("\n%s\ninput_upper_character: %d\noutput_lower_character %d\n",
// 		name,
// 		c,
// 		func);
// }

// int	main(int argc,char **argv)
// {
// 	int c;
// 	int	ptr;
// 	int	ft_ptr;

// 	if (argc > 2)
// 		return (printf("incorrect # of arguments\n"));
// 	c = ft_atoi(argv[1]);
// 	ptr = tolower(c);
// 	ft_ptr = ft_tolower(c);
// 	print_test("ft_tolower:", c, ft_ptr);
// 	print_test("tolower:", c, ptr);
// 	return (0);
// }
