/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnaciri- <fnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 10:14:23 by fnaciri-          #+#    #+#             */
/*   Updated: 2020/12/04 18:11:37 by fnaciri-         ###   ########.fr       */
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
}