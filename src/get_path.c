/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnaciri- <fnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 18:19:25 by fnaciri-          #+#    #+#             */
/*   Updated: 2020/12/01 18:21:14 by fnaciri-         ###   ########.fr       */
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
    path = ft_split(ft_getenv("PATH"), ':');
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
    return NULL;
}