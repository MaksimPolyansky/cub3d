/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw2_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heusebio <heusebio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 14:24:08 by heusebio          #+#    #+#             */
/*   Updated: 2020/10/28 11:04:04 by heusebio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	draw_pxl(t_all *all, int color)
{
	int	x;
	int	y;

	y = all->map->y * MAP_SCALE;
	while (y < (all->map->y * MAP_SCALE + MAP_SCALE))
	{
		x = all->map->x * MAP_SCALE;
		while (x < (all->map->x * MAP_SCALE + MAP_SCALE))
			my_pixel_put(all, x++, y, color);
		y++;
	}
}

void	draw_rote_pov(t_all *all)
{
	float	x;
	float	y;
	float	c;
	int		i;
	float	start;

	start = all->plr->dir - PI / 6;
	i = 0;
	while (i++ < all->width)
	{
		c = 0;
		x = all->plr->x / SCALE * MAP_SCALE;
		y = all->plr->y / SCALE * MAP_SCALE;
		while (all->map->map[(int)y / MAP_SCALE][(int)x / MAP_SCALE] == '0')
		{
			c += 2;
			x = (all->plr->x / SCALE * MAP_SCALE) + c * cos(start);
			y = (all->plr->y / SCALE * MAP_SCALE) - c * sin(start);
			my_pixel_put(all, x, y, 0x8B778F);
		}
		start += ANGLE / all->width;
	}
}

void	draw_map(t_all *all)
{
	all->map->y = -1;
	while (all->map->map[++all->map->y])
	{
		all->map->x = -1;
		while (all->map->map[all->map->y][++all->map->x])
		{
			if (all->map->map[all->map->y][all->map->x] == '1')
				draw_pxl(all, 0xFFFFFF);
			if (all->map->map[all->map->y][all->map->x] == '2')
				draw_pxl(all, 0x0000FF);
			if (all->map->map[all->map->y][all->map->x] == '3')
				draw_pxl(all, 0xFF0000);
			if (all->map->map[all->map->y][all->map->x] == '0')
				draw_pxl(all, 0x000000);
		}
	}
	my_pixel_put(all, all->plr->x / SCALE * MAP_SCALE,
	all->plr->y / SCALE * MAP_SCALE, 0x0084CD);
	draw_rote_pov(all);
}

void	draw_point_and_life(t_all *all)
{
	char	*points;
	char	*lives;
	char	*nbr;

	nbr = ft_itoa(all->point);
	points = ft_strjoin("Your points : ", nbr);
	mlx_string_put(all->mlx, all->win, 10, all->heigth - 10, 0xFFFFFF, points);
	free(points);
	free(nbr);
	nbr = ft_itoa(all->lives);
	lives = ft_strjoin("Your lives : ", nbr);
	mlx_string_put(all->mlx, all->win, 10, all->heigth - 20, 0xFFFFFF, lives);
	free(lives);
	free(nbr);
}
