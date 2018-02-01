/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yazhu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 13:38:00 by yazhu             #+#    #+#             */
/*   Updated: 2018/01/31 21:03:32 by yazhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		close_fd_and_exit(int fd, int return_value)
{
	close(fd);
	return (return_value);
}

/*
** error [1] : no data in map
** error [2] : wrong line length
*/

int		map_errors(int error)
{
	if (error == 1)
		ft_putstr("No data found.\n");
	if (error == 2)
		ft_putstr("Found wrong line length. Exiting\n");
	return (1);
}

int		map_file_error(char *file_name)
{
	ft_putstr("No file maps/");
	ft_putendl(file_name);
	return (1);
}

int		usage_error(void)
{
	ft_putstr("Usage : ./fdf <filename>\n");
	return (1);
}
