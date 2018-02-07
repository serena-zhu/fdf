/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yazhu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 18:03:20 by yazhu             #+#    #+#             */
/*   Updated: 2017/11/29 17:39:16 by yazhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	begin;

	if (s)
	{
		str = (char *)malloc((len + 1) * sizeof(char));
		i = 0;
		begin = start;
		if (str)
		{
			while (i < len)
			{
				str[i] = s[begin + i];
				i++;
			}
			str[i] = '\0';
			return (str);
		}
	}
	return (NULL);
}
