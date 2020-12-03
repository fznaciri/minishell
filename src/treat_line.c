/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnaciri- <fnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 10:27:05 by fnaciri-          #+#    #+#             */
/*   Updated: 2020/12/03 11:07:10 by fnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"
#include <stdio.h>

void    treat_line(char *line)
{
    int i;
    char **pipeline;
    char **s;
    t_cmd *cmd;

    i = 0;
    pipeline = ft_split_cmd(line);
    while (pipeline[i])
    {   
        s = ft_split(pipeline[i], ' ');
        cmd = ft_cmd_new(get_path(s[0]), s, opr(pipeline[i]));
        if (cmd->op)
            cmd->arg = remove_last_arg(cmd->arg);
        ft_cmd_add_back(&g_cmd, cmd);
        i++;
    } 
}

char    **remove_last_arg(char **s)
{
    int i;

    i = 0;
    while (s[i])
        i++;
    s[i - 1] = NULL;
    return (s);
}

char    *opr(char *s)
{
    int i;
    int l;

    i = 0;
    l = ft_strlen(s);
    if (s[l - 1] == '|' || s[l - 1] == ';')
        return (s + l - 1);
    s[l - 1] = '\0';
    return NULL;
}

void print_arg(char **arg)
{
    int i;

    i = 0;
    while(arg[i])
    {
        if (strcmp(arg[i], "|") && strcmp(arg[i], ";"))
             printf("arg[%d] %s\n",i, arg[i]);
        i++;
    }
}

void    print_cmd(t_cmd *cmd)
{
    t_cmd *tmp = cmd;
	if (!tmp)
		printf("NULL\n");
	while (tmp)
	{
		printf("cmd %s\n", tmp->cmd);
        print_arg(tmp->arg);
        printf("opr %s\n", tmp->op);
		tmp = tmp->next;
	}
}