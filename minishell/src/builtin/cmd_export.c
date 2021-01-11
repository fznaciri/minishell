/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_export.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnaciri- <fnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 12:08:27 by fnaciri-          #+#    #+#             */
/*   Updated: 2021/01/11 15:50:35 by fnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int   cmd_export(char **arg)
{
    int i;
    char *env;
    
    if (arg_num(arg) == 1)
    {
        i = 0;
        while (g_sh.env[i])
        {
            if (ft_strncmp(g_sh.env[i], "_=", 2))
            {
                write(1, "declare -x ", 11);
                write(1, g_sh.env[i], ft_strlen(g_sh.env[i]));
                write(1, "\n", 1);
            }
            i++;
        }
    }
    i = 1;
    while (arg[i])
    {
        env = extract_env(arg[i]);
        if (ft_getenv(env))
            replace_env(arg[i]);
        else if (!ft_getenv(env))
            add_env(arg[i]);
        i++;
    }
    return 0;
}

void    add_env(char *s)
{
    int n;
    int i;
    char **env;

    i = 0;
    n = arg_num(g_sh.env);
    env = malloc(sizeof(char *) * (n + 2));
    ft_memcpy(env, g_sh.env, n * sizeof(char*));
    env[n] = ft_strdup(s);
    env[n + 1] = NULL;
    free(g_sh.env);
    g_sh.env = env;    
}

void    replace_env(char *s)
{
    int i;
    // int j;
    char *str;
    
    i = 0;
    // j = 0;
    // str = s;
    // while (s[j])
    // {
    //     if (s[j] == '=')
    //          break ;
    //     j++;
    // }
    // str = ft_substr(str, 0, j + 1);
    str = extract_env(s);
    while (g_sh.env[i])
    {
        if (ft_strncmp(g_sh.env[i], str, ft_strlen(str)) == 0)
        {
            g_sh.env[i] = ft_strdup(s);
        }
        i++;
    }
}

char  *extract_env(char *s)
{
    int j;
    char *str;
    
    j = 0;
    str = s;
    while (s[j])
    {
        if (s[j] == '=')
             break ;
        j++;
    }
    str = ft_substr(str, 0, j + 1);
    return (str);
}