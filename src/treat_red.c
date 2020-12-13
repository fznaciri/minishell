/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_red.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnaciri- <fnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 10:30:25 by fnaciri-          #+#    #+#             */
/*   Updated: 2020/12/13 11:00:14 by fnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_red    *treat_red(char *pipeline)
{
    int i;
    char *red_type;
    t_red *red;
    t_red *red_list;
    i = 0;
    
    while (pipeline[i])
    {
        if (pipeline[i] == '>' && pipeline[i + 1] == '>')
            red_type = ft_strdup(">>");
         if (pipeline[i] == '<')
            red_type = ft_strdup("<");
        else if (pipeline[i] == '>')
            red_type = ft_strdup(">");
        if (red_type)
        {
            red = ft_red_new(red_type, extract_file(pipeline + i + 1, " ><"));
            ft_red_add_back(&red_list, red);
        }
        i++;
    }
    return (red_list);
}

char  *extract_file(char *s, char *set)
{
    int i;
    int j;
    char *str;
    
    i = 0;
    j = 0;
    while (s[i] == ' ')
        i++;
    while(s[i])
    {
        if (ft_strrchr(set, s[i]))
            break ;
        i++;
    }
    return (ft_strndup(s, i));
}