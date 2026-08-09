/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charlie <charlie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 19:44:11 by noah-baz          #+#    #+#             */
/*   Updated: 2026/08/09 08:10:21 by charlie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

//----------[counts how many flags are active]----------------------------//

int	count_flags(t_flags *flags)
{
	int	count;

	count = 0;
	if (flags->has_bench == true)
		count++;
	if (flags->has_diff == true)
		count++;
	return (count);
}

//----------[based on count_flags, checks for valid flags]-------------//
//----------[true if valid flags, false otherwise]------------------------//

static bool	right_flags(t_flags *flags, char **argv)
{
	if (count_flags(flags) == 0)
		return (true);
	if (count_flags(flags) == 1)
	{
		if (is_bench_flags(argv[1]) || is_diff_flags(argv[1]))
			return (true);
	}
	if (count_flags(flags) == 2)
	{
		if ((argv[2] && is_bench_flags(argv[1]) && is_diff_flags(argv[2]))
			|| (is_bench_flags(argv[2]) && is_diff_flags(argv[1])))
			return (true);
	}
	return (false);
}

//----------[checks 1st arg for bench or difficulty]----------------------------//
//----------(flag_bench already checks both arg[1] and arg[2])---------------//
//----------(right_flags checks for unvalid flags in 1st 2 args)-------------//

void	flag_check(t_flags *flags, char **argv)
{
	if (argv[1])
		flag_bench(flags, argv);
	flag_diff(flags, argv[1]);
	if (argv[2])
		flag_diff(flags, argv[2]);
	if (argv[1] && !right_flags(flags, argv))
		give_error();
}
