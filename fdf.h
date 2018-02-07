/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yazhu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 15:45:10 by yazhu             #+#    #+#             */
/*   Updated: 2018/02/06 19:35:31 by yazhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <math.h>
# include <fcntl.h>
# include "get_next_line.h"
# include "libft/libft.h"
# include "minilibx/minilibx_macos_elcapitan/mlx.h"

/*
**	sc : scale
*/

typedef struct	s_data
{
	char		**map;
	int			x_max;
	int			y_max;
	int			z_max;
	int			win_x;
	int			win_y;
	int			color1;
	int			color2;
	double		theta;
	double		sc;
	double		x0;
	double		y0;
	double		z;
	double		x1;
	double		y1;
	double		x2;
	double		y2;
	void		*mlx;
	void		*window;
}				t_data;

int				hex_to_dec(char *s);
int				close_free_and_exit(int fd, t_data *data, int return_value);
int				map_errors(int errors, int fd, t_data *data);
int				map_file_error(char *file_name);
int				usage_error(void);
int				free_line_arr(char **line_arr, int return_value);
void			draw_line(t_data *data);
void			draw_image(t_data *data, int x, int y);
void			set_scale_and_origin(t_data *data);
int				process_map(t_data *data);
void			read_map(int fd, t_data *data);
void			initialize_struct(t_data *data);
int				main(int argc, char **argv);

#endif
