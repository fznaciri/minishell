/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strremove.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnaciri- <fnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 14:00:32 by fnaciri-          #+#    #+#             */
/*   Updated: 2021/02/20 16:27:25 by fnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/utils.h"

// char    *ft_strremove(char *s, char c)
// {
//     int l;
//     int i;
//     char *new;
//     l = 0;
//     l = ft_countchar(s, c);
//     if (!l)
//         return ft_strdup(s);
//     new = malloc(sizeof(char) * (ft_strlen(s) - l + 1));
//     l = 0;
//     i = 0;
//     while (s[l])
//     {
//         if (s[l] != c)
//         {
//             new[i] = s[l];
//             i++;
//         }
//         // else if (s[l + 1] == c)
//         // {
//         //     new[i] = s[l];
//         //     i++;
//         // }
//         l++;
//     }
//     new[i] = 0;
//             // printf("%s\n", new);
//     return new;
// }
int     count_backslash(char *str)
{
    int i;
    int j;
    int sq;
    
    sq = 0;
    i = ft_strlen(str) - 1;
    j = 0;
    while (i >= 0)
    {
        if (str[i] == '\'' && !sq)
            sq = 0;
        else if (str[i] == '\'' && sq)
            sq = 0;
        if (str[i] == '\\' && !sq)
            j++;
        else if (str[i] != '\\')
            break; 
        i--;
    }
    return j;
}
char    *ft_strremove(char *s, char c)
{
    int l;
    int q;
    int sq;
    int i;
    char *new;
    l = 0;
    q = 0;
    sq = 0;
    // l = ft_countcahr(s, c);
    // if (!l)
    // //   return ft_strdup(s);
    // if (ft_strlen(s) ==  l)
    //  return ft_strdup("");
    if (!(new = malloc(sizeof(char) * (ft_strlen(s)  + 1))))
        return NULL;
    l = 0;
    i = 0;
    // printf("|%s|\n", s);
    while (s[l])
    {
        // printf("%c\n", s[l]);
        if (s[l] == '"' && !q && !sq)
            q = 1;
        else if (s[l] == '"' && q)
            q = 0;
        if (s[l] == '\'' && !sq && !q)
            sq = 1;
        else if (s[l] == '\'' && sq)
            sq = 0;
        if (c == '"' && s[l] == c && ((s[l - 1 > 0 ? l - 1 : 0] == '\\' && count_backslash(ft_strndup(s, l)) % 2 != 0) || sq)) 
        {
            new[i] = s[l];
            i++;
        }
        if ((c == '\'' && s[l] == c) && q)
        {
            new[i] = s[l];
            i++;
        }
        if (c == '\\' && s[l] == c && (sq || (s[l - 1 > 0 ? l - 1 : 0] == '\\' && count_backslash(ft_strndup(s, l)) % 2 != 0)))
        {
            new[i] = s[l];
            i++;
        }
        if ((s[l] != '\\' && c == '\\') || (s[l] != '"' && c == '"') || (s[l] != '\'' && c == '\''))
        {
            //printf("f\\\n");
            new[i] = s[l];
            i++;
        }
        // if ((s[l] != c) || (s[l] == c && q && c != '"') || (c == '\\' && (s[l + 1] == c) )) // ""
        // {
        //  new[i] = s[l];
        //  i++;
        // }
        // else if ((s[l - 1 > 0 ? l - 1 : 0] == '\\' && is_specialcar(s[l]) && c != '\''))
        // {
        //  new[i] = s[l];
        //  i++;
        // }
        l++;
    }
    new[i] = 0;
    if (s)
    {
        free(s);
        s = NULL;
    }
    // printf("%c | |%s|\n", c, new);
    return new;
}

char    *ft_putbackslash(char *s)
{
    int i;
    int j;
    int q;
    int sq;
    char *new;
    i = 0;
    q = 0;
    sq = 0;
    j = 0;
    if (!s[0])
        return (ft_strdup(s));
    new = NULL;
    while (s[i])
    {
        if (s[i] == '\'' && !sq && !q)
            sq = 1;
        else if (s[i] == '\'' && sq )
            sq = 0;
        if (s[i] == '"' && !q && !sq)
            q = 1;
        else if (s[i] == '"' && q)
            q = 0;
        if ((s[i] == '"' && sq) || (s[i] == '\\' && sq) || (s[i] == '\\' && s[i +1] != '\\' && s[i + 1] != '"' && s[i + 1] != '$' && q))
        {
            new = ft_strappend(new, '\\');
            j++;
        }
        new = ft_strappend(new, s[i]);
        i++;
    }
    if (s[0] != '\0')
        new[i + j] = 0;
    // printf("%s\n", new);
    return new;
}

