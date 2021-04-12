/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heusebio <heusebio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 14:24:35 by heusebio          #+#    #+#             */
/*   Updated: 2020/10/28 11:05:09 by heusebio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	mb_sprite(t_all *all, int x, int y)
{
	if (all->map->map[y][x] == '2')
	{
		all->map->map[y][x] = '0';
		all->point += 100;
	}
}

void	time_sprite_minus(t_all *all)
{
	static int		start = 0;
	static time_t	str_time = 0;

	if (start == 0)
		start = 1;
	if (str_time == 0)
		str_time = time(0);
	if (time(0) - str_time >= 1)
	{
		str_time = 0;
		all->lives--;
		start = 0;
	}
}

void	get_color_and_inter(t_all *all, t_sprites *tmp)
{
	if (all->map->map[(int)tmp->y / SCALE][(int)tmp->x / SCALE] == '3')
	{
		all->index = 5;
		tmp->sprite_h = SCALE / tmp->dist * 150;
		if (((int)all->plr->y / SCALE) == ((int)tmp->y / SCALE) &&
		((int)all->plr->x / SCALE) == ((int)tmp->x / SCALE))
			time_sprite_minus(all);
	}
	if (all->map->map[(int)tmp->y / SCALE][(int)tmp->x / SCALE] == '2')
	{
		all->index = 4;
		tmp->sprite_h = SCALE / tmp->dist * 250;
		if ((int)all->plr->y / SCALE == (int)tmp->y / SCALE &&
		(int)all->plr->x / SCALE == (int)tmp->x / SCALE && tmp->flag_invis != 1)
		{
			mb_sprite(all, (int)all->plr->x / SCALE, (int)all->plr->y / SCALE);
			tmp->flag_invis = 1;
		}
	}
}
