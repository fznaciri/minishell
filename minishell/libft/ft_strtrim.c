/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnaciri- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 10:54:41 by fnaciri-          #+#    #+#             */
/*   Updated: 2019/10/24 20:43:38 by fnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	strstart(char *s, char *set)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] == set[j] && set[j])
		{
			j = 0;
			i++;
		}
		else if (set[j] == '\0')
			break ;
		else
			j++;
	}
	return (i);
}

static size_t	strend(char *s, char *set)
{
	size_t j;
	size_t l;

	l = ft_strlen(s) - 1;
	j = 0;
	while (l > 0)
	{
		if (s[l] == set[j] && set[j])
		{
			j = 0;
			l--;
		}
		else if (set[j] == '\0')
			break ;
		else
			j++;
	}
	return (l);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	char	*s;
	char	*t;
	size_t	i;
	size_t	l;
	char	*str;

	if (!s1 || !set)
		return (NULL);
	s = (char *)s1;
	t = (char *)set;
	i = strstart(s, t);
	l = strend(s, t);
	if (i == ft_strlen(s1))
	{
		str = (char *)malloc(1);
		str[0] = 0;
		return (str);
	}
	str = ft_substr(s1, i, (l - i + 1));
	return (str);
}
