/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnaciri- <fnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 20:32:02 by fnaciri-          #+#    #+#             */
/*   Updated: 2020/12/11 12:01:14 by fnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int exec(t_cmd cmd)
{
    pid_t pid;
    int   status;
    
    if ((pid = fork()) == -1) 
    {
        perror("bad fork");
        exit(1);
    }
    else if (pid == 0)
    {
        execve(cmd.cmd, cmd.arg , g_env);
        perror(cmd.cmd);
        exit(1);
    }
    waitpid(pid, &status, 0);
    status = WEXITSTATUS(status);
    return status;
}

int     execute(t_cmd *cmd)
{
    int i;
    int built;
    
    built = 0;
    while (cmd)
    {
        i = 0;
        while (i < BUILTINS_NUM)
        {
            if (!strcmp(cmd->cmd, builtins_str[i]))
            {
                g_status = (*builtins[i])(cmd->arg);
                built = 1;
            }    
            i++;
        }
        if (!built)
            g_status = exec(*cmd);
        built = 0;
        cmd = cmd->next;
    }  
    return 0;
}