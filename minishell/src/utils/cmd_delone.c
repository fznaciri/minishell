/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_delone.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnaciri- <fnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 13:28:09 by fnaciri-          #+#    #+#             */
/*   Updated: 2020/12/17 10:58:11 by fnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/utils.h"

void	ft_cmd_delone(t_cmd *cmd)
{
	if (cmd)
	{
		if (cmd->cmd)
			free(cmd->cmd);
		if (cmd->arg)
			free(cmd->arg);
    	cmd = NULL;	
	}
}

void    ft_cmd_clear(t_cmd **cmd)
{
    t_cmd *tmp;

    tmp = *cmd;
    while (tmp)
    {
        ft_cmd_delone(tmp);
        tmp = tmp->next;
    }
	free(*cmd);
    *cmd = NULL;
}