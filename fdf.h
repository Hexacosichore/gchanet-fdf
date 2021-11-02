/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchanet <gchanet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 07:37:18 by gchanet           #+#    #+#             */
/*   Updated: 2021/10/21 11:05:14 by gchanet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <math.h>
# include <stdio.h>
# include <fcntl.h>
# include "../minilibx-linux/mlx.h"
# include "../libft/libft.h"
# include "../lib3d/lib3d.h"
# define WIN_WIDTH 1920
# define WIN_HEIGHT 1080
# define WIN_NAME "FDF - By gchanet"
# define SPEED_MOVE 1
# define SPEED_ZOOM 1

typedef struct s_fdf {
	t_mlx		*mlx;
	double		z_max;
	double		z_min;
	t_vertex	***vertex;
	t_vec2i		*size;
}				t_fdf;

/*	hook.c	*/
void		hook_init(t_fdf *fdf);
int			hook_loop(t_fdf *fdf);

/*	render.c	*/
void		render(t_fdf *fdf);

/*	parser.c	*/
int			parse(t_fdf *fdf, char *path);

/*	utils.c	*/
int			itox(int index, int size);
int			itoy(int index, int size);
float		purcent(int min, int max, float current);
void		center_mesh(t_fdf *f);
size_t		ft_ptrlen(char **s);

/*	transform.c	*/
void		generate_transform(t_fdf *fdf);

/*	interface.c	*/
void		draw_interface(t_fdf *f);
void		draw_background_interface(t_fdf *f);

#endif