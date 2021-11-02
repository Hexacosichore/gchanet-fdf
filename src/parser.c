/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchanet <gchanet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 17:44:32 by gchanet           #+#    #+#             */
/*   Updated: 2021/10/21 11:10:18 by gchanet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static int	parse_ptstovertex(char **pts, t_fdf *f, int y)
{
	int	x;
	int	z;

	x = 0;
	f->vertex[y] = malloc(sizeof(t_vertex **) * f->size->x);
	if (!f->vertex[y])
		return (0);
	while (x < f->size->x)
	{
		z = ft_atoi(pts[x]);
		f->vertex[y][x] = ft_init_vertex(x, y, z);
		if (z < f->z_min)
			f->z_min = z;
		else if (z > f->z_max)
			f->z_max = z;
		x++;
	}
	return (1);
}

static void	*ft_reallocptr(void *ptr, size_t newsize)
{
	char	*res;
	size_t	oldsize;

	oldsize = newsize - 1;
	res = ft_memalloc(sizeof(t_vertex ***) * newsize);
	if (!res)
		return (0);
	if (oldsize > 0)
		ft_memcpy(res, ptr, sizeof(t_vertex ***) * oldsize);
	ft_memdel(&ptr);
	return (res);
}

static int	parse_file(int fd, t_fdf *f)
{
	char	*line;
	char	**pts;
	int		ptslen;

	pts = NULL;
	while (get_next_line(fd, &line))
	{
		pts = ft_strsplit(line, ' ');
		ptslen = ft_ptrlen(pts);
		if (f->size->x == 0)
			f->size->x = ptslen;
		if (ptslen == 0)
			continue ;
		if (f->size->x != ptslen)
			return (0);
		f->size->y++;
		f->vertex = (t_vertex ***)ft_reallocptr(f->vertex, f->size->y);
		if (!f->vertex || !parse_ptstovertex(pts, f, f->size->y - 1))
			return (0);
	}
	free(line);
	center_mesh(f);
	return (f->size->y && f->size->x);
}

int	parse(t_fdf *fdf, char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("File Error!");
		exit(0);
	}
	if (!parse_file(fd, fdf))
	{
		ft_putstr("Error Parse\n");
		exit(0);
	}
	close(fd);
	return (1);
}
