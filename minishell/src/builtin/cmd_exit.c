/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_exit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnaciri- <fnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 14:04:31 by fnaciri-          #+#    #+#             */
/*   Updated: 2021/01/28 19:12:28 by fnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int    cmd_exit(char **arg)
{
    long ex;
    char *s;
    int i;

    i = 0;
    if (arg[1])
    {
        s = skip_spaces(arg[1]);
        s = ft_strtrim(s, " \t");
        if (s[0] == '-' || s[0] == '+')
            i++;
        while(s[i])
        {
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
        if (arg_num(arg) > 2)
        {
            ex = 1;
            ft_putendl_fd("minishell: exit: too many arguments", 2);
            exit(ex);
        }
        ex = ft_latoi(s) % 256;
        // ft_putstr_fd("exit\n", 2);
        exit(ex);
    }
    else
        ex = 0;
    // ft_putstr_fd("exit\n", 2);
    exit(g_sh.status);
    return (ex);
}