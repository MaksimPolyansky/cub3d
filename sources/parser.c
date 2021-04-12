/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heusebio <heusebio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 14:26:11 by heusebio          #+#    #+#             */
/*   Updated: 2020/10/27 14:26:13 by heusebio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_mapsize(t_map *map, char *map_str)
{
	int	i;
	int	p;
	int	count;

	i = 0;
	p = 0;
	count = 0;
	while (map_str[i] != '\0')
	{
		if (map_str[i] == '\n')
		{
			map->height++;
			count = (count > p) ? count : p;
			p = -1;
		}
		p++;
		i++;
	}
	map->width = count;
}

void	my_listnew(t_all *all, int y, int x)
{
	t_sprites	*tmp;
	t_sprites	*new;

	if (!(new = malloc(sizeof(t_sprites))))
		my_exit(EXIT_FAILURE, "Error\nBad malloc!\n", all);
	if (all->sprites == NULL)
		all->sprites = new;
	else
	{
		tmp = all->sprites;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
	new->x = x * SCALE + SCALE / 2;
	new->y = y * SCALE + SCALE / 2;
	new->dist = 0;
	new->flag_invis = 0;
	new->next = NULL;
}

void	start_pos(t_all *all, int y, int x, char c)
{
	if (all->plr->x != 0 || all->plr->y != 0)
		my_exit(EXIT_FAILURE, "Error\nTwo or more players!\n", all);
	all->plr->x = x * SCALE + SCALE / 2;
	all->plr->y = y * SCALE + SCALE / 2;
	if (c == 'N')
		all->plr->dir = PI / 2;
	else if (c == 'E')
		all->plr->dir = 2 * PI;
	else if (c == 'W')
		all->plr->dir = PI;
	else if (c == 'S')
		all->plr->dir = 3 * PI / 2;
}

t_map	*conversion_map(t_all *all)
{
	t_map	*map;

	if (!(map = malloc(sizeof(t_map))))
		my_exit(EXIT_FAILURE, "Error\nBad malloc!\n", all);
	ft_bzero(map, sizeof(t_map));
	ft_mapsize(map, all->map_str);
	map->map = ft_split(all->map_str, '\n');
	free(all->map_str);
	ft_run_on_map(all, map);
	return (map);
}

void	parser(t_all *all, char *name)
{
	read_map(all, name);
	if (!(all->all_dist = (float*)malloc(sizeof(float) * all->width)))
		my_exit(EXIT_FAILURE, "Error\nBad malloc!\n", all);
	ft_bzero(all->all_dist, sizeof(float));
	all->map = conversion_map(all);
	check_info(all);
	all->img->width = all->width;
	all->img->heigth = all->heigth;
}
