/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_echo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnaciri- <fnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 10:12:02 by fnaciri-          #+#    #+#             */
/*   Updated: 2020/12/03 11:07:59 by fnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int		cmd_echo()
{
	char	*s;
	int		n;

	n = 0;
	if (!ft_strncmp(g_cmd->arg[1], "-n", 2))
	{
		n = 1;
		s = g_cmd->arg[2];
        skip_spaces(&s);
	}
    ft_putstr_fd(s, 1);
	if (!n)
        write(1, "\n", 1);
	return (0);
}

void skip_spaces(char **s)
{
    while (is_space(**s))
			(*s)++;
}

int is_space(char c)
{
    if (c == ' ' || c == '\t')
        return (1);
    return (0);
}