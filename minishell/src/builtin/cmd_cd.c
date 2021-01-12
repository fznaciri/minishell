/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_cd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnaciri- <fnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 10:14:48 by fnaciri-          #+#    #+#             */
/*   Updated: 2021/01/12 12:17:00 by fnaciri-         ###   ########.fr       */
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
            pwd = getcwd(NULL, 0);
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
    else
    {
        write(2, "cd: No such file or directory:\n", 32);
        return (1);
    }    
    free(oldpwd);
    return 0;
}