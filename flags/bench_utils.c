/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaz-sil <nbaz-sil@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/13 07:02:32 by nbaz-sil          #+#    #+#             */
/*   Updated: 2026/08/14 10:48:52 by nbaz-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	flag_bench(t_flags *flags, char **argv)
{
	if (argv[1] && ft_strcmp(argv[1], "--bench") == 0)
		flags->has_bench = true;
	if (argv[2] && ft_strcmp(argv[2], "--bench") == 0)
	{
		if (flags->has_bench == true)
			give_error();
		flags->has_bench = true;
	}
}

bool	is_bench_flags(char *flag)
{
	if (!ft_strcmp(flag, "--bench"))
		return (true);
	return (false);
}

float	disorder(t_node *stack)
{
	t_node	*node1;
	t_node	*node2;
	int		count;
	int		total_pairs;

	if (ft_lstsize(stack) <= 1)
		return (0);
	node1 = stack;
	count = 0;
	total_pairs = 0;
	while (node1)
	{
		node2 = node1->next;
		while (node1 != node2 && node2)
		{
			total_pairs++;
			if (node1->content > node2->content)
				count++;
			node2 = node2->next;
		}
		node1 = node1->next;
	}
	return ((float) count / (float) total_pairs);
}

void	ft_resolve_strategy(t_flags *flag, float disorder)
{
	flag->chosen = flag->difficulty;
	if (disorder < 0.2)
		flag->difficulty = DIFF_SIMPLE;
	else if (disorder < 0.5)
		flag->difficulty = DIFF_MEDIUM;
	else
		flag->difficulty = DIFF_COMPLEX;
}
