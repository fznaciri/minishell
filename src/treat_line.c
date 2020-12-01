/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnaciri- <fnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 10:27:05 by fnaciri-          #+#    #+#             */
/*   Updated: 2020/12/01 14:10:04 by fnaciri-         ###   ########.fr       */
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
    int j = 0;
    pipeline = ft_split_cmd(line);
    while (pipeline[i])
    {   
        printf("%s\n", pipeline[i]);
        s = ft_split(pipeline[i], ' ');
        while (s[j])
        {
                printf("%s\n", s[j]);
                j++;
        }
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
    char **f_path;
    char *path;
    int i;

    i = 0;
    path = ft_getenv("PATH");
    f_path = ft_split(path, ':');
    while (f_path[i])
    {
        ft_strlcat(f_path[i], "/", ft_strlen(f_path[i]) + 2);
        ft_strlcat(f_path[i], s, ft_strlen(f_path[i]) + ft_strlen(s) + 1);
        if (stat(f_path[i], &buf) == 0)
            return (f_path[i]);
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