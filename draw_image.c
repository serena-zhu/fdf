/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yazhu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 17:57:17 by yazhu             #+#    #+#             */
/*   Updated: 2018/02/02 17:59:50 by yazhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		draw_line(t_data *data)
{
	double	tmp;
	double	line_len;
	double	m;
	double	y_new;
	int		rgb;

	rgb = data->color1;
	tmp = data->x1;
	line_len = sqrt((data->x2 - data->x1) * (data->x2 - data->x1)
				+ (data->y2 - data->y1) * (data->y2 - data->y1));
	m = (data->y2 - data->y1) / (data->x2 - data->x1);
	while (tmp <= data->x2)
	{
		y_new = m * (tmp - data->x1) + data->y1;
		mlx_pixel_put(data->mlx, data->window, tmp, y_new, rgb);
		tmp += (data->x2 - data->x1) / line_len;
		rgb += (data->color2 - data->color1) / line_len;
	}
}

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

void			draw_image(t_data *data, int x, int y)
{
	char **line_arr;
	char **line_arr2;

	while (++y < (data->y_max) && (x = -1) == -1)
	{
		line_arr = ft_strsplit(data->map[y], ' ');
		line_arr2 = ft_strsplit(data->map[y + 1], ' ');
		while (++x < (data->x_max))
		{
			if (x < (data->x_max - 1))
			{
				get_pts_along_x(x, y, line_arr, data);
				draw_line(data);
			}
			if (y < (data->y_max - 1))
			{
				if (x == (data->x_max - 1))
					get_pts_along_x(x, y, line_arr, data);
				get_next_point_along_y(x, y, line_arr2, data);
				draw_line(data);
			}
		}
		free(line_arr);
		free(line_arr2);
	}
}
