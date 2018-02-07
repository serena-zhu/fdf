/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yazhu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 19:05:35 by yazhu             #+#    #+#             */
/*   Updated: 2018/02/05 19:10:26 by yazhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		increment_color(int color1, int color2, double delta)
{
	int	r;
	int	g;
	int	b;
	int	rgb;

	r = (1.0 - delta) * (color1 / 256 / 256 % 256)
									+ delta * (color2 / 256 / 256 % 256);
	g = (1.0 - delta) * (color1 / 256 % 256) + delta * (color2 / 256 % 256);
	b = (1.0 - delta) * (color1 % 256) + delta * (color2 % 256);
	rgb = (r << 16) | (g << 8) | (b);
	return (rgb);
}

void			draw_line(t_data *data)
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
		rgb = increment_color(rgb, data->color2,
								(tmp - data->x1) / (data->x2 - data->x1));
	}
}
