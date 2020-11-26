/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnaciri- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 19:51:10 by fnaciri-          #+#    #+#             */
/*   Updated: 2019/10/23 19:58:33 by fnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *substr, size_t len)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	if (!(*substr))
		return ((char *)str);
	while (i < len && str[i])
	{
		if (str[i] == substr[0])
		{
			j = 1;
			while (substr[j] && str[i + j] == substr[j] && i + j < len)
				j++;
			if (substr[j] == '\0')
				return ((char *)str + i);
		}
		i++;
	}
	return (NULL);
}
