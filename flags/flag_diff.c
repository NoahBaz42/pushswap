/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_diff.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charlie <charlie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 08:50:36 by noah-baz          #+#    #+#             */
/*   Updated: 2026/08/14 02:02:32 by charlie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//----------[activates diff, error if duplicate]--------------------------//

static void	activatt_diff(t_flags *flags, t_diff diff)
{
	if (flags->has_diff == true && count_flags(flags) == 0)
		give_error();
	flags->difficulty = diff;
	flags->has_diff = true;
}

//----------[strcmpares arg with diff flags]------------------------------//
//----------[if 0(theyre the same), activatt_diff]---------------------//

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

//----------[checks for diff flags; false if none]------------------------//

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
