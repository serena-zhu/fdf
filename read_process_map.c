/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_process_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yazhu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 18:01:02 by yazhu             #+#    #+#             */
/*   Updated: 2018/02/02 18:05:52 by yazhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
**  This function calculates the max window size required to fit the full
**  image and scales all points such that the image would take up 80% of
**	the size of the window initially set in the data struct. The actual
**  window that is opened will be trimmed accordingly
**	The origin is then calcualted accordingly
*/

void			set_scale_and_origin(t_data *data)
{
	double	max_width;
	double	max_height;
	int		padding;

	padding = 40;
	max_width = (data->x_max + data->y_max) * sin(data->theta);
	max_height = (data->x_max + data->y_max) * cos(data->theta) + data->z_max;
	data->sc = 0.8 * data->win_x / max_width;
	if (0.8 * data->win_y / max_height < data->sc)
		data->sc = 0.8 * data->win_y / max_height;
	data->x0 += padding / 2;
	data->y0 = (data->x_max * cos(data->theta) + data->z_max) * data->sc;
	data->y0 += padding / 2;
	data->win_x = max_width * data->sc + padding;
	data->win_y = max_height * data->sc + padding;
}

static void		find_max_z(char **line_arr, t_data *data)
{
	int i;
	int	z;

	i = 0;
	while (line_arr[i] != '\0')
	{
		z = ft_atoi(line_arr[i]);
		if (z > data->z_max)
			data->z_max = z;
		i++;
	}
}

int				process_map(char *map, t_data *data)
{
	int		j;
	int		width;
	char	**line_arr;

	j = 0;
	data->map = ft_strsplit(map, '\n');
	while (data->map[j] != '\0')
		j++;
	if (j != data->y_max || data->y_max == 0)
		return (1);
	j = 0;
	while (j < data->y_max && !(width = 0))
	{
		line_arr = ft_strsplit(data->map[j], ' ');
		find_max_z(line_arr, data);
		while (line_arr[width] != '\0')
			width++;
		if (j == 0 && width == 0)
			return (1);
		(j == 0) ? data->x_max = width : 0;
		if (j++ > 0 && width < data->x_max)
			return (2);
		free(line_arr);
	}
	return (0);
}

char			*read_map(int fd, t_data *data)
{
	char	*line;
	char	*tmp;
	char	*map;

	map = ft_strnew(0);
	while (get_next_line(fd, &line) == 1)
	{
		tmp = map;
		map = ft_strnew(ft_strlen(tmp) + ft_strlen(line) + 1);
		map = ft_strcpy(map, tmp);
		map = ft_strcat(map, line);
		map[ft_strlen(tmp) + ft_strlen(line)] = '\n';
		free(tmp);
		free(line);
		data->y_max++;
	}
	return (map);
}

void			initialize_struct(t_data *data)
{
	data->map = NULL;
	data->x_max = 0;
	data->y_max = 0;
	data->z_max = 0;
	data->win_x = 1000;
	data->win_y = 1000;
	data->color1 = (255 << 16) | (255 << 8) | (255);
	data->color2 = data->color1;
	data->theta = M_PI / 3;
	data->sc = 1;
	data->x0 = 0;
	data->y0 = 0;
	data->x1 = 0;
	data->y1 = 0;
	data->x2 = 0;
	data->y2 = 0;
}
