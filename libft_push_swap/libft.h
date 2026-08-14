/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charlie <charlie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 22:03:38 by bpassos-          #+#    #+#             */
/*   Updated: 2026/08/14 00:21:36 by charlie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <sys/types.h>
# define CASE_DIFF 32

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
// other libraries:
# include <bsd/string.h>
# include <ctype.h>
# include <fcntl.h>
# include <stdbool.h>
# include <stddef.h>
# include <stdio.h>
# include <strings.h>

typedef struct s_node	t_node;

struct					s_node
{
	long				content;
	ssize_t				index;
	bool				indexed;
	ssize_t				size;
	ssize_t				chunk_min;
	ssize_t				cost;
	t_node				*next;
	t_node				*prev;
};

typedef struct s_list
{
	t_node				*root;
}						t_list;

// srcs_1 definitions:
int						ft_atoi(const char *nptr);
void					ft_bzero(void *s, size_t n);
void					*ft_calloc(size_t nmemb, size_t size);
int						ft_isalnum(int c);
int						ft_isalpha(int c);
int						ft_isascii(int c);
int						ft_isdigit(int c);
int						ft_isprint(int c);
void					*ft_memchr(const void *s, int c, size_t n);
int						ft_memcmp(const void *s1, const void *s2, size_t n);
void					*ft_memcpy(void *dest, const void *src, size_t n);
void					*ft_memmove(void *dest, const void *src, size_t n);
void					*ft_memset(void *s, int c, size_t n);
char					*ft_strchr(const char *s, int c);
char					*ft_strdup(const char *src);
size_t					ft_strlcat(char *dst, const char *src, size_t size);
size_t					ft_strlcpy(char *dst, const char *src, size_t size);
size_t					ft_strlen(const char *s);
int						ft_strncmp(const char *s1, const char *s2, size_t n);
int						ft_strcmp(const char *s1, const char *s2);
char					*ft_strnstr(const char *big, const char *little,
							size_t len);
char					*ft_strrchr(const char *s, int c);
int						ft_tolower(int c);
int						ft_toupper(int c);
// srcs_2 definitions:
char					*ft_substr(char const *s, unsigned int start,
							size_t len);
char					*ft_strjoin(char const *s1, char const *s2);
char					*ft_strtrim(char const *s1, char const *set);
char					**ft_split(char const *s, char c);
char					*ft_itoa(int n);
char					*ft_strmapi(char const *s, char (*f)(unsigned int,
								char));
void					ft_striteri(char *s, void (*f)(unsigned int, char *));
void					ft_putchar_fd(char c, int fd);
void					ft_putstr_fd(char *s, int fd);
void					ft_putendl_fd(char *s, int fd);
void					ft_putnbr_fd(int n, int fd);
// srcs_3 definitions:
// t_list				*ft_lstnew(t_node *root);
t_node					*ft_lstnew(int content);
void					ft_lstadd_front(t_node **lst, t_node *new);
size_t					ft_lstsize(t_node *lst);
t_node					*ft_lstlast(t_node *lst);
t_node					*ft_lstb4last(t_node *lst);
void					ft_lstadd_back(t_node **lst, t_node *new);
void					ft_lstdelone(t_node *lst, void (*del)(long));
void					ft_lstclear(t_node **lst, void (*del)(long));
void					ft_lstiter(t_node *lst, void (*f)(long));
t_node					*ft_lstmap(t_node *lst, int (*f)(int),
							void (*del)(long));

// PS Extra:
void					ft_free_stack(t_node **lst);
void					ft_free_node(t_node *lst);

#endif
