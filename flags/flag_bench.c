/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_bench.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charlie <charlie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 08:52:33 by noah-baz          #+#    #+#             */
/*   Updated: 2026/08/11 02:23:18 by charlie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

//------[Checks for the flag (--bench) on the 1st and 2nd args]-----------//
//------[gives error if there´s more then 1 bench flag]-------------------//
//------------(needs an error dealing revision)---------------------------//

void	flag_bench(t_flags *flags, char **argv)
{
	if (argv[1] && !ft_strcmp(argv[1], "--bench"))
		flags->has_bench = true;
	if (argv[2] && !ft_strcmp(argv[2], "--bench"))
	{
		if (flags->has_bench)
			give_error();
		flags->has_bench = true;
	}
}

//--------[returns true if arg is (--bench), false otherwise]-------------//

bool	is_bench_flags(char *flag)
{
	if (!ft_strcmp(flag, "--bench"))
		return (true);
	return (false);
}
