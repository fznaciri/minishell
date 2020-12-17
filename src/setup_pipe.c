/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnaciri- <fnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 10:24:45 by fnaciri-          #+#    #+#             */
/*   Updated: 2020/12/17 12:01:22 by fnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void    setup_pipe(t_cmd *cmd)
{
    if (cmd->op && cmd->op[0] == '|')
    {
        dup2(cmd->pipe[1], 1);
    }
    if (cmd->prev && cmd->prev->op && cmd->prev->op[0] == '|')
    {
        dup2(cmd->prev->pipe[0], 0);
    }
}

void reset_std()
{
    dup2(g_sh.in, 0);
    dup2(g_sh.out, 1);
}

void open_pipe()
{
    t_cmd *tmp;
    
    tmp = g_cmd;
    while (tmp)
    {
        if (tmp->op && tmp->op[0] == '|')
            pipe(tmp->pipe);
        tmp = tmp->next;
    }
}

void close_pipe()
{
    t_cmd *tmp;
    
    tmp = g_cmd;
    while (tmp)
    {
        if (tmp->op && tmp->op[0] == '|')
        {
            close(tmp->pipe[0]);
            close(tmp->pipe[1]);
        }
        tmp = tmp->next;
    }
}