/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_unset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnaciri- <fnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 12:09:31 by fnaciri-          #+#    #+#             */
/*   Updated: 2020/12/10 18:18:09 by fnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int   cmd_unset(char **arg)
{
    int i;

    i = 0;
    while (arg[i])
        remove_env(arg[i++]);
    return (0);    
}

void    remove_env(char *s)
{
    int i;
    int j;
    
    i = 0;
    while (g_env[i])
    {
        if (ft_strncmp(g_env[i], s, ft_strlen(s)) == 0)
        {
            j = 0;
            free(g_env[i]);
            while (g_env[i + j])
            {
                g_env[i + j] = g_env[i + j + 1];
                j++;
            }
        }
        i++;
    }
}