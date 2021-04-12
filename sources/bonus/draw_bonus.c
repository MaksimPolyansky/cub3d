/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heusebio <heusebio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 14:23:51 by heusebio          #+#    #+#             */
/*   Updated: 2020/10/28 11:03:36 by heusebio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	draw_texture(t_all *all, float high, float y, int dist)
{
	while (all->textures[all->index]->tex_y < high)
	{
		if (all->textures[all->index]->tex_x < all->textures[all->index]->width
		&& all->textures[all->index]->tex_y / all->textures[all->index]->
		tex_scale < all->textures[all->index]->heigth)
			dist_shade(all, all->textures[all->index]->tex_array[(int)(all->
			textures[all->index]->tex_y / all->textures[all->index]->
			tex_scale)][all->textures[all->index]->tex_x], dist);
		my_pixel_put(all, all->plr->line_x, y++, all->color);
		all->textures[all->index]->tex_y++;
	}
	all->textures[all->index]->tex_x++;
}
