/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnaciri- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 11:47:03 by fnaciri-          #+#    #+#             */
/*   Updated: 2019/10/23 16:44:13 by fnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_intsize(int n)
{
	int				size;
	unsigned int	nb;

	nb = n;
	size = 0;
	if (n < 0)
	{
		nb = -n;
		size++;
	}
	while (nb >= 10)
	{
		nb = nb / 10;
		size++;
	}
	return (size + 1);
}

char		*ft_itoa(int n)
{
	char			*s;
	int				size;
	int				i;
	unsigned int	nb;

	nb = n;
	size = ft_intsize(n);
	if (!(s = malloc(sizeof(char) * size + 1)))
		return (NULL);
	i = size - 1;
	s[i + 1] = '\0';
	if (n < 0)
	{
		s[0] = '-';
		nb = -n;
	}
	while (nb >= 10 && i >= 0)
	{
		s[i] = nb % 10 + '0';
		nb = nb / 10;
		i--;
	}
	if (nb <= '9')
		s[i] = nb + '0';
	return (s);
}
