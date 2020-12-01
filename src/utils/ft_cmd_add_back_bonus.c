/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd_add_back_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnaciri- <fnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 18:19:11 by fnaciri-          #+#    #+#             */
/*   Updated: 2020/12/01 10:30:54 by fnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/utils.h"

void	ft_cmd_add_back(t_cmd **alst, t_cmd *new)
{
	t_cmd *tmp;

	tmp = *alst;
	if (tmp)
	{
		tmp = ft_cmd_last(tmp);
		tmp->next = new;
	}
	else
		*alst = new;
}
