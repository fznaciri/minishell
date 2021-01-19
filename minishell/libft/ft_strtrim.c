/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnaciri- <fnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 10:54:41 by fnaciri-          #+#    #+#             */
/*   Updated: 2021/01/19 16:13:42 by fnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

// static size_t	strstart(char *s, char *set)
// {
// 	size_t i;
// 	size_t j;

// 	i = 0;
// 	j = 0;
// 	while (s[i])
// 	{
// 		if (s[i] == set[j] && set[j])
// 		{
// 			j = 0;
// 			i++;
// 		}
// 		else if (set[j] == '\0')
// 			break ;
// 		else
// 			j++;
// 	}
// 	return (i);
// }

// static size_t	strend(char *s, char *set)
// {
// 	size_t j;
// 	size_t l;

// 	l = ft_strlen(s) - 1;
// 	j = 0;
// 	while (l > 0)
// 	{
// 		if (s[l] == set[j] && set[j])
// 		{
// 			j = 0;
// 			l--;
// 		}
// 		else if (set[j] == '\0')
// 			break ;
// 		else
// 			j++;
// 	}
// 	return (l);
// }

// char			*ft_strtrim(char const *s1, char const *set)
// {
// 	char	*s;
// 	char	*t;
// 	size_t	i;
// 	size_t	l;
// 	char	*str;

// 	if (!s1 || !set)
// 		return (NULL);
// 	s = (char *)s1;
// 	t = (char *)set;
// 	i = strstart(s, t);
// 	l = strend(s, t);
// 	if (i == ft_strlen(s1))
// 	{
// 		str = (char *)malloc(1);
// 		str[0] = 0;
// 		return (str);
// 	}
// 	str = ft_substr(s1, i, (l - i + 1));
// 	return (str);
// }
static char	*ft_ctrim(char *s2, char *s3)
{
	char	*rtn;
	int		i;
	i = (unsigned long)s3 - (unsigned long)s2 + 1;
	rtn = (char*)malloc(sizeof(char) * (i + 1));
	if (rtn == NULL)
		return (NULL);
	i = 0;
	while (s2 != s3)
	{
		rtn[i] = *s2;
		i++;
		s2++;
	}
	rtn[i] = *s2;
	rtn[i + 1] = '\0';
	return (rtn);
}
static char	*f(void)
{
	char *s;
	s = (char*)malloc(sizeof(char) * 1);
	if (!s)
		return (NULL);
	*s = '\0';
	return (s);
}
char		*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	char	*s3;
	char	*s2;
	if (!s1 || !set)
		return (NULL);
	s2 = (char*)s1;
	s3 = (char*)s1 + ft_strlen(s1) - 1;
	i = -1;
	while (set[++i])
		if (*s2 == set[i])
		{
			s2++;
			i = -1;
		}
	i = -1;
	while (set[++i])
		if (*s3 == set[i])
		{
			s3--;
			i = -1;
		}
	return (!(*s2) ? f() : ft_ctrim(s2, s3));
}