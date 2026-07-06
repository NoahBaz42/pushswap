/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpassos- <bpassos-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 20:44:48 by bpassos-          #+#    #+#             */
/*   Updated: 2026/07/06 04:55:11 by bpassos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

// static int	ft_atoi_rec(const char *nptr, int n)
// {
// 	int	output;

// 	output = (n * 10) + (*nptr - 48);
// 	if (!*(nptr + 1) || !ft_isdigit(*nptr))
// 		return (output);
// 	return (ft_atoi_rec(nptr + 1, output));
// }

// int	ft_atoi__(const char *nptr)
// {
// 	int	i;
// 	int	sign;

// 	i = 0;
// 	sign = 1;
// 	while (nptr[i] == ' ')
// 		i++;
// 	if (nptr[i] == '+' || nptr[i] == '-')
// 	{
// 		if (nptr[i] == '-')
// 			sign = sign * -1;
// 		i++;
// 	}
// 	return (ft_atoi_rec(nptr + i, 0) * sign);
// }

int	ft_atoi(const char *nptr)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign = sign * -1;
		i++;
	}
	while (nptr[i] && nptr[i] >= '0' && nptr[i] <= '9')
	{
		result *= 10;
		result += nptr[i] - 48;
		i++;
	}
	return (result * sign);
}

// static void	print_test(char *name, const char *nptr, int ptr)
// {
// 	printf("\n%s\nstring: %s\nint: %d\n",
// 		name,
// 		nptr,
// 		ptr);
// }

// int	main(int argc,char **argv)
// {
// 	const char	*nptr;
// 	int	ptr;
// 	int	ft_ptr;

// 	if (argc < 2)
// 		return (printf("incorrect # of arguments\n"));
// 	nptr = argv[1];
// 	ptr = atoi(nptr);
// 	ft_ptr = ft_atoi__(nptr);
// 	print_test("ft_atoi:", nptr, ft_ptr);
// 	print_test("atoi:", nptr, ptr);
// 	return (0);
// }
