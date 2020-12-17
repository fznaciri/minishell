/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countcchar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnaciri- <fnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 14:01:27 by fnaciri-          #+#    #+#             */
/*   Updated: 2020/12/13 14:01:59 by fnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/utils.h"

int     ft_countchar(char *s, char c)
{
    int i;
    int j;
    i = 0;
    j = 0;
    while (s[i])
    {
        if (s[i] == c && s[i + 1] != c)
            j++;
        i++;
    }
    return j;
}