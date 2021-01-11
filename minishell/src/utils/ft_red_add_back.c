/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_red_add_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnaciri- <fnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 10:23:10 by fnaciri-          #+#    #+#             */
/*   Updated: 2020/12/13 10:50:28 by fnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/utils.h"

void	ft_red_add_back(t_red **red, t_red *new)
{
	t_red *tmp;

	tmp = *red;
	if (tmp)
	{
		tmp = ft_red_last(tmp);
		tmp->next = new;
	}
	else
		*red = new;
}