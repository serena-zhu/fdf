/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yazhu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 13:23:34 by yazhu             #+#    #+#             */
/*   Updated: 2018/01/24 19:32:55 by yazhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list *new;

	new = (t_list *)malloc(sizeof(t_list));
	if (new)
	{
		new->content = (void *)malloc(content_size);
		if (!new->content)
			return (NULL);
		if (!content)
		{
			new->content = NULL;
			content_size = 0;
		}
		else
			ft_memmove(new->content, content, content_size);
		new->content_size = content_size;
		new->next = NULL;
		return (new);
	}
	return (NULL);
}
