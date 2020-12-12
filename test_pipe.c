/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnaciri- <fnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 10:58:41 by fnaciri-          #+#    #+#             */
/*   Updated: 2020/12/12 11:40:34 by fnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <sys/wait.h>

//  ping -c 4 "google.com" | grep "rpu"  ping: /sbin/ping  grep: /usr/bin/grep
// ps aux | grep root | grep /usr/sbin stdin -> wp| rd ->
int main()
{
    pid_t pid1;
    pid_t pid2;
    pid_t pid3;
    int   status;
    int pipe1[2];
    int pipe2[2];
    char *a[]= {"ps", "aux", NULL};
    char *b[]= {"grep", "root", NULL};
    char *c[]= {"grep", "/usr/sbin", NULL};

    if (pipe(pipe1) == -1)
    {
      perror("bad pipe1");
      exit(1);
    }
    if (pipe(pipe2) == -1)
    {
      perror("bad pipe2");
      exit(1);
    }
    if ((pid1 = fork()) == -1) 
    {
      perror("bad fork");
       exit(1);
    }
    else if (pid1 == 0)
    {
      dup2(pipe1[1], 1);
      close(pipe1[0]);
      close(pipe1[1]);
      close(pipe2[1]);
      close(pipe2[0]);
      execve("/bin/ps", a, NULL);
      perror("bad exec ps");
      exit(1);
    }
  
    if ((pid2 = fork()) == -1)
    {
        perror("bad fork2");
        exit(1);
    } 
    else if (pid2 == 0)
    {
        dup2(pipe1[0], 0);
        dup2(pipe2[1], 1);
        close(pipe1[0]);
        close(pipe1[1]);
        close(pipe2[1]);
        close(pipe2[0]);
        execve("/usr/bin/grep", b, NULL);
        perror("bad exec grep");
        exit(1);
    }
    if ((pid3 = fork()) == -1)
    {
        perror("bad fork3");
        exit(1);
    } 
    else if (pid3 == 0)
    {
      dup2(pipe2[0], 0);
        close(pipe1[0]);
        close(pipe1[1]);
        close(pipe2[1]);
        close(pipe2[0]);
        execve("/usr/bin/grep", c, NULL);
        perror("bad exec grep");
        exit(1);
    }
    close(pipe1[0]);
    close(pipe1[1]);
    close(pipe2[0]);
    close(pipe2[1]);
    waitpid(pid1, &status, 0);
    waitpid(pid2, &status, 0);
    waitpid(pid3, &status, 0);
    return 0;
}