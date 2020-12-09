/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnaciri- <fnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 11:44:53 by fnaciri-          #+#    #+#             */
/*   Updated: 2020/12/09 12:33:19 by fnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void    init_builtins()
{
    builtins[0] = &cmd_echo;
    builtins[1] = &cmd_cd;
    builtins[2] = &cmd_pwd;
    builtins[3] = &cmd_export;
    builtins[4] = &cmd_unset;
    builtins[5] = &cmd_env;
    builtins[6] = &cmd_exit;
    builtins_str[0] = "echo";
    builtins_str[1] = "cd";
    builtins_str[2] = "pwd";
    builtins_str[3] = "export";
    builtins_str[4] = "unset";
    builtins_str[5] = "env";
    builtins_str[6] = "exit";
}

int    execute_builtins(char **arg)
{
    int i;

    i =  0;
    while (i < BUILTINS_NUM)
    {
        if (!strcmp(arg[0], builtins_str[i]))
            return (*builtins[i])(arg);
        i++;
    }
    return (0); 
}