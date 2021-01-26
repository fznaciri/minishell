/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnaciri- <fnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 13:58:41 by fnaciri-          #+#    #+#             */
/*   Updated: 2021/01/26 14:39:29 by fnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_red
{
    char *red_type;
    char *file;
    struct s_red *next;
} t_red;

typedef struct s_cmd
{
    char *cmd;
    char **arg;
    char *op;
    t_red *red; 
    int fd_in;
    int fd_out;
    int     pipe[2];
    struct s_cmd *next;
    struct s_cmd *prev;
    
} t_cmd;

typedef struct s_sh
{
    char **env;
    int status;
    pid_t pid;
    int in;
    int out;
    char *errors[10];
} t_sh;

t_sh    g_sh;
t_cmd   *g_cmd;

#endif