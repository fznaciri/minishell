/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnaciri- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 10:30:52 by fnaciri-          #+#    #+#             */
/*   Updated: 2019/10/21 18:13:45 by fnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*csrc;
	unsigned char	*cdst;

	i = 0;
	csrc = (unsigned char *)src;
	cdst = (unsigned char *)dst;
	while (i < n)
	{
		if (csrc[i] != (unsigned char)c)
			cdst[i] = csrc[i];
		else if (csrc[i] == (unsigned char)c)
		{
			cdst[i] = (unsigned char)c;
			return (cdst + i + 1);
		}
		i++;
	}
	return (NULL);
}
