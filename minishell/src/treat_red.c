/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_red.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnaciri- <fnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 10:30:25 by fnaciri-          #+#    #+#             */
/*   Updated: 2021/01/23 15:30:09 by fnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_red    *treat_red(char *pipeline)
{
    int i;
    char *red_type;
    t_red *red;
    t_red *red_list;
    i = 0;
    
    red_list = NULL;
    red_type = NULL;
    while (pipeline[i])
    {
        if (pipeline[i] == '>' && pipeline[i + 1] == '>')
        {   
            red_type = ft_strdup(">>");
            i++;
        }     
        else if (pipeline[i] == '<')
            red_type = ft_strdup("<");
        else if (pipeline[i] == '>')
            red_type = ft_strdup(">");
        if (red_type)
        {
            red = ft_red_new(red_type, ft_strtrim(extract(pipeline + i + 1, " ><;|"), " "));
            ft_red_add_back(&red_list, red);
        }
        red_type = NULL;
        i++;
    }
    return (red_list);
}

char  *extract(char *s, char *set)
{
    int i;
    int j;
    char *str;
    
    i = 0;
    j = 0;
    while (s[i] == ' ')
        i++;
    while(s[i])
    {
        if (ft_strrchr(set, s[i]))
            break ;
        i++;
    }
    return (ft_strndup(s, i));
}


char    *remove_red(char *cmd)
{
    int i;
    int j;
    int len;
    char *new;
    
    new = malloc(ft_strlen(cmd) + 1);
    i = 0;
    j = 0;
    while (cmd[i])
    {
        if (cmd[i] == '>' && cmd[i] == '>')
        {
            i += 2;
            i += ft_strlen(extract(cmd + i + 1, " ><|;"));
        }
        else if (cmd[i] == '<' || cmd[i] == '>')
        {
            i++;
            i += ft_strlen(extract(cmd + i + 1, " ><|;"));
        }
        else
        {
            new[j] = cmd[i];
            j++;
        }
        i++;
    }
    new[j] = 0;
    return new;
}

int     ft_redcount(char *cmd, int l)
{
    int i;
    int j;
    int r;
    int len;

    i = 0;
    j = 0;
    r = 0;
    while (i < l)
    {
        if (cmd[i] == '>' && cmd[i + 1] == '>')
        {
            j = j + 2;
            i++;
            r = 1;
        }
        else if (cmd[i] == '>' || cmd[i] == '<')
        {
            j++;
            r = 1;
        }
        if (r)
        {
            len = ft_strlen(extract(cmd + i + 1, " ><;|"));
            r = len + (ft_strnchrn(cmd + i + 1 + len, "><") ? ft_count_space(cmd + i + 1 + len) : 0);
            i = i + r - 1;
            j = j + r;
        }
        r = 0;
        i++;
    }
    return j;
}

int     ft_count_space(char *s)
{
    int i;
    i =0;
    while (s[i] && (s[i] == ' ' || s[i] == '\t'))
        i++;
    return i;
}