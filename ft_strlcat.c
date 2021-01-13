/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 11:11:32 by malbrand          #+#    #+#             */
/*   Updated: 2021/01/04 11:11:45 by malbrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, char const *src, size_t size)
{
	size_t i;
	size_t lensrc;
	size_t lendest;

	i = 0;
	lensrc = ft_strlen(src);
	lendest = ft_strlen(dest);
	if (size <= lendest)
		lensrc += size;
	else
		lensrc += lendest;
	if (size > lendest)
	{
		while (src[i] && (lendest + 1) < size)
		{
			dest[lendest] = src[i];
			i++;
			lendest++;
		}
	}
	dest[lendest] = '\0';
	return (lensrc);
}
