/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_cd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnaciri- <fnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 10:14:48 by fnaciri-          #+#    #+#             */
/*   Updated: 2021/01/19 12:53:13 by fnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int     cmd_cd(char **arg)
{
    int n;
    char *oldpwd;
    char *pwd;
    char *tmp;
    
    n = arg_num(arg);
    oldpwd = getcwd(NULL, 0);
    if (n == 1)
    {
        arg[1] = ft_strdup(getenv("HOME"));
        n++;
    }
    if (n == 2)
    {
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
            replace_env(oldpwd);
            free(tmp);
            free(pwd);
        }
        else
        {
            ft_putstr_fd("-bash: cd: ", 2);
            ft_putstr_fd(arg[1], 2);
            ft_putstr_fd(": ", 2);
            ft_putstr_fd(strerror(errno), 2);
            write(2, "\n", 1);
            return 1;
        }  
    }    
    free(oldpwd);
    return 0;
}