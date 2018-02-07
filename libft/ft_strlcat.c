/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yazhu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 16:03:34 by yazhu             #+#    #+#             */
/*   Updated: 2017/11/30 19:54:58 by yazhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t len;

	i = 0;
	len = 0;
	while (dst[len] && len < size)
		len++;
	if (len == size)
		return (size + ft_strlen(src));
	while (src[i] != '\0')
	{
		if (i < (size - len - 1))
			dst[len + i] = src[i];
		else
			break ;
		i++;
	}
	dst[len + i] = '\0';
	return (len + ft_strlen(src));
}
