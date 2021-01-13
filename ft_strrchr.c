/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 16:16:50 by malbrand          #+#    #+#             */
/*   Updated: 2021/01/13 13:07:08 by malbrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(char const *str, int c)
{
	size_t	len;
	char	*ret;

	len = ft_strlen(str);
	ret = (char *)str;
	if (c == '\0')
		return (&ret[len]);
	if (c)
	{
		while (len > 0)
		{
			len--;
			if (ret[len] == c)
			{
				ret = &ret[len];
				return (ret);
			}
		}
		return (NULL);
	}
	return (NULL);
}
