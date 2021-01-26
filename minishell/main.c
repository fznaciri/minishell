/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnaciri- <fnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 14:01:47 by fnaciri-          #+#    #+#             */
/*   Updated: 2021/01/26 15:22:55 by fnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minishell.h"

void prompt()
{
    write(2, "\033[1;32m", 8);
    write(2,"minishell-1.0", 14);
    write(2, "$> ", 3);
    write(2, "\033[0m", 5); 
}

void inc_shlvl()
{
    int i;
    char *s;
    char *v;

    i = 0;
    v = ft_getenv("SHLVL");
    if (v)
        i = ft_atoi(ft_getenv("SHLVL"));
    else
        i = ft_atoi(ft_strdup(""));
    i++;
    s = ft_strjoin("SHLVL=", ft_itoa(i));
    if (!v)
        add_env(s);
    else
        replace_env(s);
}

void set_env()
{
    char * pwd;
    if (!(pwd = ft_getenv("PWD")))
    {
        if(!(pwd = getcwd(NULL, 0)))
            pwd = ft_strdup("");
        pwd = ft_strjoin("PWD=", pwd);
        add_env(pwd);
    }
}

void    set_lastcmd(t_cmd *cmd)
{
    t_cmd *lcmd;
    char *s;
    int n;
    
    if (!ft_strcmp(cmd->cmd, "echo") && ft_argcmp(cmd->arg, "$_") && cmd->prev)
        lcmd = cmd->prev;
    else if (!ft_strcmp(cmd->cmd, "echo") && !ft_argcmp(cmd->arg, "$_"))
        lcmd = NULL;
    else
        lcmd = cmd;
    if (lcmd)
    {
        n = arg_num(lcmd->arg);
        if (lcmd->prev && lcmd->prev->op && !ft_strcmp(lcmd->prev->op, "|"))
            s = ft_strjoin("_=", ft_strdup(""));
        else
            s = ft_strjoin("_=", ft_strdup(lcmd->arg[n - 1]));
        remove_env("_");
        add_env(s);
    }
}

int main(int ac, char **av, char **env)
{
    int i = 0;
    int status;
    char *r;
    int c;
    
    g_sh.in = dup(0);
    g_sh.out = dup(1);
    status = 1; 
    init_env(env);
    inc_shlvl();
    remove_env("OLDPWD");
    set_env();
    init_builtins();
    signal(SIGINT,sig_handler);
    signal(SIGQUIT,sig_handler);
    if (ac == 3 && !ft_strcmp(av[1], "-c"))
    {
        g_line = ft_strdup(av[2]);
        c = 1;
    }
    while (status)
    {
        if (!c)
        {
            prompt();
            gnl(0, &g_line);
        }
        if ((r = check_syntax(g_line)))
        {
            ft_putendl_fd(r, 2);
            g_sh.status = 258;
        }    
        if (!r)
        {
            treat_line(g_line);
            // print_cmd(g_cmd);
            // printf("--------------\n");
            open_pipe();
            g_sh.status = execute(g_cmd);
            // printf("%s\n", g_line);
            close_pipe();
            ft_cmd_clear(&g_cmd);
        }
        r = 0;
        free(g_line);
        if (c)
            break ;
    }
    return(g_sh.status);
}