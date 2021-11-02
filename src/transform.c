/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchanet <gchanet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 10:56:03 by gchanet           #+#    #+#             */
/*   Updated: 2021/10/21 11:10:49 by gchanet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	generate_transform(t_fdf *fdf)
{	
	t_mat		mat;
	t_vertex	*ref;
	t_vec2i		i;
	t_vec3		dst;

	i.y = -1;
	ft_matidentity(&mat);
	ft_matrot(&mat, fdf->mlx->transform.rotation);
	ft_matscale(&mat, fdf->mlx->transform.scale);
	ft_mattranslate(&mat, fdf->mlx->transform.position);
	while (++i.y < fdf->size->y)
	{
		i.x = -1;
		while (++i.x < fdf->size->x)
		{
			ref = fdf->vertex[i.y][i.x];
			ft_matmultivec(*ref->local, mat, ref->aligned);
			ft_matmultivec(*ref->aligned,
				fdf->mlx->cam->mat_proj, ref->projected);
			ref->projected->x = (ref->projected->x + 1.0f) * 0.5f * WIN_WIDTH;
			ref->projected->y = (ref->projected->y + 1.0f) * 0.5f * WIN_HEIGHT;
		}
	}
	ft_print_vertex(*ref);
}
