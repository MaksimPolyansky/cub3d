/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_hook_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heusebio <heusebio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 14:24:23 by heusebio          #+#    #+#             */
/*   Updated: 2020/10/28 11:04:33 by heusebio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

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
	if (all->key->up == 1 && all->plr->overlook > -100)
		all->plr->overlook -= 10;
	if (all->key->down == 1 && all->plr->overlook < 100)
		all->plr->overlook += 10;
}

int		my_hook(t_all *all)
{
	if (all->lives > 0)
	{
		move(all);
		draw_ray(all);
		draw_sprites(all);
		draw_map(all);
		mlx_put_image_to_window(all->mlx, all->win, all->img->img, 0, 0);
		draw_point_and_life(all);
	}
	else
		my_exit(EXIT_SUCCESS, "Lucky next time)))\n", all);
	return (1);
}
