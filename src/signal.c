/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnaciri- <fnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 10:28:28 by fnaciri-          #+#    #+#             */
/*   Updated: 2020/12/19 12:29:11 by fnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void sig_handler(int signum)
{
    if (signum == SIGINT)
    {
        write(1, "\n", 1);
        prompt();
    }       
    else if (signum == SIGQUIT)
    {
        kill(g_sh.pid, SIGQUIT);
    }
        // exit(0);
}