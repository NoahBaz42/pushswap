/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charlie <charlie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 21:55:55 by bpassos-          #+#    #+#             */
/*   Updated: 2026/08/09 02:30:14 by charlie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int	i;

	i = -1;
	if (!s || !f)
		return ;
	while (s[++i])
		f(i, &s[i]);
}

// static	void	ft_putc(unsigned int i, char *str)
// {
// 	while(str[i])
// 	{
// 		if (str[i] == ' ')
// 			i++;
// 		str[i] = 'c';
// 		i++;
// 	}
// }

// int main(int argc, char **argv)
// {
// 	char	*og;
// 	char	*new;

// 	if (argc < 2)
// 		return(printf("incorrect # of arguments\n"), 1);
// 	og = argv[1];
// 	new = ft_strdup(argv[1]);
// 	ft_striteri(new, &ft_putc);
// 	printf("ft_striteri:\noriginal str: %s\nnew str: %s\n", og, new);
// 	return (0);

// }