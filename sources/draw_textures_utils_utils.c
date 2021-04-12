/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_textures_utils_utils.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heusebio <heusebio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 14:24:59 by heusebio          #+#    #+#             */
/*   Updated: 2020/10/27 14:25:02 by heusebio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_ceiling(t_all *all, float ceiling_start)
{
	while (ceiling_start > 0)
		my_pixel_put(all, all->plr->line_x, ceiling_start--,
		all->ceiling_color);
}

void	draw_floor(t_all *all, float floor_start)
{
	while (floor_start < all->heigth)
		my_pixel_put(all, all->plr->line_x, floor_start++, all->floor_color);
}

void	start_x(t_all *all)
{
	if (all->index == 0 || all->index == 1)
		all->textures[all->index]->tex_x = all->offset_x;
	else if (all->index == 2 || all->index == 3)
		all->textures[all->index]->tex_x = all->offset_y;
}

void	draw_all(t_all *all, float col_h, int y, float dist)
{
	start_x(all);
	draw_ceiling(all, y);
	draw_texture(all, col_h, y, dist);
	draw_floor(all, y + col_h);
	all->plr->line_x++;
}

void	draw_high_ray(t_all *all, float dist)
{
	float	column_length;
	float	start;

	dist = dist * cos(all->plr->start - all->plr->dir);
	column_length = (SCALE / dist) * (all->width / 2 / tan(ANGLE / 2));
	all->textures[all->index]->tex_scale = column_length /
	all->textures[all->index]->heigth;
	if ((int)column_length >= all->heigth)
	{
		start = 0;
		all->textures[all->index]->tex_y = (column_length - all->heigth) / 2;
		column_length = all->textures[all->index]->tex_y + all->heigth;
	}
	else
	{
		start = ((all->heigth - all->plr->overlook - column_length) / 2);
		all->textures[all->index]->tex_y = 0;
	}
	draw_all(all, column_length, start, dist);
}
