/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnaciri- <fnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 10:20:46 by fnaciri-          #+#    #+#             */
/*   Updated: 2021/02/02 17:01:20 by fnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/utils.h"

char     *ft_strnchr(char *s, char *set)
{
    size_t  i;
    size_t  j;
    int len;
    if (set[0] == '\0')
        return (0);
    i = 0;
    j = 0;
    len = ft_strlen(s);
    while (s[i + j])
    {
        // if (s[i + j] == '"')
        // {
        //  i++;
        //  while (s[i + j] && s[i + j] != '"')
        //      i++;
        // }
        while (s[i + j] && s[i + j] == set[j])
        {
            j++;
            if (set[j] == '\0')
                return (s + i);
            while (s[i+j] == ' ' || s[i + j] == '\t')
                i++;
        }
        j = 0;
        i++;
    }
    return NULL;
}