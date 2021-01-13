/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbrand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 13:36:07 by malbrand          #+#    #+#             */
/*   Updated: 2021/01/07 14:33:04 by malbrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*tmp;
	t_list	*ptr;

	if (!lst || !f || !del)
		return (NULL);
	if (!(tmp = ft_lstnew((*f)(lst->content))))
	{
		ft_lstclear(&tmp, del);
		return (NULL);
	}
	ptr = tmp;
	lst = lst->next;
	while (lst)
	{
		if ((tmp->next = ft_lstnew((*f)(lst->content))) == NULL)
		{
			ft_lstclear(&tmp, del);
			return (NULL);
		}
		lst = lst->next;
		tmp = tmp->next;
	}
	return (ptr);
}
