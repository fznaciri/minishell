/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnaciri- <fnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 13:58:35 by fnaciri-          #+#    #+#             */
/*   Updated: 2020/12/17 12:02:41 by fnaciri-         ###   ########.fr       */
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
#include <sys/wait.h>
#include <time.h>
#include <errno.h>
#include <stdlib.h>

# define BUILTINS_NUM 7

int (*builtins[BUILTINS_NUM])(char **);
char *builtins_str[BUILTINS_NUM];

char    *ft_getenv(char *name);
void    treat_line(char *line);
void    print_cmd(t_cmd *cmd);
void    print_arg(char **arg);
char    *opr(char *s);
char    *get_path(char *s);
void    init_env(char **env);
char    **remove_arg(char **arg, char *s);
int     is_space(char c);
void    skip_spaces(char **s);
int     arg_num(char **arg);
// builtins
void    init_builtins();
int     is_builtins(char *s);
int    execute_builtins();
int    cmd_cd(char **arg);
int		cmd_echo(char **arg);
int  cmd_pwd(char **arg);
int cmd_env(char **arg);
int   cmd_export(char **arg);
int   cmd_unset(char **arg);
int    cmd_exit(char **arg);
void    add_env(char *s);
char  *extract_env(char *s);
void    replace_env(char *s);
char    **ft_argtrim(char **arg, char *set);
void    remove_env(char *s);
int exec(t_cmd cmd);
int     execute(t_cmd *cmd);
t_red    *treat_red(char *pipeline);
char  *extract_file(char *s, char *set);
char    *remove_red(char *cmd);
void    setup_pipe(t_cmd *cmd);
void reset_std();
void open_pipe();
void close_pipe();


int g_pipe[2];

#endif