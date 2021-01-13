/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 11:13:57 by malbrand          #+#    #+#             */
/*   Updated: 2021/01/04 11:17:14 by malbrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char const	*ft_strnstr(char const *str, char const *to_find, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (to_find[0] == '\0')
		return (str);
	j = ft_strlen(to_find);
	while (str[i] && i <= len - j)
	{
		if (ft_strncmp(&str[i], to_find, j) == 0)
			return (&str[i]);
		i++;
	}
	return (NULL);
}
