/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 11:20:29 by malbrand          #+#    #+#             */
/*   Updated: 2021/01/07 16:13:01 by malbrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t			ft_count(char const *s, char c)
{
	size_t		i;
	size_t		nb_word;

	i = 0;
	nb_word = 0;
	while (s[i])
	{
		if ((s[i - 1] != c && s[i] == c && i != 0) ||
			(s[i] != c && s[i + 1] == '\0'))
			nb_word++;
		i++;
	}
	return (nb_word);
}

static size_t			ft_charset(char const *s, char c, size_t i)
{
	while (s[i])
	{
		if (c == s[i])
			i++;
		else
			return (i);
	}
	return (i);
}

static size_t			ft_str(char const *s, char c, size_t i)
{
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (i);
}

static char				**ft_free(char **ret, size_t line)
{
	size_t x;

	x = 0;
	while (x < line)
	{
		free(ret[x]);
		x++;
	}
	free(ret);
	return (NULL);
}

char					**ft_split(char const *s, char c)
{
	char		**ret;
	size_t		x;
	size_t		y;
	size_t		i_str;
	size_t		i_charset;

	x = 0;
	i_str = 0;
	if (!(ret = (char **)malloc(sizeof(char *) * ft_count(s, c) + 1)))
		return (NULL);
	while (x < (ft_count(s, c)))
	{
		y = -1;
		i_charset = ft_charset(s, c, i_str);
		i_str = ft_str(s, c, i_charset);
		if (!(ret[x] = (char*)malloc(sizeof(char) * (i_str - i_charset) + 1)))
			return (ft_free(ret, x));
		while (i_charset <= i_str)
			ret[x][++y] = s[i_charset++];
		ret[x][y] = '\0';
		x++;
	}
	ret[x] = NULL;
	return (ret);
}
