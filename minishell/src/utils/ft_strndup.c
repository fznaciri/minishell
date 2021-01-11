/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnaciri- <fnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 11:01:06 by fnaciri-          #+#    #+#             */
/*   Updated: 2020/12/13 11:01:35 by fnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/utils.h"

char        *ft_strndup(const char *s1, size_t n)
{
    char    *ptr;
    size_t  i;
    i = ft_strlen(s1);
    if (n > i)
        ptr = (char *)malloc((i + 1) * sizeof(char));
    else
        ptr = (char *)malloc((n + 1) * sizeof(char));
    if (!ptr)
        return (NULL);
    i = 0;
    while (*(s1 + i) && n--)
    {
        *(ptr + i) = *(s1 + i);
        i++;
    }
    *(ptr + i) = '\0';
    return (ptr);
}