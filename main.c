/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnaciri- <fnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 14:01:47 by fnaciri-          #+#    #+#             */
/*   Updated: 2020/11/26 13:12:34 by fnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minishell.h"

void  prompt(void)
{
    printf("\033[31;1m$>\033[0m");
}

int main(int ac, char **av, char **env)
{
    
    char *s;
    int i;

    i = 0;
    s = ft_getenv(env, "PWD");
    printf("\033[31;1m-> %s\033[0m", s);
    prompt();
    gnl(0, &g_line);
    // treat_line(g_line);
    // free(g_line);
    return(0);
}