/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnchrn.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnaciri- <fnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 11:26:44 by fnaciri-          #+#    #+#             */
/*   Updated: 2020/12/21 11:58:15 by fnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/utils.h"

int     ft_strnchrn(char *s, char *set)
{
    int i;
    int j;
    if (set[0] == '\0')
        return (0);
    i = 0;
    while (s[i])
    {
        j = 0;
        while (set[j])
        {
            if (s[i] == set[j])
                return i;
            j++;
        }
        i++;
    }
    return 0;
}