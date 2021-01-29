/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_unset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnaciri- <fnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 12:09:31 by fnaciri-          #+#    #+#             */
/*   Updated: 2021/01/29 19:03:53 by fnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int   cmd_unset(char **arg)
{
    int i;
    int ret;
    
    ret = 0;
    i = 1;
    while (arg[i])
    {
        if (is_special(arg[i]))
            ret = 1;
        else
            remove_env(arg[i]);
        // else
        //     return 1;
        i++;
    }
    return (ret);    
}

void    remove_env(char *s)
{
    int i;
    int j;
    
    i = 0;
    while (g_sh.env[i])
    {
        if (ft_strncmp(g_sh.env[i], s, ft_strlen(s)) == 0)
        {
            j = 0;
            free(g_sh.env[i]);
            while (g_sh.env[i + j])
            {
                g_sh.env[i + j] = g_sh.env[i + j + 1];
                j++;
            }
        }
        i++;
    }
}

int is_special(char *env)
{
    int j;
    int l;
    
    j = 0;
    if (ft_is_empty(env))
    {
        ft_putstr_fd("minishell: unset: ",2);
        ft_putchar_fd('`', 2);
        ft_putstr_fd(env, 2);
        ft_putchar_fd('\'', 2);
        ft_putstr_fd(": not a valid identifier\n", 2);
        return 1;
    }
    else
    {
        l = ft_strlen(env);
        while (env[j])
        {
            if (SPECIAL(env[j]) || env[j] == ' ' || env[l - 1] == '=')
            {
                ft_putstr_fd("minishell: unset: ",2);
                ft_putchar_fd('`', 2);
                ft_putstr_fd(env, 2);
                ft_putchar_fd('\'', 2);
                ft_putstr_fd(": not a valid identifier\n", 2);
                return 1;
            }
            j++;
        }  
    }
    return 0;
}