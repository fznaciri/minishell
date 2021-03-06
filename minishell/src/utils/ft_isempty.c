/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isempty.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnaciri- <fnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 12:16:57 by fnaciri-          #+#    #+#             */
/*   Updated: 2021/01/23 11:59:19 by fnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/utils.h"

int     ft_is_empty(char *s)
{
    int i;
    i = 0;
    while (s[i] && (s[i] == ' ' || s[i] == '\t'))
        i++;
    if (s[i])
        return 0;
    return 1;   
}