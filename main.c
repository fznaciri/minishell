/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnaciri- <fnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 14:01:47 by fnaciri-          #+#    #+#             */
/*   Updated: 2020/11/26 19:16:59 by fnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minishell.h"

void  prompt(void)
{
    // printf("\033[31;1m$>\033[0m");
}

int main(int ac, char **av, char **env)
{
    
    char *s;
    
    int status;

    
   
    status = 1;
    while (status)
    {
        s = ft_getenv(env, "PWD");
        write(1, "\033[0;31m", 8);
        write(1," ->", 3);
        write(1, s, strlen(s));
        write(1, "$> ", 3);
        write(1, "\033[0m", 5);
        gnl(0, &g_line);
        printf("%s\n", g_line);
        treat_line(g_line);
        free(g_line);
    }
    
    
    
    return(0);
}