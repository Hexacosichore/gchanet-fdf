/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchanet <gchanet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 16:39:58 by gchanet           #+#    #+#             */
/*   Updated: 2021/10/21 11:03:49 by gchanet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	hook_exit(t_fdf *fdf)
{
	mlx_destroy_window(fdf->mlx->mlx_ptr, fdf->mlx->win_ptr);
	exit(0);
}

static int	hook_key_press(int keycode, t_fdf *fdf)
{
	if (keycode == KEY_ESCAPE)
		hook_exit(fdf);
	toggle_keys(keycode, fdf->mlx, 1);
}

static int	hook_key_release(int keycode, t_fdf *fdf)
{
	toggle_keys(keycode, fdf->mlx, 0);
}

int	hook_loop(t_fdf *f)
{
	if (f->mlx->keys->k_keypad1)
		f->mlx->transform.rotation.x += 0.01f;
	if (f->mlx->keys->k_keypad3)
		f->mlx->transform.rotation.x -= 0.01f;
	if (f->mlx->keys->k_keypad4)
		f->mlx->transform.rotation.y += 0.01f;
	if (f->mlx->keys->k_keypad6)
		f->mlx->transform.rotation.y -= 0.01f;
	if (f->mlx->keys->k_keypad7)
		f->mlx->transform.rotation.z += 0.01f;
	if (f->mlx->keys->k_keypad9)
		f->mlx->transform.rotation.z -= 0.01f;
	if (f->mlx->keys->k_a)
		f->mlx->transform.position.x += SPEED_MOVE;
	if (f->mlx->keys->k_d)
		f->mlx->transform.position.x -= SPEED_MOVE;
	if (f->mlx->keys->k_w)
		f->mlx->transform.position.y += SPEED_MOVE;
	if (f->mlx->keys->k_s)
		f->mlx->transform.position.y -= SPEED_MOVE;
	if (f->mlx->keys->k_space)
		f->mlx->transform.position.z += SPEED_MOVE;
	if (f->mlx->keys->k_c)
		f->mlx->transform.position.z -= SPEED_MOVE;
	render(f);
}

void	hook_init(t_fdf *fdf)
{
	mlx_hook(fdf->mlx->win_ptr, 2, (1L << 0), hook_key_press, fdf);
	mlx_hook(fdf->mlx->win_ptr, 3, (1L << 1), hook_key_release, fdf);
	mlx_hook(fdf->mlx->win_ptr, 17, 0, hook_exit, fdf);
	mlx_loop_hook(fdf->mlx->mlx_ptr, hook_loop, fdf);
}
