/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strremove.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnaciri- <fnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 14:00:32 by fnaciri-          #+#    #+#             */
/*   Updated: 2021/01/13 15:00:21 by fnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/utils.h"

char    *ft_strremove(char *s, char c)
{
    int l;
    int i;
    char *new;
    l = 0;
    l = ft_countchar(s, c);
    if (!l)
        return ft_strdup(s);
    new = malloc(sizeof(char) * (ft_strlen(s) - l + 1));
    l = 0;
    i = 0;
    while (s[l])
    {
        if (s[l] != c)
        {
            new[i] = s[l];
            i++;
        }
        // else if (s[l + 1] == c)
        // {
        //     new[i] = s[l];
        //     i++;
        // }
        l++;
    }
    new[i] = 0;
    return new;
}