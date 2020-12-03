/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_cd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnaciri- <fnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 10:14:48 by fnaciri-          #+#    #+#             */
/*   Updated: 2020/12/03 14:41:32 by fnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void    cmd_cd()
{
    char *pwd;
    
}

// int		run_cd(t_minishell *minishell)
// {
// 	char	*error;

// 	if (!ft_strcmp(minishell->commands->data, ""))
// 	{
// 		minishell->commands->data = ft_strdup(
// get_env_value(minishell->env_variables, "HOME"));
// 	}
// 	errno = 0;
// 	if (chdir(minishell->commands->data) < 0)
// 	{
// 		error = strerror(errno);
// 		write_msg_error(minishell->name, minishell->commands->name, error);
// 		return (-1);
// 	}
// 	free(minishell->path);
// 	minishell->path = NULL;
// 	minishell->path = getcwd(minishell->path, 0);
// 	return (0);
// }