/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yazhu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 18:23:32 by yazhu             #+#    #+#             */
/*   Updated: 2017/11/29 18:10:16 by yazhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	int		k;
	char	*str;

	if (s)
	{
		i = 0;
		while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && s[i] != '\0')
			i++;
		j = (int)ft_strlen(s) - 1;
		while ((s[j] == ' ' || s[j] == '\n' || s[j] == '\t') && j > i)
			j--;
		str = (char *)malloc((j - i + 1 + 1) * sizeof(char));
		k = 0;
		if (str)
		{
			while (i <= j)
				str[k++] = s[i++];
			str[k] = '\0';
			return (str);
		}
	}
	return (NULL);
}
