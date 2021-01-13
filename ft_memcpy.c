/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 18:27:21 by malbrand          #+#    #+#             */
/*   Updated: 2020/11/19 18:28:21 by malbrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*cpy_src;
	unsigned char	*cpy_dest;
	size_t			i;

	cpy_src = (unsigned char *)src;
	cpy_dest = (unsigned char *)dest;
	i = 0;
	if (!dest && !src)
		return (NULL);
	while (i < n)
	{
		cpy_dest[i] = cpy_src[i];
		i++;
	}
	dest = (void *)cpy_dest;
	return (dest);
}
