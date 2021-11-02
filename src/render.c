/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchanet <gchanet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 17:43:52 by gchanet           #+#    #+#             */
/*   Updated: 2021/10/21 11:22:44 by gchanet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	putpixel(t_vec3 pts, void *param)
{
	int		color;
	int		x;
	int		y;
	float	p;
	t_fdf	*f;

	f = (t_fdf *)param;
	x = (int)pts.x;
	y = (int)pts.y;
	if (x >= 0 && y >= 0 && x < WIN_WIDTH && y < WIN_HEIGHT)
	{
		p = purcent(f->z_min, f->z_max, pts.z);
		color = ft_colinterpolate(c_blue, c_red, p);
		ft_img_putpixel(&f->mlx->img, x, y, color);
	}
}

void	drawlines(t_fdf *fdf, t_vertex *v0, t_vertex *v1)
{
	v0->projected->z = v0->local->z;
	v1->projected->z = v1->local->z;
	get_line(*v0->projected, *v1->projected, &putpixel, fdf);
}

void	render(t_fdf	*f)
{
	t_vec2i	p;

	generate_transform(f);
	ft_img_reset(f->mlx, WIN_WIDTH, WIN_HEIGHT);
	p.y = 0;
	while (p.y < f->size->y)
	{
		p.x = 0;
		while (p.x < f->size->x)
		{
			if (p.x < f->size->x - 1)
				drawlines(f, f->vertex[p.y][p.x],
					f->vertex[p.y][p.x + 1]);
			if (p.y < f->size->y - 1)
				drawlines(f, f->vertex[p.y][p.x],
					f->vertex[p.y + 1][p.x]);
			p.x++;
		}
		p.y++;
	}
	draw_background_interface(f);
	ft_img_print(f->mlx);
	draw_interface(f);
}
