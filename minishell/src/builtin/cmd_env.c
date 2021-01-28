/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnaciri- <fnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 13:56:02 by fnaciri-          #+#    #+#             */
/*   Updated: 2021/01/28 17:22:38 by fnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int cmd_env(char **arg)
{
    int i;

    i = 0;
    replace_env(ft_strdup("_=env"));
    while(g_sh.env[i])
    {
        if (ft_strchr(g_sh.env[i], '='))
            ft_putendl_fd(g_sh.env[i], 1);
        i++;
    }
    return(0);
}