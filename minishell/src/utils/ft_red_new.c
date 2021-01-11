/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_red_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnaciri- <fnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 10:03:58 by fnaciri-          #+#    #+#             */
/*   Updated: 2020/12/13 10:05:40 by fnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/utils.h"
#include <stdlib.h>

t_red	*ft_red_new(void *red_type, char *file)
{
	t_red	*new;

	if (!(new = malloc(sizeof(t_red))))
		return (NULL);
	new->red_type = red_type;
    new->file = file;
	new->next = NULL;
	return (new);
}