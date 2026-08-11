/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charlie <charlie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/11 03:24:20 by charlie           #+#    #+#             */
/*   Updated: 2026/08/11 03:26:48 by charlie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	free_flags(t_flags *flags)
{
	if (!flags)
		return ;
	free(flags);
}
void	free_op_count(t_op_count *op_count)
{
	if (!op_count)
		return ;
	free(op_count);
}