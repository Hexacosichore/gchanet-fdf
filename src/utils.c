/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchanet <gchanet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 18:24:19 by gchanet           #+#    #+#             */
/*   Updated: 2021/10/21 11:08:08 by gchanet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	itox(int index, int size)
{
	return (index % size);
}

int	itoy(int index, int size)
{
	return (index / size);
}

float	purcent(int min, int max, float current)
{
	max -= min;
	current -= min;
	return ((float)current / (float)max);
}

void	center_mesh(t_fdf *f)
{
	t_vec2i	i;

	i.y = -1;
	while (++i.y < f->size->y)
	{
		i.x = -1;
		while (++i.x < f->size->x)
		{
			f->vertex[i.y][i.x]->local->x -= f->size->x / 2;
			f->vertex[i.y][i.x]->local->y -= f->size->y / 2;
		}
	}
}

size_t	ft_ptrlen(char **s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}
