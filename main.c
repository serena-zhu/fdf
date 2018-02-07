/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yazhu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 11:03:49 by yazhu             #+#    #+#             */
/*   Updated: 2018/02/06 19:35:48 by yazhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		exit_pgm(int key, t_data *data)
{
	if (key == 53)
	{
		free_line_arr(data->map, 0);
		exit(0);
	}
	return (0);
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
	read_map(fd, &data);
	if ((ret = process_map(&data)) != 0)
		return (map_errors(ret, fd, &data));
	set_scale_and_origin(&data);
	if (!(data.mlx = mlx_init()))
		return (close_free_and_exit(fd, &data, 1));
	data.window = mlx_new_window(data.mlx, data.win_x, data.win_y, argv[1]);
	draw_image(&data, -1, -1);
	mlx_key_hook(data.window, exit_pgm, &data);
	mlx_loop(data.mlx);
	return (close_free_and_exit(fd, &data, 0));
}
