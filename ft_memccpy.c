/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 11:07:51 by malbrand          #+#    #+#             */
/*   Updated: 2021/01/05 11:51:46 by malbrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*cpy_src;
	unsigned char	*cpy_dest;
	size_t			i;

	cpy_src = (unsigned char *)src;
	cpy_dest = (unsigned char *)dest;
	i = 0;
	while (i < n)
	{
		cpy_dest[i] = cpy_src[i];
		if (cpy_dest[i] == (unsigned char)c)
			return (&cpy_dest[i + 1]);
		i++;
	}
	return (NULL);
}
