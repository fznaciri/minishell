/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnaciri- <fnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 10:36:26 by fnaciri-          #+#    #+#             */
/*   Updated: 2020/11/26 18:17:50 by fnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	if (!(str = malloc(len + 1)))
		return (NULL);
	i = 0;
	j = len;
	while (s[start] != '\0' && i <= j - 1 && ft_strlen(s) >= start)
		str[i++] = s[start++];
	str[i] = '\0';
	return (str);
}
