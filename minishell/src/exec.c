/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnaciri- <fnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 20:32:02 by fnaciri-          #+#    #+#             */
/*   Updated: 2021/01/23 12:06:33 by fnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int exec(t_cmd cmd)
{
    int   status;
    DIR  *dir;
    int err;
    
    if ((g_sh.pid = fork()) == -1) 
    {
        perror("bad fork");
        exit(1);
    }
    else if (g_sh.pid == 0)
    {
        if (execve(cmd.cmd, cmd.arg , g_sh.env) == -1)
        {
            err = errno;
            ft_putstr_fd("minishell: ", 2);
            ft_putstr_fd(cmd.cmd, 2);
            dir = opendir(cmd.cmd);
            if (dir)
            {
                closedir(dir);
                ft_putendl_fd(": is a directory", 2);
            }
            else if (err == 2)
            {
                ft_putstr_fd(": command not found\n", 2);
                exit(127);
            }
            else
            {
                // ft_putstr_fd(": ", 2);
                ft_putendl_fd(": Permission denied", 2);
                // ft_putendl_fd(strerror(err), 2);
            }
            exit(126);
        }
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
        wrap_exec(&cmd);
        // print_cmd(cmd);
        setup_pipe(cmd);
        setup_red(cmd);
        i = 0;
        while (i < BUILTINS_NUM && cmd->cmd)
        {
            if (!strcmp(cmd->cmd, builtins_str[i]))
            {
                g_sh.status = (*builtins[i])(cmd->arg);
                close(cmd->pipe[1]);
                built = 1;
            }    
            i++;
        }
        if (!built && cmd->cmd && !ft_is_empty(cmd->cmd))
            g_sh.status = exec(*cmd);
        built = 0;
        reset_std();
        cmd = cmd->next;
    }  
    return g_sh.status;
}

void    setup_red(t_cmd *cmd)
{
    t_red *red;

    red = cmd->red;
    cmd->fd_out = 0;
    cmd->fd_in = 0;
    while (red)
    {
        if (red && red->red_type[0] == '>' && red->red_type[1] != '>')
            cmd->fd_out = open(red->file, O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
        else if (red && red->red_type[0] == '>' && red->red_type[1] == '>')
            cmd->fd_out = open(red->file, O_CREAT | O_WRONLY | O_APPEND, S_IRWXU);
        if (red && red->red_type[0] == '<')
            cmd->fd_in = open(red->file, O_RDONLY, S_IRWXU);
        if (cmd->fd_in < 0 || cmd->fd_out< 0)
        {
            ft_putstr_fd("minishell: ", 2);
            ft_putstr_fd(red->file, 2);
            ft_putstr_fd(": ", 2);
            ft_putendl_fd(strerror(errno), 2);
        }
        if (red->next && cmd->fd_out && red->next->red_type[0] != '<')
            close(cmd->fd_out);
        if (red->next && cmd->fd_in && red->next->red_type[0] == '<')
            close(cmd->fd_in);
        red = red->next;
    }
    if (cmd->fd_in)
        dup2(cmd->fd_in, 0);
    if (cmd->fd_out)
        dup2(cmd->fd_out, 1);
}

void    wrap_exec(t_cmd **cmd)
{
    int i;
    int j;
    char **arg;
    char *tmp;

    (*cmd)->cmd = restruct_line((*cmd)->cmd);
    arg = malloc((arg_num((*cmd)->arg) + 1) * sizeof(char*));
    i = 0;
    j = 0;
    while ((*cmd)->arg[i])
    {
        tmp = restruct_line((*cmd)->arg[i]);
        if (tmp)
        {
            arg[j] = tmp;
            if (arg[j])
            {
                arg[j] = ft_strremove(arg[j], '"');
                arg[j] = ft_strremove(arg[j], '\'');
                arg[j] = ft_strremove(arg[j], '\\');
                // printf("arg : %s\n", (*cmd)->arg[i]);
            }
            j++;
        }
        i++;
    }
    arg[j] = NULL;
    (*cmd)->arg = arg;
}