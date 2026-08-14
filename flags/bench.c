/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaz-sil <nbaz-sil@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 08:52:33 by nbaz-sil          #+#    #+#             */
/*   Updated: 2026/08/14 10:49:33 by nbaz-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	output_bench(t_op_count *op_count, t_flags *flags, float disorder)
{
	const char	*names[4] = {"Adaptive", "Simple", "Medium", "Complex"};
	const char	*complex[4] = {"__", "O(n2)", "O(n√n)", "O(n log n)"};

	ft_printf(2, "[bench] disorder: %d", (int)(disorder * 100));
	ft_printf(2, ".%d", ((int)(disorder * 100) % 10));
	ft_printf(2, "%d%%\n", (((int)(disorder * 1000) % 10)));
	ft_printf(2, "[bench] strategy: %s / %s\n", names[flags->chosen],
		complex[flags->difficulty]);
	ft_printf(2, "[bench] total_ops: %d\n", op_count->total);
	ft_printf(2, "[bench] sa: %d sb: %d ss: %d pa: %d pb: %d\n", op_count->sa,
		op_count->sb, op_count->ss, op_count->pa, op_count->pb);
	ft_printf(2, "[bench] ra: %d rb: %d rr: %d rra: %d rrb: %d rrr: %d\n",
		op_count->ra, op_count->rb, op_count->rr, op_count->rra, op_count->rrb,
		op_count->rrr);
}
