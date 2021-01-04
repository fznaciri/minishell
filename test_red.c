/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_red.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnaciri- <fnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 11:38:41 by fnaciri-          #+#    #+#             */
/*   Updated: 2021/01/04 10:28:10 by fnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minishell.h"

t_red    *treat_red(char *pipeline)
{
    int i;
    char *red_type;
    t_red *red;
    t_red *red_list
    i = 0;
    while (pipeline[i])
    {
        if (pipeline[i] == '<')
            red_type = ft_strdup("<");
        if (pipeline[i] == '>')
            red_type = ft_strdup(">");
        if (pipeline[i] == '>>')
            red_type = ft_strdup(">>");
    }
    if (red_type)
    {
        red = ft_red_new(red_type; extract(pipeline + i + 1));
        ft_red_add_back(&red_list, red);
    }
    return (red_list)
}

char  *extract(char *s)
{
    int i;
    int j;
    char *str;
    
    i = 0;
    j = 0;
    while (s[i] == ' ')
        i++;
    while(s && s[i] != ' ')
    {
        str[j] = s[i];
        i++;
        j++;
    }
    return (ft_strdup(str));
}

