/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnaciri- <fnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 10:27:05 by fnaciri-          #+#    #+#             */
/*   Updated: 2020/11/26 12:08:24 by fnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void    treat_line(char *line)
{
    int i;

    i = 0;
    g_cmd.arg = ft_split(line, ' ');
    while (g_cmd.arg[i])
    {
        printf("%s\n", g_cmd.arg[i]);
        i++;
    }  
}