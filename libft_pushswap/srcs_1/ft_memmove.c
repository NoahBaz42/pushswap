/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charlie <charlie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 18:00:00 by bpassos-          #+#    #+#             */
/*   Updated: 2026/08/09 02:27:32 by charlie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

// void	*ft_memmove(void *dest, const void *src, size_t n)
// {
// 	unsigned char		*dest_ptr;
// 	const unsigned char	*src_ptr;
// 	size_t				i;

// 	dest_ptr = (unsigned char *) dest;
// 	src_ptr = (const unsigned char *) src;
// 	if (dest_ptr > src_ptr)
// 	{
// 		i = n;
// 		while (i-- > 0)
// 			dest_ptr[i] = src_ptr[i];
// 	}
// 	else
// 	{
// 		i = 0;
// 		while (i < n)
// 		{
// 			dest_ptr[i] = src_ptr[i];
// 			i++;
// 		}
// 	}
// 	return (dest);
// }

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*dest_str;
	const unsigned char	*src_str;

	i = 0;
	dest_str = (unsigned char *)dest;
	src_str = (const unsigned char *)src;
	if (src_str > dest_str)
		ft_memcpy(dest_str, src_str, n);
	else
	{
		i = n;
		while (i-- > 0)
			dest_str[i] = src_str[i];
	}
	return (dest_str);
}

// static void	print_test(char *name, char *dest,
// 				char *src, size_t n, void *ptr)
// {
// 	printf("\n%s\ndest: %s\nsrc: %s \nn: %zu\nfound @ %p (%s)\n",
// 		name,
// 		dest,
// 		src,
// 		n,
// 		ptr, (char *)ptr);
// }

// int	main(int argc, char **argv)
// {
// 	void	*ptr;
// 	void	*ft_ptr;
// 	char	*dest;
// 	char	*src;
// 	char	*dest1;
// 	char	*src1;
// 	size_t	n;

// 	if (argc < 2)
// 		return (printf("incorrect # of arguments\n"), 1);
// 	src = strdup(argv[1]);
// 	dest = src - 1;
// 	src1 = strdup(argv[1]);
// 	dest1 = src1 - 1;
// 	n = ft_strlen(argv[1]);
// 	if (argv[2])
// 		n = atoi(argv[2]);
// 	ptr = memmove(dest, src, n);
// 	ft_ptr = ft_memmove(dest1, src1, n);
// 	print_test("memmove", dest, src, n, ptr);
// 	print_test("ft_memmove", dest1, src1, n, ft_ptr);
// 	return (0);
// }
