/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnaciri- <fnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 10:14:23 by fnaciri-          #+#    #+#             */
/*   Updated: 2021/02/15 16:54:32 by fnaciri-         ###   ########.fr       */
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
    while (g_sh.env[i])
    {
        j = 0;
        while (j <= l)
        {
            if (g_sh.env[i][j] != name[j])
                break ;
            j++;
            if (g_sh.env[i][j] == '=' && j == l)
                return g_sh.env[i] + j + 1;   
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
    g_sh.env = malloc(sizeof(char*) * (n + 1));
    while (env[i])
    {
        g_sh.env[i] = ft_strdup(env[i]);
        i++;
    }
    g_sh.env[i] = NULL;
}