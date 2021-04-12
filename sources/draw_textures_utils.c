/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_textures_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heusebio <heusebio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 14:25:06 by heusebio          #+#    #+#             */
/*   Updated: 2020/10/27 14:25:09 by heusebio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		check_wall(t_all *all, float x, float y)
{
	x = (int)(x / SCALE);
	y = (int)(y / SCALE);
	if (x < 0 || y < 0 || y >= all->map->height || x >= all->map->width)
		return (-1);
	else if (all->map->map[(int)y][(int)x] == '1')
		return (1);
	else
		return (0);
}

float	hor_inter1(t_all *all, float *y, float step, char c)
{
	if (c == 'p')
	{
		*y = (int)(all->plr->y / SCALE) * SCALE - 0.001;
		return (-step);
	}
	if (c == 'm')
	{
		*y = (int)(all->plr->y / SCALE) * SCALE + SCALE;
		return (-step);
	}
	return (0);
}

float	hor_inter(t_all *all, float start)
{
	float	x;
	float	y;
	float	step_x;
	float	step_y;

	step_y = SCALE;
	step_x = SCALE / tan(start);
	if ((start > 0 && start < PI) || start > PI * 2)
		step_y = hor_inter1(all, &y, step_y, 'p');
	else
		step_x = hor_inter1(all, &y, step_x, 'm');
	x = all->plr->x + (all->plr->y - y) / tan(start);
	while (check_wall(all, x, y) == 0)
	{
		x += step_x;
		y += step_y;
	}
	all->offset_x = (int)x % SCALE;
	return (check_wall(all, x, y) == -1 ? INT_MAX :
	sqrt(pow(all->plr->x - x, 2) + pow(all->plr->y - y, 2)));
}

float	ver_inter1(t_all *all, float *x, float step, char c)
{
	if (c == 'p')
	{
		*x = (int)(all->plr->x / SCALE) * SCALE - 0.001;
		return (-step);
	}
	if (c == 'm')
	{
		*x = (int)(all->plr->x / SCALE) * SCALE + SCALE;
		return (-step);
	}
	return (0);
}

float	ver_inter(t_all *all, float start)
{
	float	x;
	float	y;
	float	step_x;
	float	step_y;

	step_x = SCALE;
	step_y = SCALE * tan(start);
	if (start > PI / 2 && start < 3 * PI / 2)
		step_x = ver_inter1(all, &x, step_x, 'p');
	else
		step_y = ver_inter1(all, &x, step_y, 'm');
	y = all->plr->y + (all->plr->x - x) * tan(start);
	while (check_wall(all, x, y) == 0)
	{
		x += step_x;
		y += step_y;
	}
	all->offset_y = (int)y % SCALE;
	return (check_wall(all, x, y) == -1 ? INT_MAX :
	sqrt(pow(all->plr->x - x, 2) + pow(all->plr->y - y, 2)));
}
