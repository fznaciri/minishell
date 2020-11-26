/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnaciri- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 19:11:41 by fnaciri-          #+#    #+#             */
/*   Updated: 2019/10/24 20:45:07 by fnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int		ft_countword(char const *s, char c)
{
	char	*str;
	int		i;
	int		wc;

	str = (char*)s;
	i = 0;
	wc = 0;
	if (str[i] != c)
		wc = 1;
	while (str[i])
	{
		if (str[i] == c && str[i + 1] != c && str[i + 1] != '\0')
			wc++;
		i++;
	}
	return (wc);
}

static	size_t	ft_wordlen(char *s, int i, char c)
{
	size_t j;

	j = 0;
	while (s[i] != c && s[i])
	{
		i++;
		j++;
	}
	return (j);
}

static void		*ft_dealocate(char ***t, int i)
{
	while (i >= 0)
	{
		free((*t)[i]);
		i--;
	}
	free(**t);
	return (NULL);
}

char			**ft_split(char const *s, char c)
{
	char	**words;
	int		wc;
	int		i;
	int		j;
	size_t	len;

	if (!s)
		return (NULL);
	wc = ft_countword((char*)s, c);
	if (!(words = malloc((wc + 1) * sizeof(char *))))
		return (NULL);
	i = 0;
	j = 0;
	while (j < wc && ((char*)s)[i])
	{
		while (((char*)s)[i] == c && ((char*)s)[i])
			i++;
		len = ft_wordlen((char*)s, i, c);
		if (!(words[j] = ft_substr(s, i, len)))
			return (ft_dealocate(&words, j));
		j++;
		i = i + len;
	}
	words[j] = NULL;
	return (words);
}
