/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchanet <gchanet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 10:56:03 by gchanet           #+#    #+#             */
/*   Updated: 2021/10/21 11:01:48 by gchanet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static void	draw_cord(t_mlx *m, t_vec3 coord, int x, int y)
{
	char	*t;

	t = "x:";
	mlx_string_put(m->mlx_ptr, m->win_ptr, x, y, c_white, t);
	x += 15;
	mlx_string_put(m->mlx_ptr, m->win_ptr, x, y, c_green, ft_itoa(coord.x));
	t = "y:";
	x += 30;
	mlx_string_put(m->mlx_ptr, m->win_ptr, x, y, c_white, t);
	x += 15;
	mlx_string_put(m->mlx_ptr, m->win_ptr, x, y, c_green, ft_itoa(coord.y));
	t = "z:";
	x += 30;
	mlx_string_put(m->mlx_ptr, m->win_ptr, x, y, c_white, t);
	x += 15;
	mlx_string_put(m->mlx_ptr, m->win_ptr, x, y, c_green, ft_itoa(coord.z));
}

static void	draw_background_pts_interface(t_vec2i pts, void *param)
{
	t_fdf	*f;

	f = (t_fdf *)param;
	ft_img_putpixel(&f->mlx->img, pts.x, pts.y, c_black_1);
}

void	draw_background_interface(t_fdf *f)
{
	t_vec2i	origine;
	t_vec2i	size;

	origine.x = 0;
	origine.y = 0;
	size.x = 300;
	size.y = WIN_HEIGHT;
	get_rect(origine, size, draw_background_pts_interface, f);
}

void	draw_interface(t_fdf *f)
{
	char	*t;

	t = "POSITION";
	mlx_string_put(f->mlx->mlx_ptr, f->mlx->win_ptr, 40, 40, c_white, t);
	draw_cord(f->mlx, f->mlx->transform.position, 100, 40);
	t = "ROTATION";
	mlx_string_put(f->mlx->mlx_ptr, f->mlx->win_ptr, 40, 60, c_white, t);
	draw_cord(f->mlx, f->mlx->transform.rotation, 100, 60);
	t = "SCALE";
	mlx_string_put(f->mlx->mlx_ptr, f->mlx->win_ptr, 40, 80, c_white, t);
	draw_cord(f->mlx, f->mlx->transform.scale, 100, 80);
}
