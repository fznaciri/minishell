/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnaciri- <fnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 13:58:35 by fnaciri-          #+#    #+#             */
/*   Updated: 2020/12/21 12:34:11 by fnaciri-         ###   ########.fr       */
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
#include <fcntl.h>
#include <signal.h>

# define BUILTINS_NUM 7

int (*builtins[BUILTINS_NUM])(char **);
char *builtins_str[BUILTINS_NUM];

//prompt
void prompt();

//treat line
void    treat_line(char *line);
char    *opr(char *s);
char    *get_path(char *s);
char    **remove_arg(char **arg, char *s);
int     arg_num(char **arg);
char    **ft_argtrim(char **arg, char *set);

//print
void    print_cmd(t_cmd *cmd);
void    print_arg(char **arg);

//spaces
int         is_space(char c);
void        skip_spaces(char **s);
int         ft_count_space(char *s);

// builtins
void        init_builtins();
int         is_builtins(char *s);
int         execute_builtins();
int         cmd_cd(char **arg);
int		    cmd_echo(char **arg);
int         cmd_pwd(char **arg);
int         cmd_env(char **arg);
int         cmd_export(char **arg);
int         cmd_unset(char **arg);
int         cmd_exit(char **arg);

//env
void        init_env(char **env);
void        inc_shlvl();
char        *ft_getenv(char *name);
void        add_env(char *s);
char        *extract_env(char *s);
void        replace_env(char *s);
void        remove_env(char *s);

//execution
int         exec(t_cmd cmd);
int         execute(t_cmd *cmd);

//redirection
t_red       *treat_red(char *pipeline);
char        *extract_file(char *s, char *set);
char        *remove_red(char *cmd);
void        setup_red(t_cmd *cmd);

//pipes
void        setup_pipe(t_cmd *cmd);
void        reset_std();
void        open_pipe();
void        close_pipe();
int         ft_redcount(char *cmd, int l);

//signal
void sig_handler(int signum);

#endif