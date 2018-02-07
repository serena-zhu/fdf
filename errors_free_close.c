/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_free_close.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yazhu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 17:54:52 by yazhu             #+#    #+#             */
/*   Updated: 2018/02/06 19:35:18 by yazhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		free_line_arr(char **line_arr, int return_value)
{
	int j;

	if (line_arr)
	{
		j = 0;
		while (line_arr[j] != '\0')
			ft_strdel(&line_arr[j++]);
		free(line_arr);
	}
	return (return_value);
}

int		close_free_and_exit(int fd, t_data *data, int return_value)
{
	close(fd);
	return (free_line_arr(data->map, return_value));
}

/*
** error [1] : no data in map
** error [2] : wrong line length
*/

int		map_errors(int error, int fd, t_data *data)
{
	if (error == 1)
		ft_putstr("No data found.\n");
	if (error == 2)
		ft_putstr("Found wrong line length. Exiting\n");
	free_line_arr(data->map, 0);
	close(fd);
	return (1);
}

int		map_file_error(char *file_name)
{
	ft_putstr("No file ");
	ft_putendl(file_name);
	return (1);
}

int		usage_error(void)
{
	ft_putstr("Usage : ./fdf <filename>\n");
	return (1);
}
