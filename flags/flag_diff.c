/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_diff.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charlie <charlie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 08:50:36 by noah-baz          #+#    #+#             */
/*   Updated: 2026/08/09 11:04:25 by charlie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

//----------[activates diff, error if duplicate]--------------------------//

static void	activatt_diff(t_flags *flags, t_diff diff)
{
	if (flags->has_diff == true)
		give_error();
	flags->difficulty = diff;
	flags->has_diff = true;
}

//----------[strcmpares arg with diff flags]------------------------------//
//----------[if 0(theyre the same), activatt_diff]---------------------//

void	flag_diff(t_flags *flags, char *arg)
{
	if (!strcmp(arg, "--simple"))
		activatt_diff(flags, DIFF_SIMPLE);
	else if (!strcmp(arg, "--medium"))
		activatt_diff(flags, DIFF_MEDIUM);
	else if (!strcmp(arg, "--complex"))
		activatt_diff(flags, DIFF_COMPLEX);
	else
		activatt_diff(flags, DIFF_ADAPTIVE);
}

//----------[checks for diff flags; false if none]------------------------//

bool	is_diff_flags(char *flag)
{
	if (!strcmp(flag, "--simple"))
		return (true);
	else if (!strcmp(flag, "--medium"))
		return (true);
	else if (!strcmp(flag, "--complex"))
		return (true);
	else if (!strcmp(flag, "--adaptive"))
		return (true);
	return (false);
}
