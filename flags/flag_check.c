/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaz-sil <nbaz-sil@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 19:44:11 by nbaz-sil          #+#    #+#             */
/*   Updated: 2026/08/14 10:49:42 by nbaz-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

static bool	right_flags(t_flags *flags, char **argv)
{
	if (count_flags(flags) == 0)
	{
		flags->difficulty = DIFF_ADAPTIVE;
		return (true);
	}
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

void	flag_check(t_flags *flags, char **argv)
{
	flag_diff(flags, argv[1]);
	if (argv[1])
		flag_bench(flags, argv);
	if (argv[2])
		flag_diff(flags, argv[2]);
	if (argv[1] && !right_flags(flags, argv))
		give_error();
}
