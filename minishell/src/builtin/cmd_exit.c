/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_exit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnaciri- <fnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 14:04:31 by fnaciri-          #+#    #+#             */
/*   Updated: 2021/01/12 11:16:24 by fnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int    cmd_exit(char **arg)
{
    int ex;
    int i;

    i = 0;
    if (arg_num(arg) > 2)
    {
        ex = 1;
        ft_putstr_fd("bash: exit: too many arguments\n", 2);
        exit(ex);
    }
    if (arg[1])
    {
        while(arg[1][i])
        {
            if (arg[1][0] == '-')
                i++;
            if (ft_isdigit(arg[1][i]))
                i++;
            else
            {
                ft_putstr_fd("exit\n", 2);
                ft_putstr_fd("bash: exit: ", 2);
                ft_putstr_fd(arg[1],2);
                ft_putstr_fd(": numeric argument required", 2);
                exit(255);
            }
        }       
        ex = ft_atoi(arg[1]) % 256;
        ft_putstr_fd("exit\n", 2);
        exit(ex);
    }
    else
        ex = 0;
    ft_putstr_fd("exit\n", 2);
    exit(g_sh.status);
    return (ex);
}