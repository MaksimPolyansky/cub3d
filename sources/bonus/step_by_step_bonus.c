/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step_by_step_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heusebio <heusebio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 10:51:39 by heusebio          #+#    #+#             */
/*   Updated: 2020/10/28 11:27:30 by heusebio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	move_forvard(t_all *all)
{
	if (all->map->map[(int)all->plr->y / SCALE][(int)(all->plr->x +
	cos(all->plr->dir) * SPEED) / SCALE] != '1')
		all->plr->x += cos(all->plr->dir) * SPEED;
	if (all->map->map[(int)(all->plr->y - sin(all->plr->dir) * SPEED) /
	SCALE][(int)all->plr->x / SCALE] != '1')
		all->plr->y -= sin(all->plr->dir) * SPEED;
}

void	move_back(t_all *all)
{
	if (all->map->map[(int)all->plr->y / SCALE][(int)(all->plr->x -
	cos(all->plr->dir) * SPEED) / SCALE] != '1')
		all->plr->x -= cos(all->plr->dir) * SPEED;
	if (all->map->map[(int)(all->plr->y + sin(all->plr->dir) * SPEED) /
	SCALE][(int)all->plr->x / SCALE] != '1')
		all->plr->y += sin(all->plr->dir) * SPEED;
}

void	move_left(t_all *all)
{
	if (all->map->map[(int)all->plr->y / SCALE][(int)(all->plr->x -
	cos(all->plr->dir - PI / 2) * SPEED) / SCALE] != '1')
		all->plr->x -= cos(all->plr->dir - PI / 2) * SPEED;
	if (all->map->map[(int)(all->plr->y + sin(all->plr->dir - PI / 2) *
	SPEED) / SCALE][(int)all->plr->x / SCALE] != '1')
		all->plr->y += sin(all->plr->dir - PI / 2) * SPEED;
}

void	move_right(t_all *all)
{
	if (all->map->map[(int)all->plr->y / SCALE][(int)(all->plr->x +
	cos(all->plr->dir - PI / 2) * SPEED) / SCALE] != '1')
		all->plr->x += cos(all->plr->dir - PI / 2) * SPEED;
	if (all->map->map[(int)(all->plr->y - sin(all->plr->dir - PI / 2) *
	SPEED) / SCALE][(int)all->plr->x / SCALE] != '1')
		all->plr->y -= sin(all->plr->dir - PI / 2) * SPEED;
}
