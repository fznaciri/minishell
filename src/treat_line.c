/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnaciri- <fnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 10:27:05 by fnaciri-          #+#    #+#             */
/*   Updated: 2020/12/01 14:49:13 by fnaciri-         ###   ########.fr       */
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
        printf("%s\n", pipeline[i]);
        s = ft_split(pipeline[i], ' ');
        cmd = ft_cmd_new(get_path(s[0]), s, opr(pipeline[i]));
        ft_cmd_add_back(&g_cmd, cmd);
        i++;
    } 
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

char    *get_path(char *s)
{
    struct stat buf;
    char **path;
    char *tmp;
    char *f_path;
    int i;

    i = 0;
    path = ft_split(ft_getenv("PATH"), ':');
    while (path[i])
    {
        f_path = ft_strjoin(path[i], "/");
        tmp = f_path;
        f_path = ft_strjoin(tmp, s);
        free(tmp);
        if (!stat(f_path, &buf))
            return f_path;
        free(f_path);
        i++;
    }
    return NULL;
}

void print_arg(char **arg)
{
    int i;

    i = 0;
    while(arg[i])
    {
        if (strcmp(arg[i], "|") && strcmp(arg[i], ";"))
             printf("%s\n", arg[i]);
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