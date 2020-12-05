/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnaciri- <fnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 10:14:23 by fnaciri-          #+#    #+#             */
/*   Updated: 2020/12/05 13:41:54 by fnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char *ft_getenv(char *name)
{
    int i;
    int j;
    int l;

    i = 0;
    l = ft_strlen(name);
    while (g_env[i])
    {
        j = 0;
        while (j <= l)
        {
            if (g_env[i][j] != name[j])
                break ;
            j++;
            if (j == l)
                return g_env[i] + j + 1;
        }
        i++;  
    }
    return (NULL);
}

void    init_env(char **env)
{
    int n;
    int i;

    i = 0;
    n = arg_num(env);
    g_env = malloc(sizeof(char *) * n + 1);
    while (env[i])
    {
        g_env[i] = ft_strdup(env[i]);
        i++;
    }
    g_env[i] = NULL;
}

void    add_env(char *s)
{
    int n;
    int i;
    char **env;

    i = 0;
    n = arg_num(g_env);
    env = malloc(sizeof(char *) * n + 2);
    ft_memcpy(env, g_env, n * sizeof(char*));
    env[n] = ft_strdup(s);
    env[n + 1] = NULL;
    free(g_env);
    g_env = env;    
}

void    replace_env(char *s)
{
    int i;
    int j;
    char *str;
    
    i = 0;
    j = 0;
    str = s;
    while (s[j])
    {
        if (s[j] == '=')
             break ;
        j++;
    }
    str = ft_substr(str, 0, j + 1);
    while (g_env[i])
    {
        if (ft_strncmp(g_env[i], str, ft_strlen(str)) == 0)
        {
            g_env[i] = ft_strdup(s);
        }
        i++;
    }
}