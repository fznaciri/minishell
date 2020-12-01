/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnaciri- <fnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 18:22:50 by fnaciri-          #+#    #+#             */
/*   Updated: 2020/12/01 10:45:26 by fnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../../include/minishell.h"

int		is_separator(char c)
{
	if (c == '|' || c == ';')
		return (1);
	return (0);
}

static int		ft_countword(char *s)
{
	char	*str;
	int		i;
	int		wc;

	str = (char*)s;
	i = 0;
	wc = 0;
	if (!is_separator(str[i]))
		wc = 1;
	while (str[i])
	{
		if (is_separator(str[i]) && !is_separator(str[i + 1])&& str[i + 1])
			wc++;
		i++;
	}
	return (wc);
}

static	size_t	ft_wordlen(char *s, int i)
{
	size_t j;

	j = 0;
	while (!is_separator(s[i]) && s[i])
	{
		i++;
		j++;
	}
	return (j + 1);
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

char			**ft_split_cmd(char  *s)
{
	char	**words;
	int		wc;
	int		i;
	int		j;
	size_t	len;

	if (!s)
		return (NULL);
	wc = ft_countword((char*)s);
	if (!(words = malloc((wc + 1) * sizeof(char *))))
		return (NULL);
	i = 0;
	j = 0;
	while (j < wc && ((char*)s)[i])
	{
		while (is_separator(((char*)s)[i]) && ((char*)s)[i])
			i++;
		len = ft_wordlen((char*)s, i);
		if (!(words[j] = ft_substr(s, i, len)))
			return (ft_dealocate(&words, j));
		j++;
		i = i + len;
	}
	words[j] = NULL;
	return (words);
}
