/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnaciri- <fnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 10:56:00 by fnaciri-          #+#    #+#             */
/*   Updated: 2021/01/04 10:56:18 by fnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/utils.h"

char    *ft_strappend(char *str, char c)
{
    char *s;
    int l;
    int i;
    if (!str)
    {
        s = malloc(sizeof(char) * 2);
        s[0] = c;
        s[1] = 0;
        return s;
    }
    l = ft_strlen(str);
    s = malloc(sizeof(char) * (l + 2));
    i = 0;
    while (i < l)
    {
        s[i] = str[i];
        i++;
    }
    s[i] = c;
    i++;
    s[i] = 0;
    return s;
}