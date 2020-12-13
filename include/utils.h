/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnaciri- <fnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 13:58:21 by fnaciri-          #+#    #+#             */
/*   Updated: 2020/12/13 11:29:02 by fnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
#include <stdio.h>
#include "struct.h"
#include "../libft/libft.h"
# define BUFFER_SIZE 32

char    *g_line;

int			        gnl(int fd, char **line);
char				**ft_splitt(char const *s, char *set);
t_cmd				*ft_cmd_new(void *cmd, char **arg, char *op);
t_cmd				*ft_cmd_last(t_cmd *lst);
void				ft_cmd_add_back(t_cmd **alst, t_cmd *new);
void                ft_cmd_delone(t_cmd *cmd);
void                ft_cmd_clear(t_cmd **cmd);
t_red               *ft_red_new(void *red_type, char *file);
void	ft_red_add_back(t_red **red, t_red *new);
t_red		*ft_red_last(t_red *lst);
t_red	*ft_red_new(void *red_type, char *file);
char *ft_strndup(const char *s1, size_t n);

int     ft_strnchrn(char *s, char *set);
int     ft_strchrn(char *s, char c);
int     ft_tab_min(int tab[], int i);
#endif