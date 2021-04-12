/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heusebio <heusebio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 14:26:06 by heusebio          #+#    #+#             */
/*   Updated: 2020/10/28 13:29:38 by heusebio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move(t_all *all)
{
	if (all->key->forward == 1)
		move_forvard(all);
	if (all->key->back == 1)
		move_back(all);
	if (all->key->turn_left == 1)
	{
		all->plr->dir += TURN;
		if (all->plr->dir > 2 * PI)
			all->plr->dir -= 2 * PI;
	}
	if (all->key->turn_right == 1)
	{
		all->plr->dir -= TURN;
		if (all->plr->dir < 0)
			all->plr->dir += 2 * PI;
	}
	if (all->key->left == 1)
		move_left(all);
	if (all->key->right == 1)
		move_right(all);
}

int		my_hook(t_all *all)
{
	move(all);
	draw_ray(all);
	draw_sprites(all);
	mlx_put_image_to_window(all->mlx, all->win, all->img->img, 0, 0);
	return (1);
}
