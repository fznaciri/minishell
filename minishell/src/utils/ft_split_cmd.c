// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   ft_split_cmd.c                                     :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: fnaciri- <fnaciri-@student.42.fr>          +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2020/11/30 18:22:50 by fnaciri-          #+#    #+#             */
// /*   Updated: 2020/12/01 10:45:26 by fnaciri-         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include <stdlib.h>
#include "../../include/minishell.h"

// int		is_separator(char c)
// {
// 	if (c == '|' || c == ';')
// 		return (1);
// 	return (0);
// }

// static int		ft_countword(char *s)
// {
// 	char	*str;
// 	int		i;
// 	int		wc;

// 	str = (char*)s;
// 	i = 0;
// 	wc = 0;
// 	if (!is_separator(str[i]))
// 		wc = 1;
// 	while (str[i])
// 	{
// 		if (is_separator(str[i]) && !is_separator(str[i + 1])&& str[i + 1])
// 			wc++;
// 		i++;
// 	}
// 	return (wc);
// }

// static	size_t	ft_wordlen(char *s, int i)
// {
// 	size_t j;

// 	j = 0;
// 	while (!is_separator(s[i]) && s[i])
// 	{
// 		i++;
// 		j++;
// 	}
// 	return (j + 1);
// }

// static void		*ft_dealocate(char ***t, int i)
// {
// 	while (i >= 0)
// 	{
// 		free((*t)[i]);
// 		i--;
// 	}
// 	free(**t);
// 	return (NULL);
// }

// char			**ft_split_cmd(char  *s)
// {
// 	char	**words;
// 	int		wc;
// 	int		i;
// 	int		j;
// 	size_t	len;

// 	if (!s)
// 		return (NULL);
// 	wc = ft_countword((char*)s);
// 	if (!(words = malloc((wc + 1) * sizeof(char *))))
// 		return (NULL);
// 	i = 0;
// 	j = 0;
// 	while (j < wc && ((char*)s)[i])
// 	{
// 		while (is_separator(((char*)s)[i]) && ((char*)s)[i])
// 			i++;
// 		len = ft_wordlen((char*)s, i);
// 		if (!(words[j] = ft_substr(s, i, len)))
// 			return (ft_dealocate(&words, j));
// 		j++;
// 		i = i + len;
// 	}
// 	words[j] = NULL;
// 	return (words);
// }

int     is_seperator(char *s, int i, char *set)
{
    int j;
	int q;
	int sq;

    j = 0;
	q = 0;
	sq = 0;
    while (set[j])
    {
		if (s[i] == '\'' && !sq && !q)
            sq = 1;
        else if (s[i] == '\'' && sq )
            sq = 0;
        if (s[i] == '"' && !q && !sq)
            q = 1;
        else if (s[i] == '"' && q)
            q = 0;
        if (set[j] == s[i] && (s[(i - 1 < 0 ? 1 : i - 1)] != '\\' || !SPECIAL(s[i])))
			return 1;
        j++;
    }
    return 0;
}
static		int		ft_wordscount(const char *str, char *set)
{
	int		i;
	int		wc;
	char	*s;
	int		len;
	s = (char*)str;
	i = 0;
	wc = 0;
	len = ft_strlen(s);
	if (!is_seperator(s, i, set))
		wc++;
	while (i < len)
	{
		if (s[i] == 34 || s[i] == 39)
        {
            i++;
            while (s[i] != 34 && s[i] != 39 && s[i] != 0)
                i++;
        }
		if (is_seperator(s, i, set) && !is_seperator(s, i + 1, set) && s[i + 1])
			wc++;
		i++;
	}
	return (wc);
}
static	size_t		ft_wordlen(char *s, char *set, int i)
{
	int j;
	int len;
	j = 0;
	len = ft_strlen(s);
	while (i < len && !is_seperator(s, i, set) && s[i])
	{
		if (s[i] == 34 || s[i] == 39)
        {
            i++;
			j++;
            while (s[i] != 34 && s[i] != 39  && s[i] != 0)
			{
                i++;
				j++;
			}
        }
		j++;
		i++;
	}
	if (i < len && SPECIAL (s[i]))
		j++;
	return (j);
}
static	void		*ft_dealocate(char ***tab, int i)
{
	while (i >= 0)
	{
		free((*tab)[i]);
		i--;
	}
	free(**tab);
	return (NULL);
}
char				**ft_splitt(char const *s, char *set)
{
	char	**words;
	int		i;
	int		j;
	int		wc;
	size_t	len;
	i = 0;
	j = 0;
	wc = 0;
	if (!((char*)s))
		return (NULL);
	wc = ft_wordscount((char*)s, set);
	if (!(words = malloc((wc + 1) * sizeof(char*))))
		return (NULL);
	while (j < wc && ((char*)s)[i])
	{
		while (is_seperator(((char*)s), i, set) && ((char*)s)[i])
			i++;
		len = ft_wordlen((char*)s, set, i);
		if (!(words[j] = ft_substr((char*)s, i, len)))
			return (ft_dealocate(&words, j));
		j++;
		i = i + len;
	}
	words[j] = NULL;
	return (words);
}