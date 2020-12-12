/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnaciri- <fnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 10:27:05 by fnaciri-          #+#    #+#             */
/*   Updated: 2020/12/12 14:55:14 by fnaciri-         ###   ########.fr       */
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
    char *op;
    
    i = 0;
    pipeline = ft_splitt(line, "|;");
    pipeline = ft_argtrim(pipeline, " "); // p[0] = echo tet>f1>f2 ; p[1] = pwd > f2
    print_arg(pipeline);
    while (pipeline[i])
    {
        s = ft_splitt(pipeline[i], "><>>"); // s[0]= echo tet> >s[1] = f1 > s[2] = f2;
        s = ft_splitt(pipeline[i], "  ");
        op = opr(pipeline[i]);
        if (op)
            s = remove_arg(s, op);
        s = ft_argtrim(s, "\"'");
        cmd = ft_cmd_new(get_path(s[0]), s, op);
        ft_cmd_add_back(&g_cmd, cmd);
        i++;
    }
    
}

char    **ft_argtrim(char **arg, char *set)
{
    int i;
    char *tmp;
    i = 0;
    while (arg[i])
    {
        tmp = arg[i];
        arg[i] = ft_strtrim(arg[i], set);
        free(tmp);
        i++;
    }
    return arg;
}

char    **remove_arg(char **arg, char *s)
{
    int i;
    int l;
    
    i = 0;
    while (arg[i])
    {
        if (!ft_strncmp(arg[i], s, ft_strlen(s)))
        {
            free(arg[i]);
            arg[i] = NULL;
            return (arg);
        }
        i++;
    }
    if (ft_strchr(arg[i - 1], '|') || ft_strchr(arg[i - 1], ';'))
    {
        l = ft_strlen(arg[i - 1]);
        arg[i - 1][l - 1] = 0;
    }
    return (arg);
}

int     arg_num(char **arg)
{
    int i;

    i = 0;
    while (arg[i])
        i++;
    return (i);
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
             printf("arg[%d] |%s|\n",i, arg[i]);
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
        printf("opr |%s|\n", tmp->op);
		tmp = tmp->next;
	}
}