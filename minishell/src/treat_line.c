/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnaciri- <fnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 10:27:05 by fnaciri-          #+#    #+#             */
/*   Updated: 2021/01/15 16:37:21 by fnaciri-         ###   ########.fr       */
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
    t_red *red;
    char *op;
    int j;
    
    j = 0;
    i = 0;
    pipeline = ft_splitt(line, "|;");
    pipeline = ft_argtrim(pipeline, " ");
    // print_arg(pipeline);
    while (pipeline[i])
    {
       
        red = treat_red(pipeline[i]); 
        op = opr(pipeline[i]);
        pipeline[i] =  remove_red(pipeline[i]);
        s = ft_splitt(pipeline[i], "  ");
        if (op)
            s = remove_arg(s, op);
        // s = ft_argtrim(s, "\"'");
        cmd = ft_cmd_new(ft_strtrim(get_path(s[0]), " "), s, op);
        cmd->red = red;
        ft_cmd_add_back(&g_cmd, cmd);
        i++;
    }
}


char    *restruct_line(char *l)
{
    int i;
    char *line;
    char *v;
    
    i = 0;
    line = NULL;
    while(l[i])
    {
        if (l[i - 1] != '\\' && l[i] == '$' && !is_space(l[i + 1]))
        {
            if (l[i + 1] == '?')
            {
                line = ft_strjoin(line, ft_itoa(g_sh.status));
                i++;
            }
            else
            {
                v = extract(l + i + 1, "$");
                printf("v: %s\n", v);
                if (v)
                {
                    line = ft_strjoin(line, ft_getenv(v));
                    printf("line: %s\n", line);
                    i += ft_strlen(v);
                }
                else
                    line = ft_strappend(line, l[i]);
                
            }
        }
        else if (l[i] == '~' && l[i - 1] != '\\')
            line = ft_strjoin(line, getenv("HOME"));
        else
            line = ft_strappend(line, l[i]);
        i++;
    }
    return (line);
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
        return ft_strdup(s + l - 1);
    return NULL;
}

void print_arg(char **arg)
{
    int i;

    i = 0;
    while(arg[i])
    {
        printf("arg[%d] |%s|\n",i, arg[i]);
        i++;
    }
}

void    print_cmd(t_cmd *cmd)
{
    t_cmd *tmp = cmd;
    t_red *red;

    red = tmp->red;
	if (!tmp)
		printf("NULL\n");
	while (tmp)
	{
		printf("cmd %s\n", tmp->cmd);
        print_arg(tmp->arg);
        while (red)
        {
            printf("type: %s file: %s\n", red->red_type, red->file);
            red = red->next;
        }
        printf("opr |%s|\n", tmp->op);
		tmp = tmp->next;
	}
}