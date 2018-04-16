/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yazhu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 18:57:46 by yazhu             #+#    #+#             */
/*   Updated: 2018/02/06 18:37:20 by yazhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		count_words(char const *s, char c)
{
	int i;
	int word_count;

	i = 0;
	word_count = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			word_count++;
		i++;
	}
	return (word_count);
}

static int		occupy_arr(char **arr, char const *s, char c)
{
	int	index[4];

	index[0] = 0;
	index[1] = 0;
	while (s[index[0]] != '\0')
	{
		if (s[index[0]] == c)
			index[0]++;
		else
		{
			index[3] = 0;
			index[2] = index[0];
			while (s[index[0]] != c && s[index[0]] != '\0')
			{
				index[3]++;
				index[0]++;
			}
			arr[index[1]] = (char *)malloc((index[3] + 1) * sizeof(char));
			if (!arr[index[1]])
				return (0);
			arr[index[1]] = ft_strncpy(arr[index[1]], s + index[2], index[3]);
			arr[index[1]++][index[3]] = '\0';
		}
	}
	return (1);
}

char			**ft_strsplit(char const *s, char c)
{
	int		word_count;
	char	**arr;

	if (s)
	{
		word_count = count_words(s, c);
		arr = (char **)malloc((word_count + 1) * sizeof(char *));
		if (!arr)
			return (NULL);
		if (occupy_arr(arr, s, c) == 0)
			return (NULL);
		arr[word_count] = (char *)NULL;
		return (arr);
	}
	return (NULL);
}
