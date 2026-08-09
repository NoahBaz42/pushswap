/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: charlie <charlie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 19:15:12 by bpassos-          #+#    #+#             */
/*   Updated: 2026/08/08 23:24:45 by charlie          ###   ########.fr       */
=======
<<<<<<<< HEAD:flags.c
<<<<<<<< HEAD:libft_pushswap/srcs_1/ft_isprint.c
/*   By: bpassos- <bpassos-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 19:15:12 by bpassos-          #+#    #+#             */
/*   Updated: 2026/07/16 08:08:18 by bpassos-         ###   ########.fr       */
========
/*   By: nbaz-sil <nbaz-sil@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 19:44:11 by noah-baz          #+#    #+#             */
/*   Updated: 2026/07/02 23:13:39 by nbaz-sil         ###   ########.fr       */
>>>>>>>> noah_parsing:flags.c
========
/*   By: bpassos- <bpassos-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 19:15:12 by bpassos-          #+#    #+#             */
/*   Updated: 2026/07/06 04:55:11 by bpassos-         ###   ########.fr       */
>>>>>>>> noah_parsing:libft_pushswap/srcs_1/ft_isprint.c
>>>>>>> noah_parsing
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

<<<<<<< HEAD
=======
<<<<<<<< HEAD:flags.c
<<<<<<<< HEAD:libft_pushswap/srcs_1/ft_isprint.c
>>>>>>> noah_parsing
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
<<<<<<< HEAD
=======
========

/* void flag_checker(int argc, char **argv)
{
    
} */
>>>>>>>> noah_parsing:flags.c
========
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
>>>>>>>> noah_parsing:libft_pushswap/srcs_1/ft_isprint.c
>>>>>>> noah_parsing
