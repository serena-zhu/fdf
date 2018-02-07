/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yazhu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 17:57:17 by yazhu             #+#    #+#             */
/*   Updated: 2018/02/06 16:41:56 by yazhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		get_pts_along_x(int x, int y, char **line_arr, t_data *data)
{
	double	theta;
	int		i;
	int		tmp;

	i = 0;
	theta = data->theta;
	data->z = ft_atoi(line_arr[x]) * data->sc;
	while (line_arr[x][i] != '\0' && line_arr[x][i] != ',')
		i++;
	if (line_arr[x][i++] == ',' && (tmp = hex_to_dec(&line_arr[x][i])) >= 0)
		data->color1 = tmp;
	data->x1 = (x + y) * sin(theta) * data->sc + data->x0;
	data->y1 = (y - x) * cos(theta) * data->sc - data->z + data->y0;
	if (x < (data->x_max - 1) && !(i = 0))
	{
		data->z = ft_atoi(line_arr[x + 1]) * data->sc;
		while (line_arr[x + 1][i] != '\0' && line_arr[x + 1][i] != ',')
			i++;
		if (line_arr[x + 1][i++] == ','
							&& (tmp = hex_to_dec(&line_arr[x + 1][i])) >= 0)
			data->color2 = tmp;
		data->x2 = ((x + 1) + y) * sin(theta) * data->sc + data->x0;
		data->y2 = (y - (x + 1)) * cos(theta) * data->sc - data->z + data->y0;
	}
}

static void		get_next_point_along_y(int x, int y, char **line_arr2,
																t_data *data)
{
	double	theta;
	int		i;
	int		tmp;

	i = 0;
	theta = data->theta;
	data->z = ft_atoi(line_arr2[x]) * data->sc;
	while (line_arr2[x][i] != '\0' && line_arr2[x][i] != ',')
		i++;
	if (line_arr2[x][i++] == ',' && (tmp = hex_to_dec(&line_arr2[x][i])) >= 0)
		data->color2 = tmp;
	data->x2 = (x + (y + 1)) * sin(theta) * data->sc + data->x0;
	data->y2 = ((y + 1) - x) * cos(theta) * data->sc - data->z + data->y0;
}

/*
**	option [1] : reset color1 only
**  option [2] : reset color2 only
**  option [3] : reset both colors
*/

static int		reset_default_color(t_data *data, int option)
{
	if (option == 1 || option == 3)
		data->color1 = (255 << 16) | (255 << 8) | (255);
	if (option == 2 || option == 3)
		data->color2 = data->color1;
	return (1);
}

/*
**	l_a2 = line_arr2
*/

void			draw_image(t_data *data, int x, int y)
{
	char **line_arr;
	char **l_a2;

	while (++y < (data->y_max) && (x = -1) == -1)
	{
		line_arr = ft_strsplit(data->map[y], ' ');
		((y + 1) < data->y_max) ? l_a2 = ft_strsplit(data->map[y + 1], ' ') : 0;
		while (++x < (data->x_max))
		{
			if (x < (data->x_max - 1) && reset_default_color(data, 3))
			{
				get_pts_along_x(x, y, line_arr, data);
				draw_line(data);
			}
			if (y < (data->y_max - 1) && reset_default_color(data, 2))
			{
				if (x == (data->x_max - 1) && reset_default_color(data, 1))
					get_pts_along_x(x, y, line_arr, data);
				get_next_point_along_y(x, y, l_a2, data);
				draw_line(data);
			}
		}
		free_line_arr(line_arr, 0);
		((y + 1) < data->y_max) ? free_line_arr(l_a2, 0) : 0;
	}
}
