/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_red.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnaciri- <fnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 11:38:41 by fnaciri-          #+#    #+#             */
/*   Updated: 2020/12/12 14:59:01 by fnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <sys/wait.h>
#include <fcntl.h>
#include "include/minishell.h"

int main(int ac, char **av)
{
    // pid_t pid;
    int i;
    // int fd0;
    // int fd1;
    int in;
    int out;
    char *input;
    char *output;
    // int status;
    int j;
    
    in = 0;
    out = 0;
    
        i = 1;
        while (av[i])
        {
            
            if (av[i][0] == '<')
            {
                av[i] = NULL;
                input = (av[i + 1]);
                printf("in: %s\n", input);
                in++;
                j = i;
                while (av[j - 1])
                {
                    av[j] = av[j + 2];
                    j++;
                }  
            }   
            if (av[i][0] == '>')
            {
                av[i] = NULL;
                output = (av[i + 1]);
                printf("out: %s\n", output);
                out++;
                j = i;
                printf("j:%d\n", j);
                while (av[j - 1])
                {
                    av[j] = av[j + 2];
                    j++;
                }
            } 
            printf("av[%d]: %s\n", i, av[i]);
            i++;
        }
    return 0;
}