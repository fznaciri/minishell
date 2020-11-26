/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnaciri- <fnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 14:23:48 by fnaciri-          #+#    #+#             */
/*   Updated: 2020/11/25 14:23:55 by fnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/utils.h"

char	*ft_strchr(const char *s, int c)
{
	char *str;

	str = (char*)s;
	if (!s)
		return (NULL);
	if (!c)
		return (str + ft_strlen(s));
	while (*str)
	{
		if (*str == c)
			return (str);
		str++;
	}
	return (NULL);
}
