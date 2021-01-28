/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_exit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnaciri- <fnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 14:04:31 by fnaciri-          #+#    #+#             */
/*   Updated: 2021/01/28 18:09:40 by fnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int    cmd_exit(char **arg)
{
    int ex;
    char *s;
    int i;

    i = 0;
    if (arg_num(arg) > 2)
    {
        ex = 1;
        ft_putendl_fd("minishell: exit: too many arguments", 2);
        exit(ex);
    }
    if (arg[1])
    {
        s = ft_strtrim(arg[1], " \t\f\r");
        while(s[i])
        {
            if (s[0] == '-' || s[0] == '+')
                i++;
            
            if (ft_isdigit(s[i]))
                i++;
            else
            {
                // ft_putstr_fd("exit\n", 2);
                ft_putstr_fd("minishell: exit: ", 2);
                ft_putstr_fd(arg[1],2);
                ft_putendl_fd(": numeric argument required", 2);
                exit(255);
            }
        }       
        ex = ft_atoi(s) % 256;
        // ft_putstr_fd("exit\n", 2);
        exit(ex);
    }
    else
        ex = 0;
    // ft_putstr_fd("exit\n", 2);
    exit(g_sh.status);
    return (ex);
}