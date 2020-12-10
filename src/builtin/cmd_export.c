/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_export.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnaciri- <fnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 12:08:27 by fnaciri-          #+#    #+#             */
/*   Updated: 2020/12/10 14:32:51 by fnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int   cmd_export(char **arg)
{
    int i;
    char *env;
    
    i = 1;
    while (arg[i])
    {
        env = extract_env(arg[i]);
        if (ft_getenv(env))
            replace_env(arg[i]);
        else if (!ft_getenv(env))
            add_env(arg[i]);
        i++;
    }
    return 0;
}