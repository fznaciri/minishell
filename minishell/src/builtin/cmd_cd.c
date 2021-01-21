/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_cd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnaciri- <fnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 10:14:48 by fnaciri-          #+#    #+#             */
/*   Updated: 2021/01/21 12:36:01 by fnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int     cmd_cd(char **arg)
{
    // int n;
    char *oldpwd;
    char *pwd;
    char *tmp;
    
    // n = arg_num(arg);
    oldpwd = ft_strdup(ft_getenv("PWD") ? ft_getenv("PWD") : "");

     if (!arg[1])
    {
        if (!(arg[1] = ft_getenv("HOME")))
        {
            ft_putendl_fd("minishell: cd: HOME not set", 2);
            return 1;
        }
        arg[1] = ft_strdup(arg[1]);
    }
    // if (n == 1)
    // {
    //     arg[1] = ft_strdup(ft_getenv("HOME"));
    //     n++;
    // }
    if (arg[1] && ft_is_empty(arg[1]))
    {
        oldpwd = ft_strjoin("OLDPWD=", oldpwd);
        if (ft_getenv("OLDPWD"))
            replace_env(oldpwd);
        else
            add_env(oldpwd);
        return 1;
    }
        if (!chdir(arg[1]))
        {
            if (!(pwd = getcwd(NULL, 0)))
            {
                ft_putstr_fd("cd: error retrieving current directory: getcwd: cannot access parent directories: ", 2);
                ft_putendl_fd(strerror(errno), 2);
                pwd = ft_strdup(ft_getenv("PWD"));
                pwd = ft_strappend(pwd, '/');
                pwd = ft_strjoin(pwd, arg[1]);
            }
            tmp = pwd;
            pwd = ft_strjoin("PWD=", pwd);
            replace_env(pwd);
            free(tmp);
            tmp = oldpwd;
            oldpwd = ft_strjoin("OLDPWD=", oldpwd);
            if (ft_getenv("OLDPWD"))
                replace_env(oldpwd);
            else
                add_env(oldpwd);
            free(tmp);
            free(pwd);
        }
        else
        {
            ft_putstr_fd("minishell: cd: ", 2);
            ft_putstr_fd(arg[1], 2);
            ft_putstr_fd(": ", 2);
            ft_putstr_fd(strerror(errno), 2);
            write(2, "\n", 1);
            return 1;
        }  
   
    free(oldpwd);
    return 0;
}