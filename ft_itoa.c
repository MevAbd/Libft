/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 11:22:17 by malbrand          #+#    #+#             */
/*   Updated: 2021/01/05 11:37:20 by malbrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_nblen(int n)
{
	int	nblen;

	if (n == 0)
		return (2);
	nblen = 0;
	nblen = n < 0 ? nblen + 1 : nblen;
	while (n < 0 || n > 0)
	{
		n = n / 10;
		nblen++;
	}
	return (nblen + 1);
}

char			*ft_itoa(int n)
{
	int				nblen;
	int				i;
	char			*ret;
	unsigned int	nbr;

	i = n < 0 ? 1 : 0;
	nbr = n < 0 ? -n : n;
	nblen = ft_nblen(n);
	if (!(ret = (char *)malloc(sizeof(char) * nblen)))
		return (NULL);
	ret[--nblen] = '\0';
	if (n == 0)
	{
		ret[0] = '0';
		return (ret);
	}
	ret[0] = n < 0 ? '-' : 0;
	while (nblen > i)
	{
		ret[--nblen] = nbr % 10 + '0';
		nbr = nbr / 10;
	}
	return (ret);
}
