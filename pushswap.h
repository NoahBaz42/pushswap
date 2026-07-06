/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpassos- <bpassos-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 18:57:38 by noah-baz          #+#    #+#             */
/*   Updated: 2026/07/06 05:35:43 by bpassos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft_pushswap/libft.h"
#include <complex>
#include <stdlib.h>
#include <unistd.h>

typedef struct operations
{
    char    *sa;
    char    *sb;
    char    *ss;
    char    *pa;
    char    *pb;
    char    *ra;
    char    *rb;
    char    *rr;
    char    *rra;
    char    *rrb;
    char    *rrr;
}               op;

//pushswap operations:
void    ft_sstack(t_node *stack);
void    ft_ss(t_node *stack_a, t_node *stack_b);
void    ft_pstack(t_node *stack_1, t_node *stack_2);
void    ft_rstack(t_node *stack);
void    ft_rr(t_node *stack_a, t_node *stack_b);
void    ft_rrstack(t_node *stack);
void    ft_rrr(t_node *stack_a, t_node *stack_b);

//utils:
void	ft_del_it(void *content);

#endif