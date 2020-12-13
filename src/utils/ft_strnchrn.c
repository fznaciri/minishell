/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnchrn.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnaciri- <fnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 11:26:44 by fnaciri-          #+#    #+#             */
/*   Updated: 2020/12/13 11:31:56 by fnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/utils.h"

int     ft_strnchrn(char *s, char *set)
{
    size_t  i;
    size_t  j;
    if (set[0] == '\0')
        return (0);
    i = 0;
    j = 0;
    while (s[i + j])
    {
        while (s[i + j] == set[j])
        {
            j++;
            if (set[j] == '\0')
                return (i);
        }
        j = 0;
        i++;
    }
    return 0;
}