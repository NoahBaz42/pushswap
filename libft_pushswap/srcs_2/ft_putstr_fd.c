/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
<<<<<<< HEAD
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charlie <charlie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
<<<<<<<< HEAD:libft_pushswap/srcs_2/ft_putstr_fd.c
/*   Created: 2026/04/29 21:55:50 by bpassos-          #+#    #+#             */
/*   Updated: 2026/08/08 23:15:28 by charlie          ###   ########.fr       */
========
/*   Created: 2026/06/30 19:26:22 by noah-baz          #+#    #+#             */
/*   Updated: 2026/08/07 04:43:19 by nbaz-sil         ###   ########.fr       */
>>>>>>>> noah_parsing:push_swap_utils.c
=======
<<<<<<<< HEAD:nodes.c
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpassos- <bpassos-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 21:55:45 by bpassos-          #+#    #+#             */
/*   Updated: 2026/07/16 08:07:27 by bpassos-         ###   ########.fr       */
========
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpassos- <bpassos-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 21:55:50 by bpassos-          #+#    #+#             */
/*   Updated: 2026/07/06 04:55:12 by bpassos-         ###   ########.fr       */
>>>>>>>> noah_parsing:libft_pushswap/srcs_2/ft_putstr_fd.c
>>>>>>> noah_parsing
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

<<<<<<< HEAD
<<<<<<<< HEAD:libft_pushswap/srcs_2/ft_putstr_fd.c
=======
<<<<<<<< HEAD:nodes.c
void	ft_putendl_fd(char *s, int fd)
{
	if (!s)
		return ;
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}

// int	main(int argc, char **argv)
// {
// 	char	*s;
// 	int		fd;

// 	if (argc < 3)
// 		return (printf("incorrect # of arguments\n"));
// 	s = argv[1];
// 	fd = open(argv[2], O_RDWR | O_CREAT | O_APPEND);
========
>>>>>>> noah_parsing
void	ft_putstr_fd(char *s, int fd)
{
	size_t	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
		ft_putchar_fd(s[i++], fd);
}

// int	main(int argc, char **argv)
// {
// 	char	*s;
// 	int		fd;

// 	if (argc < 3)
// 		return (printf("incorrect # of arguments\n"));
// 	s = argv[1];
// 	fd = atoi(argv[2]);
<<<<<<< HEAD
// 	ft_putendl_fd(s, fd);
// }
========

>>>>>>>> noah_parsing:push_swap_utils.c
=======
>>>>>>>> noah_parsing:libft_pushswap/srcs_2/ft_putstr_fd.c
// 	ft_putendl_fd(s, fd);
// }
>>>>>>> noah_parsing
