/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnaciri- <fnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 10:27:05 by fnaciri-          #+#    #+#             */
/*   Updated: 2021/02/02 18:07:37 by fnaciri-         ###   ########.fr       */
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
    char *path;
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
        s = ft_splitt(pipeline[i], "  \t");
        if (op)
            s = remove_arg(s, op);
        // s = ft_argtrim(s, "\"'");
        if (!(s[0]))
            s[0] = ft_strdup("");
        else if (ft_is_empty(s[0]) && s[1])
            s = s + 1;
        path = get_path(s[0]);
        path = ft_strtrim(path, " ");
        path = ft_strremove(path, '\'');
        path = ft_strremove(path, '"');
        cmd = ft_cmd_new(path, s, op);
        cmd->red = red;
        ft_cmd_add_back(&g_cmd, cmd);
        i++;
    }
}

// int   check_syntax(char *line)
// {
//     int i;
//     int n;

//     i = 0;
//     n = ft_strlen(line);
//     while (line[i])
//     {
//         while (line[i] == ' ')
//             i++;
//         if (ft_strnchr(line, "|;"))
//              return (ft_err("bash: syntax error near unexpected token `|'", 258));
//         if (ft_strnchr(line, ";|")) 
//             return (ft_err("bash: syntax error near unexpected token `|'",258));
//         if ((ft_strnchr(line, ";;")))
//             return (ft_err("bash: syntax error near unexpected token `;;'",258));
//         if (ft_strnchr(line, "><"))
//             return (ft_err("bash: syntax error near unexpected token `>'",258));
//         if (ft_strnchr(line, "||"))
//             return (ft_err("bash: syntax error near unexpected token `|'",258));
//         if (ft_strnchrn(line, ">>>"))
//             return (ft_err("bash: syntax error near unexpected token `>'",258));
//         i++;
//     }
//     return 0;
// }


char    *check_syntax()
{
    int r;
    g_sh.errors[1] = ft_strdup("minishell: syntax error near unexpected token `|'");
    g_sh.errors[2] = ft_strdup("minishell: syntax error near unexpected token `;'");
    g_sh.errors[3] = ft_strdup("minishell: syntax error near unexpected token `||'");
    g_sh.errors[4] = ft_strdup("minishell: syntax error near unexpected token `;;'");
    g_sh.errors[5] = ft_strdup("minishell: syntax error near unexpected token `|;'");
    g_sh.errors[6] = ft_strdup("minishell: syntax error near unexpected token `;|'");
    g_sh.errors[7] = ft_strdup("minishell: syntax error near unexpected token `<<'");
    g_sh.errors[8] = ft_strdup("minishell: syntax error near unexpected token `>'");
    g_sh.errors[9] = ft_strdup("minishell: syntax error near unexpected token `newline'");
    if ((r = check_pipe()))
        return g_sh.errors[r];
    if ((r = check_red()))
        return g_sh.errors[r];
    // if ((r = check_quote()))
    //     return g_sh.errors[r];
    return NULL;
}
int     check_pipe()
{
    int l;
    l = 0;
    while (g_line[l] == ' ')
        l++;
    if (g_line[l] == '|')
        return 1;
    else if (g_line[l] == ';')
        return 2;
    l = ft_strlen(g_line);
    l--;
    while (g_line[l])
    {
        if (g_line[l] == ' ')
            l--;
        if (g_line[l] == '|')
            return 1;
        else
            break ;
    }
    if (ft_strnchr(g_line, "||"))
        return 3;
    if (ft_strnchr(g_line, ";;"))
        return 4; 
    if (ft_strnchr(g_line, "|;"))
        return 5;
    if (ft_strnchr(g_line, ";|"))
        return 6;
    return 0;
}
int     check_red()
{
    int i;
    if (ft_strnchr(g_line, "<<"))
        return 7;
    if (ft_strnchr(g_line, ">>>"))
        return 8;
    i = 0;
    while (g_line[i])
    {
        if (g_line[i] == '>' && g_line[i + 1] == '>')
        {
            i+= 2;
            while (g_line[i] == ' ')
                i++;
            if (SPECIAL(g_line[i]) || !g_line[i])
                return 9;
        }
        else if (g_line[i] == '>' || g_line[i] == '<')
        {
            i++;
            while (g_line[i] == ' ')
                    i++;
            if (SPECIAL(g_line[i]) || !g_line[i])
                return 9;
        }
        i++;
    }
    return 0;
}

int ft_err(char *s, int i)
{
    ft_putendl_fd(s, 2);
    return i;
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
        if (l[i] == '\'' && l[i - 1 < 0 ? 1 : i - 1] != '\\')
        {
            i++;
            while (l[i] != '\'')
            {
                line = ft_strappend(line, l[i]);
                i++;
            }
        }
        if (l[i - 1 < 0 ? 1 : i - 1] != '\\' && l[i] == '$' && !is_space(l[i + 1]))
        {
            if (l[i + 1] == '?')
            {
                line = ft_strjoin(line, ft_itoa(g_sh.status));
                i++;
            }
            else
            {
                v = extract(l + i + 1, "\"$= |@,");
                if (v)
                {
                    line = ft_strjoin(line, ft_getenv(v));
                    i += ft_strlen(v);
                }
                else
                    line = ft_strappend(line, l[i]);
                
            }
        }
        else if (l[i] == '~' && l[i - 1 < 0 ? 1 : i - 1] != '\\')
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
    if (ft_strchr(arg[i - 1 < 0 ? 1 : i - 1], '|') || ft_strchr(arg[i - 1 < 0 ? 1 : i - 1], ';'))
    {
        l = ft_strlen(arg[i - 1 < 0 ? 1 : i - 1]);
        arg[i - 1 < 0 ? 1 : i - 1][l - 1] = 0;
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