/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_free_close.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yazhu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 17:54:52 by yazhu             #+#    #+#             */
/*   Updated: 2018/02/02 17:54:56 by yazhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_map(t_data *data)
{
	int j;

	j = 0;
	while (j < data->y_max)
		free(data->map[j++]);
	free(data->map);
}

int		close_free_and_exit(int fd, t_data *data, int return_value)
{
	close(fd);
	free_map(data);
	return (return_value);
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
	if (data->map)
		free_map(data);
	close(fd);
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
