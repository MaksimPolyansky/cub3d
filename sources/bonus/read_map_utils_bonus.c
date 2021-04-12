/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_utils_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heusebio <heusebio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 14:24:29 by heusebio          #+#    #+#             */
/*   Updated: 2020/10/28 11:04:50 by heusebio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int		after_read_map(t_all *all, char *line, int res)
{
	int	i;

	if (*line == 'R' && *all->map_str == '\0')
		return (is_display(all, line));
	if ((*line == 'N' || *line == 'E' || *line == 'H' ||
	*line == 'W' || *line == 'S') && *all->map_str == '\0')
		return (is_texture(all, line));
	if ((*line == 'F' || *line == 'C') && *all->map_str == '\0')
		return (is_color_f_c(all, line, 0));
	i = 0;
	while (line[i] == ' ')
		i++;
	if (line[i] == '1')
		return (is_map(all, line));
	if ((*line == '\0' && res == 0) ||
	(*line == '\0' && *all->map_str == '\0'))
		return (1);
	return (-1);
}

void	ft_run_on_map(t_all *all, t_map *map)
{
	map->y = -1;
	while (map->map[++map->y])
	{
		map->x = -1;
		while (map->map[map->y][++map->x])
		{
			if (map->map[map->y][map->x] == 'N' ||
					map->map[map->y][map->x] == 'E' ||
					map->map[map->y][map->x] == 'W' ||
					map->map[map->y][map->x] == 'S')
			{
				start_pos(all, map->y, map->x, map->map[map->y][map->x]);
				map->map[map->y][map->x] = '0';
			}
			if (map->map[map->y][map->x] == '2' ||
			map->map[map->y][map->x] == '3')
				my_listnew(all, map->y, map->x);
		}
	}
}
