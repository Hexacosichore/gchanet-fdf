/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchanet <gchanet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 07:36:20 by gchanet           #+#    #+#             */
/*   Updated: 2021/10/21 11:10:08 by gchanet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

t_fdf	*init(void)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)malloc(sizeof(t_fdf));
	fdf->mlx = ft_init_mlx(WIN_WIDTH, WIN_HEIGHT, WIN_NAME);
	fdf->mlx->transform.scale = ft_get_vec3(1, 1, 1);
	fdf->vertex = NULL;
	fdf->size = ft_init_vec2i(0, 0);
	fdf->z_max = 0;
	fdf->z_min = 0;
	return (fdf);
}

int	main(void)
{
	t_fdf	*fdf;

	fdf = init();
	if (fdf->mlx != 0 && parse(fdf, "maps/mars.fdf"))
	{
		fdf->mlx->transform.position = ft_get_vec3(0, 0, fdf->size->x);
		fdf->mlx->transform.rotation = ft_get_vec3(270, 0, 0);
		ft_print_vec3(fdf->mlx->transform.position);
		hook_init(fdf);
		ft_putnbr(fdf->mlx->mlx_ptr == NULL);
		mlx_loop(fdf->mlx->mlx_ptr);
	}
	else
		ft_putstr("Error mlx!");
}
