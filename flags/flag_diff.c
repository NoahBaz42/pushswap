/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_diff.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaz-sil <nbaz-sil@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 08:50:36 by noah-baz          #+#    #+#             */
/*   Updated: 2026/08/07 07:26:25 by nbaz-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//----------[activates diff, error if duplicate]--------------------------//

static void	ft_activate_diff(t_flags *flags, e_diff diff)
{
	if (flags->has_diff == true)
		ft_give_error();
	flags->difficulty = diff;
	flags->has_diff = true;
}

//----------[strcmpares arg with diff flags]------------------------------//
//----------[if 0(theyre the same), ft_activate_diff]---------------------//

void	ft_flag_diff(t_flags *flags, char *arg)
{
	if (!ft_strcmp(arg, "--simple"))
		ft_activate_diff(flags, DIFF_SIMPLE);
	if (!ft_strcmp(arg, "--medium"))
		ft_activate_diff(flags, DIFF_MEDIUM);
	if (!ft_strcmp(arg, "--complex"))
		ft_activate_diff(flags, DIFF_COMPLEX);
	if (!ft_strcmp(arg, "--adaptive"))
		ft_activate_diff(flags, DIFF_ADAPTIVE);
}

//----------[checks for diff flags; false if none]------------------------//

bool	ft_is_diff_flags(char *flag)
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
