/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yazhu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 10:55:36 by yazhu             #+#    #+#             */
/*   Updated: 2017/11/30 14:34:40 by yazhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		count_digits(long long nbr)
{
	int digits;

	digits = 0;
	if (nbr == 0)
		return (1);
	while (nbr > 0)
	{
		digits++;
		nbr /= 10;
	}
	return (digits);
}

char			*ft_itoa(int n)
{
	long long	nbr;
	int			neg;
	int			digits;
	char		*str;

	nbr = (n < 0) ? (long long)n * -1 : n;
	neg = (n < 0) ? 1 : 0;
	digits = count_digits(nbr);
	str = (char *)malloc((digits + neg + 1) * sizeof(char));
	if (str)
	{
		str[neg + digits--] = '\0';
		while ((digits + neg) >= 0)
		{
			str[neg + digits--] = (nbr % 10) + '0';
			nbr /= 10;
		}
		str[0] = (n < 0) ? '-' : str[0];
		return (str);
	}
	return (NULL);
}
