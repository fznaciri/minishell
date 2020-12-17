/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnaciri- <fnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 20:32:02 by fnaciri-          #+#    #+#             */
/*   Updated: 2020/12/17 12:05:31 by fnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int exec(t_cmd cmd)
{
    int   status;
    
    if ((g_sh.pid = fork()) == -1) 
    {
        perror("bad fork");
        exit(1);
    }
    else if (g_sh.pid == 0)
    {
        execve(cmd.cmd, cmd.arg , g_sh.env);
        perror(cmd.cmd);
        exit(1);
    }
    close(cmd.pipe[1]);
    waitpid(g_sh.pid, &status, 0);
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
        setup_pipe(cmd);
        setup_red(cmd);
        i = 0;
        while (i < BUILTINS_NUM)
        {
            if (!strcmp(cmd->cmd, builtins_str[i]))
            {
                g_sh.status = (*builtins[i])(cmd->arg);
                close(cmd->pipe[1]);
                built = 1;
            }    
            i++;
        }
        if (!built)
            g_sh.status = exec(*cmd);
        built = 0;
        reset_std();
        cmd = cmd->next;
    }  
    return 0;
}

void    setup_red(t_cmd *cmd)
{
    t_red *red;

    red = cmd->red;
    while (red)
    {
        if (red->red_type[0] == '>')
        {
            printf("test\n");
            cmd->fd_out = open(red->file, O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
        }
        else if (red->red_type[0] == '>' && red->red_type[1] == '>')
            cmd->fd_out = open(red->file, O_CREAT | O_WRONLY | O_APPEND, S_IRWXU);
        if (red->red_type[0] == '<')
            cmd->fd_in = open(red->file, O_CREAT | O_RDONLY, S_IRWXU);
        if (red->next && red->red_type[0] == '>')
            close(cmd->fd_out);
        // if (red->next && red->type[0] == '<')
        //     close(cmd.fd_in);
        red = red->next;
    }
    if (cmd->fd_in)
        dup2(cmd->fd_in, 0);
    if (cmd->fd_out)
        dup2(cmd->fd_out, 0);
}