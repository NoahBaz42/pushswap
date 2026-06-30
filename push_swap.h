/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noah-baz <noah-baz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 18:57:38 by noah-baz          #+#    #+#             */
/*   Updated: 2026/06/30 21:39:28 by noah-baz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft/libft.h"
#include <stdlib.h>
#include <unistd.h>

//utils->free functions
void    give_error(void);
void    free_array(char **array);
void    free_list(t_list list);
//flag
void    flag_checker(int argc, char **argv);
//parsing
static long int ft_atol(char *array);
int     arr_count(char **array);
char    **other_parsing(int argc, char **argv);
int ft_dup_check(char **array, int size);
t_list *simple_parsing(int argc, char **argv);
//lists
t_list   array_to_list();

#endif