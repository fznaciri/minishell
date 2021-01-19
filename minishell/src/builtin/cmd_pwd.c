/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_pwd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnaciri- <fnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 13:47:47 by fnaciri-          #+#    #+#             */
/*   Updated: 2021/01/19 14:42:01 by fnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int  cmd_pwd(char **arg)
{
    char *pwd;

    if (!(pwd = getcwd(NULL, 0)))
    {
        pwd = ft_getenv("PWD");
    }
    ft_putstr_fd(pwd, 1);
    write(1, "\n", 1);
    return (0);
}