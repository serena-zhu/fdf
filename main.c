/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yazhu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 11:03:49 by yazhu             #+#    #+#             */
/*   Updated: 2018/02/01 18:31:32 by yazhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_line(t_data *data)
{
	double	tmp;
	double	line_len;
	double	m;
	double	y_new;
	int		rgb;

	rgb = (255 << 16) | (255 << 8) | (255);
	tmp = data->x1;
	line_len = sqrt((data->x2 - data->x1) * (data->x2 - data->x1)
				+ (data->y2 - data->y1) * (data->y2 - data->y1));
	m = (data->y2 - data->y1) / (data->x2 - data->x1);
	while (tmp <= data->x2)
	{
		y_new = m * (tmp - data->x1) + data->y1;
		mlx_pixel_put(data->mlx, data->window, tmp, y_new, rgb);
		tmp += (data->x2 - data->x1) / line_len;
	}
}

void	get_two_pts_along_x(int x, int y, char **line_arr, t_data *data)
{
	double theta;

	theta = data->theta;
	data->z = ft_atoi(line_arr[x]) * data->sc;
	data->x1 = (x + y) * sin(theta) * data->sc + data->x0;
	data->y1 = (y - x) * cos(theta) * data->sc - data->z + data->y0;
	data->z = ft_atoi(line_arr[x + 1]) * data->sc;
	data->x2 = ((x + 1) + y) * sin(theta) * data->sc + data->x0;
	data->y2 = (y - (x + 1)) * cos(theta) * data->sc - data->z + data->y0;
}

void	get_next_point_along_y(int x, int y, char **line_arr2, t_data *data)
{
	double theta;

	theta = data->theta;
	data->z = ft_atoi(line_arr2[x]) * data->sc;
	data->x2 = (x + (y + 1)) * sin(theta) * data->sc + data->x0;
	data->y2 = (y + 1 - x) * cos(theta) * data->sc - data->z + data->y0;
}

void	draw_image(t_data *data, int x, int y)
{
	char **line_arr;
	char **line_arr2;

	while (y < (data->y_max - 1))
	{
		line_arr = ft_strsplit(data->map[y], ' ');
		line_arr2 = ft_strsplit(data->map[y + 1], ' ');
		x = 0;
		while (x < (data->x_max - 1))
		{
			get_two_pts_along_x(x, y, line_arr, data);
			draw_line(data);
			get_next_point_along_y(x, y, line_arr2, data);
			draw_line(data);
			x++;
		}
		free(line_arr);
		free(line_arr2);
		y++;
	}
}

int		exit_pgm(int key)
{
	if (key == 53)
	{
		//free data->map
		exit(0);
	}
	return (0);
}

void	find_max_z(char **line_arr, t_data *data)
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

int		process_map(char *map, t_data *data)
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

char	*read_map(int fd, t_data *data)
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

void	initialize_struct(t_data *data)
{
	data->map = NULL;
	data->x_max = 0;
	data->y_max = 0;
	data->z_max = 0;
	data->win_x = 1000;
	data->win_y = 1000;
	data->theta = M_PI / 3;
	data->sc = 1;
	data->x0 = 0;
	data->y0 = 0;
	data->x1 = 0;
	data->y1 = 0;
	data->x2 = 0;
	data->y2 = 0;
}

/*
**  This function calculates the max window size required to fit the full
**  image and scales all points such that the image would take up 80% of
**	the size of the window initially set in the data struct. The actual
**  window that is opened will be trimmed accordingly
**	The origin is then calcualted accordingly
*/

void	set_scale_and_origin(t_data *data)
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

int		main(int argc, char **argv)
{
	int		fd;
	int		ret;
	t_data	data;

	if (argc != 2)
		return (usage_error());
	if ((fd = open(argv[1], O_RDONLY)) < 0)
		return (map_file_error(argv[1]));
	initialize_struct(&data);
	if ((ret = process_map(read_map(fd, &data), &data)) != 0)
		return (map_errors(ret));
	set_scale_and_origin(&data);
	if (!(data.mlx = mlx_init()))
		return (close_fd_and_exit(fd, 1)); //free data.map also?
	data.window = mlx_new_window(data.mlx, data.win_x, data.win_y, argv[1]);
	draw_image(&data, 0, 0);
	mlx_key_hook(data.window, exit_pgm, (void *)0);
	mlx_loop(data.mlx);
	return (close_fd_and_exit(fd, 0)); //free data.map also?
}
