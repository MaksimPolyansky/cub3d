/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valide_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heusebio <heusebio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 14:27:01 by heusebio          #+#    #+#             */
/*   Updated: 2020/10/27 14:27:03 by heusebio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		check_map_symbol(t_map *map)
{
	int		x;
	int		y;

	y = -1;
	while (++y < map->height)
	{
		x = -1;
		while (++x < map->width && map->map[y][x] != '\0')
		{
			if (map->map[y][x] != ' ' && map->map[y][x] != '0' &&
			map->map[y][x] != '1' && map->map[y][x] != '2' &&
			map->map[y][x] != 'E' && map->map[y][x] != 'N' &&
			map->map[y][x] != 'S' && map->map[y][x] != 'W')
				return (-1);
		}
	}
	return (1);
}

int		valid_sym2(t_map *map, int y, int x)
{
	if (map->map[y][x] == '0' || map->map[y][x] == 'E' ||
	map->map[y][x] == '1' || map->map[y][x] == '2' ||
	map->map[y][x] == 'N' ||
	map->map[y][x] == 'S' || map->map[y][x] == 'W')
		return (1);
	return (0);
}

int		valid_sym1(t_map *map, int y, int x)
{
	if (valid_sym2(map, y, x + 1) && valid_sym2(map, y, x - 1) &&
	valid_sym2(map, y + 1, x) && valid_sym2(map, y - 1, x))
		return (1);
	return (0);
}

int		valid_sym(t_map *map, int y, int x)
{
	if (map->map[y][x] == '0' || map->map[y][x] == '2' ||
	map->map[y][x] == 'N' ||
	map->map[y][x] == 'S' || map->map[y][x] == 'W' ||
	map->map[y][x] == 'E')
		return (1);
	return (0);
}
