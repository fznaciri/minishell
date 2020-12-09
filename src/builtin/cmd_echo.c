/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_echo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnaciri- <fnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 10:12:02 by fnaciri-          #+#    #+#             */
/*   Updated: 2020/12/09 12:27:58 by fnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int		cmd_echo(char **arg)
{
	int i;
	int		n;

	n = 0;
	if (arg[1])
		if (!ft_strncmp(arg[1], "-n", 2))
			n = 1;
	// if (n)
	// {
		i = 1;
		while (arg[i + n])
		{
			ft_putstr_fd(arg[i + n], 1);
			if (arg[i + n + 1])
				write(1, " ", 1);
			i++;
		}
	// }
	// else
    // 	print_arg(g_cmd->arg + 1);
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