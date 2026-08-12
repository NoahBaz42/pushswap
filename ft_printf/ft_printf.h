/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charlie <charlie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 16:47:47 by nbaz-sil          #+#    #+#             */
/*   Updated: 2026/08/12 01:15:37 by charlie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(int fd, const char *format, ...);
int	ft_putchr(char c, int fd);
int	ft_putstr(char *str, int fd);
int	ft_putnbr(int n, int fd);
int	ft_putptr(void *ptr, int fd);
int	ft_puthex(unsigned long num, char format, int fd);
int	ft_putuns(unsigned int num, int fd);

#endif