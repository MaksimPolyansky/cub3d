/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_textures_utils_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heusebio <heusebio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 10:45:08 by heusebio          #+#    #+#             */
/*   Updated: 2020/10/28 10:45:43 by heusebio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int		len_name(char *line)
{
	int	count;

	count = 0;
	while (ft_isprint(line[count]) && is_space(line[count]) != 1)
		count++;
	return (count);
}

int		check_file(char *name)
{
	int	fd;
	int	name_len;

	name_len = ft_strlen(name);
	if ((fd = open(name, O_RDONLY)) == -1)
	{
		close(fd);
		return (-1);
	}
	if (name[name_len - 4] != '.' || name[name_len - 3] != 'x' ||
			name[name_len - 2] != 'p' || name[name_len - 1] != 'm')
		return (-1);
	return (1);
}

void	make_array(t_all *all, int index)
{
	int	i;
	int	x;
	int	y;

	y = 0;
	if (!(all->textures[index]->tex_array = (int**)malloc(sizeof(int*) *
	all->textures[index]->heigth)))
		my_exit(EXIT_FAILURE, "Error\nBad malloc!\n", all);
	while (y < all->textures[index]->heigth)
		if (!(all->textures[index]->tex_array[y++] = (int*)malloc(sizeof(int) *
		all->textures[index]->width)))
			my_exit(EXIT_FAILURE, "Error\nBad malloc!\n", all);
	y = 0;
	i = 0;
	while (y < all->textures[index]->heigth)
	{
		x = 0;
		while (x < all->textures[index]->width)
			all->textures[index]->tex_array[y][x++] =
			all->textures[index]->addr[i++];
		y++;
	}
}

void	make_reverce_array(t_all *all, int index)
{
	int	i;
	int	x;
	int	y;

	y = 0;
	if (!(all->textures[index]->tex_array = (int**)malloc(sizeof(int*) *
	all->textures[index]->heigth)))
		my_exit(EXIT_FAILURE, "Error\nBad malloc!\n", all);
	while (y < all->textures[index]->heigth)
		if (!(all->textures[index]->tex_array[y++] = (int*)malloc(sizeof(int)
		* all->textures[index]->width)))
			my_exit(EXIT_FAILURE, "Error\nBad malloc!\n", all);
	y = 0;
	i = 0;
	while (y < all->textures[index]->heigth)
	{
		x = all->textures[index]->width - 1;
		while (x >= 0)
			all->textures[index]->tex_array[y][x--] =
			all->textures[index]->addr[i++];
		y++;
	}
}
