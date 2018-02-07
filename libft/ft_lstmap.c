/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yazhu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 12:38:18 by yazhu             #+#    #+#             */
/*   Updated: 2018/01/02 22:25:13 by yazhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *tmp;
	t_list *tmp2;
	t_list *new;

	if (!lst || !f)
		return (NULL);
	tmp = lst;
	if (!(new = f(lst)))
		return (NULL);
	tmp = new;
	while (lst->next)
	{
		if (!(tmp2 = f(lst->next)))
			return (NULL);
		tmp->next = tmp2;
		lst = lst->next;
		tmp = tmp->next;
	}
	return (new);
}
