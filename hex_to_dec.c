/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_to_dec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yazhu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 15:23:38 by yazhu             #+#    #+#             */
/*   Updated: 2018/02/02 17:53:19 by yazhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
**	This function will convert the provided rgb in hex to decimal. If there is
**  no color specified or if input is not a valid hex value, then function
**  will return 1 and the default color (white) will be used.
*/

static int		is_in_base(char c)
{
	return ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z')
													|| (c >= 'A' && c <= 'Z'));
}

int				hex_to_dec(char *s)
{
	int i;
	int nbr;

	i = 0;
	nbr = 0;
	if (s[i] == '0' && (s[i + 1] == 'x' || s[i + 1] == 'X'))
		i = 2;
	while (is_in_base(s[i]))
	{
		if (s[i] >= 'a' && s[i] <= 'z')
			nbr = nbr * 16 + (s[i] - 'a' + 10);
		else if (s[i] >= 'A' && s[i] <= 'Z')
			nbr = nbr * 16 + (s[i] - 'A' + 10);
		else if (s[i] >= '0' && s[i] <= '9')
			nbr = nbr * 16 + (s[i] - '0');
		i++;
	}
	if (i == 0)
		return (-1);
	return (nbr);
}
