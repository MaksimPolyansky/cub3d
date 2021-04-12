/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heusebio <heusebio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 14:26:40 by heusebio          #+#    #+#             */
/*   Updated: 2020/10/27 14:26:43 by heusebio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_color_and_inter(t_all *all, t_sprites *tmp)
{
	if (all->map->map[(int)tmp->y / SCALE][(int)tmp->x / SCALE] == '2')
	{
		all->index = 4;
		tmp->sprite_h = SCALE / tmp->dist * 250;
	}
}
