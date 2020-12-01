/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnaciri- <fnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 13:58:35 by fnaciri-          #+#    #+#             */
/*   Updated: 2020/12/01 13:30:34 by fnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

#include <stdio.h>
#include "utils.h"
#include "struct.h"
#include "../libft/libft.h"
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>

char *ft_getenv(char *name);
void    treat_line(char *line);
void    print_cmd(t_cmd *cmd);
void print_arg(char **arg);
char    *opr(char *s);
char    *get_path(char *s);
void    init_env(char **env);

char **g_env;

#endif