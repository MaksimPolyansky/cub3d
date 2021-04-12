/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_textures_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heusebio <heusebio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 10:40:25 by heusebio          #+#    #+#             */
/*   Updated: 2020/10/28 11:29:00 by heusebio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int		route(float gleam, char c)
{
	if (c == 'h')
	{
		if ((gleam > 0 && gleam < PI) || gleam > 2 * PI)
			return (1);
		else
			return (-1);
	}
	if (c == 'v')
	{
		if (gleam > PI / 2 && gleam < 3 * PI / 2)
			return (-1);
		else
			return (1);
	}
	return (0);
}

void	draw_wall_hor(t_all *all, float dist_hor)
{
	if (route(all->plr->start, 'h') == 1)
	{
		all->index = 0;
		draw_high_ray(all, dist_hor);
	}
	else if (route(all->plr->start, 'h') == -1)
	{
		all->index = 1;
		draw_high_ray(all, dist_hor);
	}
}

void	draw_wall_ver(t_all *all, float dist_ver)
{
	if (route(all->plr->start, 'v') == 1)
	{
		all->index = 3;
		draw_high_ray(all, dist_ver);
	}
	else if (route(all->plr->start, 'v') == -1)
	{
		all->index = 2;
		draw_high_ray(all, dist_ver);
	}
}

void	draw_wall(t_all *all, float dist_ver, float dist_hor)
{
	if (dist_hor < dist_ver)
		draw_wall_hor(all, dist_hor);
	else
		draw_wall_ver(all, dist_ver);
}

void	draw_ray(t_all *all)
{
	float	dist_hor;
	float	dist_ver;
	int		i;

	all->plr->line_x = 0;
	all->plr->start = all->plr->dir + PI / 6;
	all->plr->end = all->plr->dir - PI / 6;
	i = 0;
	while (all->plr->start > all->plr->end)
	{
		dist_hor = hor_inter(all, all->plr->start);
		dist_ver = ver_inter(all, all->plr->start);
		draw_wall(all, dist_ver, dist_hor);
		all->plr->start -= ANGLE / all->width;
		if (dist_hor < dist_ver)
			all->all_dist[i++] = dist_hor;
		else
			all->all_dist[i++] = dist_ver;
	}
}
