/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heusebio <heusebio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 14:26:57 by heusebio          #+#    #+#             */
/*   Updated: 2020/10/27 14:26:58 by heusebio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		check_valid_map_line(t_map *map)
{
	int		x;
	int		y;

	y = -1;
	while (++y < map->height)
	{
		x = 0;
		while (x < map->width && map->map[y][x])
		{
			if (map->map[y][x] == ' ' || map->map[y][x] == '1')
				x++;
			else if (valid_sym(map, y, x) && valid_sym1(map, y, x))
				x++;
			else
				return (-1);
		}
	}
	return (1);
}

int		check_valid_map(t_all *all)
{
	if (check_map_symbol(all->map) == -1)
		return (-1);
	if (check_valid_map_line(all->map) == -1)
		return (-1);
	return (1);
}

void	check_info(t_all *all)
{
	int		i;

	i = -1;
	if (check_valid_map(all) == -1)
		my_exit(EXIT_FAILURE, "Error\nInvalid map!\nCheck please)\n", all);
	if (all->plr->x == 0 || all->plr->y == 0)
		my_exit(EXIT_FAILURE, "Error\nGive me player!\n", all);
	while (++i < 5)
	{
		if (all->textures[i]->check == 0)
			my_exit(1, "Error\nNeed more textures or sprites!\n", all);
	}
	if (all->width == 0 || all->heigth == 0)
		my_exit(EXIT_FAILURE, "Error\nNeed format display!\n", all);
	if (all->f_c != 1 || all->c_c != 1)
		my_exit(1, "Error\nNeed color for floor or ceiling!\n", all);
}
