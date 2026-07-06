/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpassos- <bpassos-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 19:14:00 by bpassos-          #+#    #+#             */
/*   Updated: 2026/07/06 04:55:12 by bpassos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_toupper(int c)
{
	int	upper;

	upper = 0;
	if (c >= 'a' && c <= 'z')
	{
		upper = c - CASE_DIFF;
		return (upper);
	}
	return (c);
}

// static void	print_test(char *name, int c, int func)
// {
// 	printf("\n%s\ninput_lower_character: %d\noutput_upper_character %d\n",
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
// 	ptr = toupper(c);
// 	ft_ptr = ft_toupper(c);
// 	print_test("ft_toupper:", c, ft_ptr);
// 	print_test("toupper:", c, ptr);
// 	return (0);
// }
