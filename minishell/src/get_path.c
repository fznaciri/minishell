/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnaciri- <fnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 18:19:25 by fnaciri-          #+#    #+#             */
/*   Updated: 2021/02/15 16:58:13 by fnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char    *get_path(char *s)
{
    struct stat buf;
    char **path;
    char *tmp;
    char *f_path;
    int i;

    i = 0;
    if (s[0] == '.' || is_builtins(s) || !ft_getenv("PATH") || ft_is_empty(s))
        return (ft_strdup(s));
    path = ft_splitt(ft_getenv("PATH"), ":");
    while (path[i])
    {
        f_path = ft_strjoin(path[i], "/");
        tmp = f_path;
        f_path = ft_strjoin(tmp, s);
        free(tmp);
        if (!stat(f_path, &buf))
            return f_path;
        free(f_path);
        i++;
    }
    return ft_strdup(s);
}

int     is_builtins(char *s)
{
    int i;

    i = 0;
    while (i < BUILTINS_NUM)
    {
        if (!ft_strncmp(s, builtins_str[i], ft_strlen(builtins_str[i])))
            return 1;
        i++;
    }
    return (0);
}