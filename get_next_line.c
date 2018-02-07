/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yazhu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 12:05:33 by yazhu             #+#    #+#             */
/*   Updated: 2018/02/06 19:23:12 by yazhu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		has_line(t_struct *files, const int fd)
{
	while (files[fd].buf[files[fd].i] != '\n'
			&& files[fd].buf[files[fd].i] != '\0')
		files[fd].i++;
	if (files[fd].buf[files[fd].i] == '\0')
	{
		files[fd].i = 0;
		return (0);
	}
	files[fd].buf[files[fd].i] = '\0';
	files[fd].i++;
	return (1);
}

static char		*resize_str(char *str, int i, int n)
{
	char *new_str;

	if (!(new_str = ft_strnew((size_t)(n * BUFF_SIZE))))
		return (NULL);
	new_str = ft_strcpy(new_str, str + i);
	if (n > 2)
		ft_strdel(&str);
	return (new_str);
}

static char		*keep_reading(t_struct *files, const int fd)
{
	int		ret;
	int		n;
	char	*tmp;
	char	*tmp2;

	n = 1;
	while (!files[fd].line && !files[fd].end)
	{
		tmp2 = (++n == 2) ? files[fd].buf : tmp;
		if (!(tmp = resize_str(tmp2, files[fd].i, n)))
			return (NULL);
		ft_bzero(files[fd].buf, (size_t)BUFF_SIZE);
		if ((ret = read(fd, files[fd].buf, BUFF_SIZE)) < 0)
			return (NULL);
		files[fd].i = 0;
		files[fd].line = (ret == 0 && tmp[0] != '\0') ? 1 : has_line(files, fd);
		if (ret == 0 && tmp[0] == '\0' && (files[fd].end = 1))
		{
			ft_strdel(&files[fd].buf);
			ft_strdel(&tmp);
			return (NULL);
		}
		tmp = ft_strcat(tmp, files[fd].buf);
	}
	return (tmp);
}

static int		start_reading(t_struct *files, const int fd)
{
	int ret;

	if (!(files[fd].buf = ft_strnew((size_t)BUFF_SIZE)))
		return (-1);
	files[fd].i = 0;
	files[fd].end = 0;
	if ((ret = read(fd, files[fd].buf, BUFF_SIZE)) < 0)
		return (-1);
	if (ret == 0)
	{
		files[fd].end = 1;
		ft_strdel(&files[fd].buf);
		return (0);
	}
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	static t_struct files[8192];
	int				n;

	n = -1;
	if (!line)
		return (-1);
	*line = NULL;
	if (fd < 0 || fd >= 8192)
		return (-1);
	if ((!(files[fd].buf) || files[fd].end == 1)
		&& ((n = start_reading(files, fd)) != 1))
		return (n);
	files[fd].buf = ft_strcpy(files[fd].buf, files[fd].buf + files[fd].i);
	files[fd].i = 0;
	if ((files[fd].line = has_line(files, fd)) == 0)
	{
		*line = keep_reading(files, fd);
		if (files[fd].end == 1)
			return (0);
		if (!*line)
			return (-1);
	}
	else
		*line = ft_strdup(files[fd].buf);
	return (1);
}
