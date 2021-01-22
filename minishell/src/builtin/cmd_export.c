/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_export.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnaciri- <fnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 12:08:27 by fnaciri-          #+#    #+#             */
/*   Updated: 2021/01/22 12:42:54 by fnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int   cmd_export(char **arg)
{
    int i;
    int n;
    char *env;
    char *var;
    int j;
    
    if (arg_num(arg) == 1)
    {
        i = 0;
        while (g_sh.env[i])
        {
            if (ft_strncmp(g_sh.env[i], "_=", 2))
            {
                var = extract_env(g_sh.env[i]);
                n = ft_strnchrn(g_sh.env[i], "=");
                ft_putstr_fd("declare -x ", 1);
                ft_putstr_fd(var, 1);
                if (n)
                {
                    ft_putchar_fd('=', 1);
                    ft_putstr_fd("\"", 1);
                    ft_putstr_fd(g_sh.env[i] + n + 1, 1);
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
            ft_putstr_fd("minishell: export: ",2);
            ft_putstr_fd(arg[i], 2);
            ft_putstr_fd(": not a valid identifier\n", 2);
            return 1;
        }
        env = extract_env(arg[i]);
        j = 0;
        while (env[j])
        {
            if (SPECIAL(env[j]) || env[j] == ' ')
            {
                ft_putstr_fd("minishell: export: ",2);
                ft_putchar_fd('`', 2);
                ft_putstr_fd(arg[i], 2);
                ft_putchar_fd('\'', 2);
                ft_putstr_fd(": not a valid identifier\n", 2);
                return 1;
            }
            j++;
        }
        if (env && ft_isdigit(env[0]))
        {
            ft_putstr_fd("minishell: export: ",2);
            ft_putchar_fd('`', 2);
            ft_putstr_fd(arg[i], 2);
            ft_putchar_fd('\'', 2);
            ft_putstr_fd(": not a valid identifier\n", 2);
            return 1;
        }
        if (ft_getenv(env))
            replace_env(arg[i]);
        else if (!ft_getenv(env))
        {
            if (check(env))
                add_env(arg[i]);
        }   
        i++;
    }
    return 0;
}

int check(char *env)
{
    int i;

    i = 0;
    while (env[i])
    {
        if (env[i] == '+' && env[i] != '=')
            return 0;
        i++;
    }
    return 1;
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
    g_sh.env = env;
}

void    replace_env(char *s)
{
    int i;
    char *str;
    int  n;
    char *val;
    
    i = 0;
    str = extract_env(s);
    n = ft_strnchrn(s, "+");
    while (g_sh.env[i])
    {
        if (n && s[n + 1] == '=')
        {
            val = ft_getenv(str);
            val = ft_strjoin(val, s + n + 2);
            s = ft_strjoin(str, "=");
            s = ft_strjoin(s, val);
        }
        if (ft_strncmp(g_sh.env[i], str, ft_strlen(str)) == 0)
            g_sh.env[i] = ft_strdup(s);
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
        if (s[j] == '=' || (s[j] == '+' && s[j + 1] == '='))
             break ;
        j++;
    }
    str = ft_substr(str, 0, j);
    return (str);
}