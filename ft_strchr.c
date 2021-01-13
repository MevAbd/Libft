/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 16:15:58 by malbrand          #+#    #+#             */
/*   Updated: 2021/01/04 11:10:12 by malbrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(char const *str, int c)
{
	char		*ret;
	size_t		i;
	size_t		len;

	i = -1;
	len = ft_strlen(str);
	ret = (char *)str;
	if (c == '\0')
	{
		ret = &ret[len];
		return (ret);
	}
	if (c)
	{
		while (ret[++i])
		{
			if (ret[i] == c)
			{
				ret = &ret[i];
				return (ret);
			}
		}
		return (NULL);
	}
	return (NULL);
}
