/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnaciri- <fnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 12:55:51 by fnaciri-          #+#    #+#             */
/*   Updated: 2021/01/26 12:58:46 by fnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/utils.h"

int ft_argcmp(char **arg, char *s)
{
    int i;

    i = 0;
    while (arg[i])
    {
        if (ft_strnstr(arg[i], s , ft_strlen(arg[i])))
            return 1;
        i++;
    }
    return 0;
}
