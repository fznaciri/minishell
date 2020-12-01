/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnaciri- <fnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 13:58:21 by fnaciri-          #+#    #+#             */
/*   Updated: 2020/12/01 10:28:47 by fnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
#include <stdio.h>
#include "struct.h"
# define BUFFER_SIZE 32

char    *g_line;

int			        gnl(int fd, char **line);
char	            **ft_split_cmd(char *str);
t_cmd				*ft_cmd_new(void *cmd, char **arg, char *op);
t_cmd				*ft_cmd_last(t_cmd *lst);
void				ft_cmd_add_back(t_cmd **alst, t_cmd *new);

#endif