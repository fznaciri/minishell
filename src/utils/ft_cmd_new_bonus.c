/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd_new_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnaciri- <fnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 16:02:58 by fnaciri-          #+#    #+#             */
/*   Updated: 2020/12/01 10:30:26 by fnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/utils.h"
#include <stdlib.h>

t_cmd	*ft_cmd_new(void *cmd, char **arg, char *op)
{
	t_cmd	*new;

	if (!(new = malloc(sizeof(t_cmd))))
		return (NULL);
	new->cmd = cmd;
    new->arg = arg;
    new->op = op;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}
