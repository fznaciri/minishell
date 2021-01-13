/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_export.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnaciri- <fnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 12:08:27 by fnaciri-          #+#    #+#             */
/*   Updated: 2021/01/13 15:47:09 by fnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int   cmd_export(char **arg)
{
    int i;
    char *env;
    char *var;
    
    if (arg_num(arg) == 1)
    {
        i = 0;
        while (g_sh.env[i])
        {
            if (ft_strncmp(g_sh.env[i], "_=", 2))
            {
                var = extract_env(g_sh.env[i]);
                ft_putstr_fd("declare -x ", 1);
                ft_putstr_fd(var, 1);
                if (var[ft_strlen(var) - 1] == '=')
                {
                    ft_putstr_fd("\"", 1);
                    ft_putstr_fd(g_sh.env[i] + ft_strlen(var), 1);
                    ft_putstr_fd("\"", 1);
                }
                write(1, "\n", 1);
            }
            i++;
        }
    }
    i = 1;
    while (arg[i])
    {
        if (arg[i][0] == '=')
        {
            ft_putstr_fd("bash: export: ",2);
            ft_putstr_fd(arg[i], 2);
            ft_putstr_fd(" : not a valid identifier\n", 2);
            return 1;
        }
        env = extract_env(arg[i]);
        if (env && ft_isdigit(env[0]))
        {
            ft_putstr_fd("bash: export: not a valid identifier\n", 2);
            return 1;
        }
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
    char **env;

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
    char *str;
    
    i = 0;
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