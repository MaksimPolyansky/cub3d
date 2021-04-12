/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heusebio <heusebio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 10:43:11 by heusebio          #+#    #+#             */
/*   Updated: 2020/10/28 11:28:49 by heusebio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int		check_display_line(char *line)
{
	int	i;

	i = 0;
	if (line[i] != 'R' || is_space(line[i + 1]) != 1)
		return (-1);
	i++;
	while (is_space(line[i]) == 1)
		i++;
	while (ft_isdigit(line[i]))
		i++;
	if (is_space(line[i]) != 1)
		return (-1);
	while (is_space(line[i]) == 1)
		i++;
	while (ft_isdigit(line[i]))
		i++;
	while (is_space(line[i]) == 1)
		i++;
	if (line[i] != '\0')
		return (-1);
	return (1);
}

int		is_display(t_all *all, char *line)
{
	int	i;

	if (check_display_line(line) == -1)
		my_exit(EXIT_FAILURE, "Error\nIncorrect format display!\n", all);
	if (all->width != 0 || all->heigth != 0)
		my_exit(EXIT_FAILURE,
		"Error\nExtra width and height arguments!\n", all);
	i = 1;
	while (is_space(line[i]) == 1)
		i++;
	while (ft_isalnum(line[i]))
		all->width = all->width * 10 + (line[i++] - 48);
	all->width = (all->width > 1920) ? 1920 : all->width;
	all->width = (all->width < 320) ? 320 : all->width;
	while (is_space(line[i]) == 1)
		i++;
	while (ft_isalnum(line[i]) && line[i != '\0'])
		all->heigth = all->heigth * 10 + (line[i++] - 48);
	all->heigth = (all->heigth > 1080) ? 1080 : all->heigth;
	all->heigth = (all->heigth < 240) ? 240 : all->heigth;
	return (1);
}
