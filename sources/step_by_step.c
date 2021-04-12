/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step_by_step.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heusebio <heusebio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 14:26:51 by heusebio          #+#    #+#             */
/*   Updated: 2020/10/27 14:26:53 by heusebio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
