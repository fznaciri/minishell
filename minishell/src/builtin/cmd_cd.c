/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_cd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnaciri- <fnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 10:14:48 by fnaciri-          #+#    #+#             */
/*   Updated: 2021/01/04 11:11:19 by fnaciri-         ###   ########.fr       */
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
        // if (!ft_strncmp(arg[1], "~", 1))
        //     arg[1] = ft_strdup(getenv("HOME"));
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
    }
    else
    {
        write(1, "cd: No such file or directory:\n", 32);
        return (1);
    }    
    free(oldpwd);
    return 0;
}