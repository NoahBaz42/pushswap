/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_diff.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaz-sil <nbaz-sil@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 08:50:36 by nbaz-sil          #+#    #+#             */
/*   Updated: 2026/08/14 10:49:50 by nbaz-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	activatt_diff(t_flags *flags, t_diff diff)
{
	if (flags->has_diff == true && count_flags(flags) == 0)
		give_error();
	flags->difficulty = diff;
	flags->has_diff = true;
}

void	flag_diff(t_flags *flags, char *arg)
{
	if (!ft_strcmp(arg, "--simple"))
		activatt_diff(flags, DIFF_SIMPLE);
	else if (!ft_strcmp(arg, "--medium"))
		activatt_diff(flags, DIFF_MEDIUM);
	else if (!ft_strcmp(arg, "--complex"))
		activatt_diff(flags, DIFF_COMPLEX);
	else if (!ft_strcmp(arg, "--adaptive"))
		activatt_diff(flags, DIFF_ADAPTIVE);
}

bool	is_diff_flags(char *flag)
{
	if (!ft_strcmp(flag, "--simple"))
		return (true);
	else if (!ft_strcmp(flag, "--medium"))
		return (true);
	else if (!ft_strcmp(flag, "--complex"))
		return (true);
	else if (!ft_strcmp(flag, "--adaptive"))
		return (true);
	return (false);
}
