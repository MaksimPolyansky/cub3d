/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heusebio <heusebio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 14:25:19 by heusebio          #+#    #+#             */
/*   Updated: 2020/10/27 14:25:22 by heusebio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_texture(t_all *all, float high, float y, int dist)
{
	dist = 0;
	while (all->textures[all->index]->tex_y < high)
	{
		my_pixel_put(all, all->plr->line_x, y++,
		all->textures[all->index]->tex_array[(int)(all->
		textures[all->index]->tex_y / all->textures[all->index]->
		tex_scale)][all->textures[all->index]->tex_x]);
		all->textures[all->index]->tex_y++;
	}
	all->textures[all->index]->tex_x++;
}
