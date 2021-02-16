/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_echo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnaciri- <fnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 10:12:02 by fnaciri-          #+#    #+#             */
/*   Updated: 2021/02/15 17:06:12 by fnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int		cmd_echo(char **arg)
{
	int i;
	int		n;
	char *p;
	int l;
	
	n = 0;
	i = 1;
	while (arg[i] && !ft_strncmp(arg[i], "-n", 2))
	{
		n = 1;
		i++;		
	}
	if (n)
		i--;		
	while (arg[i + n])
	{
		// ft_putstr_fd(arg[i + n], 1);
		// if (arg[i + n + 1])
		// 	write(1, " ", 1);
		// i++;
		p = ft_strtrim(arg[i + n], " ");
        l = 0;
        while (p[l])
        {
            while (p[l] && (p[l] == ' ' || p[l] == '\t'))
                l++;
            if (l - 1 >= 0 && (p[l - 1] == ' ' || p[l - 1] == '\t'))
                write(1, " ", 1);
            if (p[l])
                write(1, p + l, 1);
            l++;
        }
        if (arg[i + n + 1])
            ft_putstr_fd(" ", 1);
        i++;
	}
	if (!n)
        write(1, "\n", 1);
	return (0);
}

char *skip_spaces(char *s)
{
	int i;

	i = 0;
    while (s[i] && is_space(s[i]))
			i++;
	return (s + i);
}

int is_space(char c)
{
    if (c == ' ' || c == '\t' || c == '\r' || c == '\f')
        return (1);
    return (0);
}