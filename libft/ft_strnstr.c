/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yazhu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 16:21:34 by yazhu             #+#    #+#             */
/*   Updated: 2017/11/27 16:53:17 by yazhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t i;
	size_t j;

	i = 0;
	if (to_find[0] == '\0')
		return ((char *)str);
	while (str[i] != '\0' && i < len)
	{
		j = 0;
		if (str[i] == to_find[j])
		{
			while (to_find[j] != '\0' && (i + j) < len)
			{
				if (to_find[j] != str[i + j])
					break ;
				j++;
			}
		}
		if (to_find[j] == '\0')
			break ;
		i++;
	}
	if (str[i] == '\0' || i == len)
		return (NULL);
	return ((char *)&str[i]);
}
