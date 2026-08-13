/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charlie <charlie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 04:34:04 by nbaz-sil          #+#    #+#             */
/*   Updated: 2026/08/13 23:01:06 by charlie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "pushswap.h"
# include <stdlib.h>
# include <unistd.h>

# define BUFFER_SIZE 3

size_t		ft_strlen_gnl(char *line);
void		*ft_memcpy(void *dest, const void *src, size_t n);
char		*ft_strjoin_gnl(char *line, char *buffer);
void		ft_update(char *buffer);
char		*ft_find_line(char *line);
char		*get_next_line(int fd);

void		add_op(t_op_lst **lst, t_op_lst *new);
t_op_lst	*op_last(t_op_lst *lst);
t_op_lst	*op_new(char *op);
void		free_op_node(t_op_lst *node);
void		free_one_op_node(t_op_lst *lst, void (*del)(t_op_lst *));
void		free_op_lst(t_op_lst **lst, void (*del)(t_op_lst *));

#endif
