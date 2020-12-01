/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnaciri- <fnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 10:14:23 by fnaciri-          #+#    #+#             */
/*   Updated: 2020/12/01 13:29:12 by fnaciri-         ###   ########.fr       */
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
    g_env = env;
}