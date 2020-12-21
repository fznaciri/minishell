/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnaciri- <fnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 14:01:47 by fnaciri-          #+#    #+#             */
/*   Updated: 2020/12/21 12:17:11 by fnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minishell.h"

void prompt()
{
    char *s;

    s = getcwd(NULL, 0);
    write(1, "\033[0;31m", 8);
    write(1," ->", 3);
    write(1, s, strlen(s));
    write(1, "$> ", 3);
    write(1, "\033[0m", 5); 
}

void inc_shlvl()
{
    int i;
    char *s;

    i = ft_atoi(getenv("SHLVL"));
    i++;
    s = ft_strjoin("SHLVL=", ft_itoa(i));
    replace_env(s);
}

int main(int ac, char **av, char **env)
{
    int i = 0;
    int status;
    
    g_sh.in = dup(0);
    g_sh.out = dup(1);
    status = 1; 
    init_env(env);
    inc_shlvl();
    init_builtins();
    signal(SIGINT,sig_handler);
    signal(SIGQUIT,sig_handler);
    while (status)
    {
        prompt();
        gnl(0, &g_line);
        // printf("%s\n", g_line);
        treat_line(g_line);
        // print_cmd(g_cmd);
        open_pipe();
        g_sh.status = execute(g_cmd);
        close_pipe();
        ft_cmd_clear(&g_cmd);
        free(g_line);
    }
    return(0);
}