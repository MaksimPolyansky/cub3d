/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_textures_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heusebio <heusebio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 14:24:15 by heusebio          #+#    #+#             */
/*   Updated: 2020/10/28 11:04:22 by heusebio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int		check_textures_line(char *line)
{
	int	i;

	i = 0;
	if (line[i] != 'N' && line[i] != 'S' && line[i] != 'W' &&
	line[i] != 'E' && line[i] != 'H')
		return (-1);
	i++;
	if (line[i] != 'O' && line[i] != 'E' && line[i] != 'A' && line[i] != ' ')
		return (-1);
	i++;
	while (is_space(line[i]) == 1)
		i++;
	if (line[i] != '.' && line[i + 1] != '/')
		return (-1);
	while (is_space(line[i]) != 1 && ft_isprint(line[i]) && line[i] != '\0')
		i++;
	if (is_space(line[i]) != 1 && line[i] != '\0')
		return (-1);
	while (is_space(line[i]) == 1)
		i++;
	if (line[i] != '\0')
		return (-1);
	return (1);
}

int		is_texture1(t_all *all, int index, char *line)
{
	char	*name;

	if (!(name = ft_substr(line, 0, len_name(line))) || check_file(name) == -1)
		my_exit(EXIT_FAILURE, "Error\nIncorrect format textures!\n", all);
	if (all->textures[index]->check == 1)
		my_exit(EXIT_FAILURE, "Error\nDelete one or more textures!\n", all);
	all->textures[index]->check = 1;
	if (!(all->textures[index]->img = mlx_xpm_file_to_image(all->mlx, name,
		&all->textures[index]->width, &all->textures[index]->heigth)))
		my_exit(1, "Error\nI'm so sorry...\nMLX dont want to work\n", all);
	if (!(all->textures[index]->addr =
	(int*)mlx_get_data_addr(all->textures[index]->img,
	&all->textures[index]->bpp, &all->textures[index]->size_line,
	&all->textures[index]->endian)))
		my_exit(1, "Error\nI'm so sorry...\nMLX dont want to work\n", all);
	if (index == 1 || index == 3)
		make_reverce_array(all, index);
	else if (index == 0 || index == 2 || index == 4 || index == 5)
		make_array(all, index);
	free(name);
	return (1);
}

int		is_texture(t_all *all, char *line)
{
	int		i;

	i = 0;
	if (check_textures_line(line) == -1)
		my_exit(EXIT_FAILURE, "Error\nIncorrect format textures!\n", all);
	if (line[i] == 'N' && line[i + 1] == 'O' && is_space(line[i + 2]) == 1)
		return (is_texture1(all, 0, ft_strchr(line, '.')));
	if (line[i] == 'S' && line[i + 1] == 'O' && is_space(line[i + 2]) == 1)
		return (is_texture1(all, 1, ft_strchr(line, '.')));
	if (line[i] == 'W' && line[i + 1] == 'E' && is_space(line[i + 2]) == 1)
		return (is_texture1(all, 2, ft_strchr(line, '.')));
	if (line[i] == 'E' && line[i + 1] == 'A' && is_space(line[i + 2]) == 1)
		return (is_texture1(all, 3, ft_strchr(line, '.')));
	if (line[i] == 'S' && is_space(line[i + 1]) == 1)
		return (is_texture1(all, 4, ft_strchr(line, '.')));
	if (line[i] == 'H' && is_space(line[i + 1]) == 1)
		return (is_texture1(all, 5, ft_strchr(line, '.')));
	return (1);
}
