/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heusebio <heusebio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 14:26:46 by heusebio          #+#    #+#             */
/*   Updated: 2020/10/27 14:26:48 by heusebio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_pixel_sprite1(t_all *all, t_sprites *tmp, float scale, int x)
{
	int		y;

	y = 0;
	while (y < tmp->sprite_h && (y + tmp->sprite_y) < all->heigth)
	{
		all->color = all->textures[all->index]->tex_array[(int)(y /
		scale)][(int)(x / scale)];
		if (all->color > 0 && all->all_dist[(int)(tmp->sprite_x + x)] >
		tmp->dist)
			my_pixel_put(all, tmp->sprite_x + x, tmp->sprite_y + y,
			all->color);
		y++;
	}
}

void	draw_pixel_sprite(t_all *all, t_sprites *tmp)
{
	int		x;
	float	scale;

	x = 0;
	get_color_and_inter(all, tmp);
	scale = tmp->sprite_h / all->textures[all->index]->width;
	tmp->sprite_x = all->width / 2 - (all->width / (PI / 3)) *
	tmp->sprite_angle - tmp->sprite_h / 2;
	tmp->sprite_y = all->heigth / 2 - tmp->sprite_h / 2;
	while (x < tmp->sprite_h && (x + tmp->sprite_x) < all->width &&
	!tmp->flag_invis)
	{
		draw_pixel_sprite1(all, tmp, scale, x);
		x++;
	}
}

void	sorting_sprites(t_all *all)
{
	t_sprites	*tmp;
	t_sprites	*sprite_max;
	float		dist_max;

	dist_max = 0;
	while (dist_max != -1)
	{
		tmp = all->sprites;
		dist_max = -1;
		while (tmp != NULL)
		{
			if (tmp->dist > dist_max)
			{
				dist_max = tmp->dist;
				sprite_max = tmp;
			}
			tmp = tmp->next;
		}
		if (dist_max != -1)
		{
			draw_pixel_sprite(all, sprite_max);
			sprite_max->dist = -1;
		}
	}
}

void	draw_sprites(t_all *all)
{
	t_sprites	*tmp;

	tmp = all->sprites;
	while (tmp != NULL)
	{
		tmp->sprite_angle = atan2(all->plr->y - tmp->y, tmp->x - all->plr->x);
		if (tmp->sprite_angle < 0 && all->plr->dir >= PI / 6 && all->plr->dir
		<= (PI * 2 - PI / 6))
			tmp->sprite_angle += 2 * PI;
		if (all->plr->dir > (PI * 2 - PI / 6) && all->plr->dir <= 7)
			tmp->sprite_angle += 2 * PI;
		tmp->sprite_angle -= all->plr->dir;
		if (tmp->sprite_angle > -PI / 6 && tmp->sprite_angle < PI / 6)
			tmp->dist = sqrt(pow(all->plr->x - tmp->x, 2) + pow(all->plr->y -
			tmp->y, 2));
		else
			tmp->dist = -1;
		if (tmp->dist < 10)
			tmp->dist = -1;
		tmp = tmp->next;
	}
	sorting_sprites(all);
}
