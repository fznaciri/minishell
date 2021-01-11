/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnaciri- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 22:03:58 by fnaciri-          #+#    #+#             */
/*   Updated: 2019/10/25 17:03:59 by fnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *new;
	t_list *l;

	l = NULL;
	while (lst)
	{
		if (!(new = ft_lstnew(f(lst->next))))
		{
			ft_lstclear(&l, del);
			return (NULL);
		}
		ft_lstadd_back(&l, new);
		lst = lst->next;
	}
	return (l);
}
