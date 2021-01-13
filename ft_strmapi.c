/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 13:23:48 by malbrand          #+#    #+#             */
/*   Updated: 2021/01/04 13:24:48 by malbrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*ret;
	size_t	i;

	if (!s || !f)
		return (NULL);
	if (s)
	{
		ret = ft_strdup(s);
		if (ret == NULL)
			return (NULL);
		i = 0;
		while (ret[i])
		{
			ret[i] = f((unsigned int)i, ret[i]);
			i++;
		}
		return (ret);
	}
	else
		return (NULL);
}
