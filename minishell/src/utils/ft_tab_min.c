/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_min.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnaciri- <fnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 11:27:46 by fnaciri-          #+#    #+#             */
/*   Updated: 2020/12/13 11:32:03 by fnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/utils.h"

int     ft_tab_min(int tab[], int i)
{
    int j;
    int min;
    j = 0;
    min = tab[j];
    while (j < i)
    {
        if (tab[j] < min)
            min = tab[j];
        j++;
    }
    if (min == 0)
    {
        j = 0;
        while (j < i)
        {
            if (tab[j] > min)
                return tab[j];
            j++;
        }
    }
    return min;
}