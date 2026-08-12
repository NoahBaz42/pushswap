/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   free_parsing.c                                    :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: username <username@student.42tokyo.jp>    #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/08/11 03:24:20 by username         #+#    #+#              */
/*   Updated: 2026/08/12 21:33:44 by username        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	free_op_count(t_op_count *op_count)
{
	if (!op_count)
		return ;
	free(op_count);
}
