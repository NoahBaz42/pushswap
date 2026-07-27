/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noah-baz <noah-baz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 19:44:11 by noah-baz          #+#    #+#             */
/*   Updated: 2026/07/27 17:19:56 by noah-baz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//----------[counts how many flags are active]----------------------------//

int	ft_count_flags(t_flags *flags)
{
	int	count;

	count = 0;
	if (flags->has_bench == true)
		count++;
	if (flags->has_diff == true)
		count++;
	return (count);
}

//----------[based on ft_count_flags, checks for valid flags]-------------//
//----------[true if valid flags, false otherwise]------------------------//

static bool	ft_right_flags(t_flags *flags, char **argv)
{
	if (ft_count_flags(flags) == 0)
		return (true);
	if (ft_count_flags(flags) == 1)
	{
		if (ft_is_bench_flags(argv[1]) || ft_is_diff_flags(argv[1]))
			return (true);
	}
	if (ft_count_flags(flags) == 2)
	{
		if ((argv[2] && ft_is_bench_flags(argv[1]) && ft_is_diff_flags(argv[2]))
			|| (ft_is_bench_flags(argv[2]) && ft_is_diff_flags(argv[1])))
			return (true);
	}
	return (false);
}

//----------[checks 1st arg for bench or difficulty]----------------------------//
//----------(ft_flag_bench already checks both arg[1] and arg[2])---------------//
//----------[it works, but im not sure about the error dealing]-----------------//

void	ft_flag_check(t_flags *flags, char **argv)
{
	if (argv[1])
		ft_flag_bench(flags, argv);
	ft_flag_diff(flags, argv[1]);
	if (argv[2])
		ft_flag_diff(flags, argv[2]);
	if (argv[1] && !ft_right_flags(flags, argv))
		ft_give_error();
}
