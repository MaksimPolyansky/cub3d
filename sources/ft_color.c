/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heusebio <heusebio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 14:25:28 by heusebio          #+#    #+#             */
/*   Updated: 2020/10/27 14:25:33 by heusebio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		check_color_f_c(char *line)
{
	int	i;

	i = 1;
	if (is_space(line[i]) != 1)
		return (-1);
	while (is_space(line[i]) == 1)
		i++;
	while (ft_isdigit(line[i]) || line[i] == ',')
		i++;
	while (is_space(line[i]) == 1)
		i++;
	if (line[i] != '\0')
		return (-1);
	return (1);
}

int		check_correct_color(char *line, int *i)
{
	int	cl;

	cl = ft_atoi(line + *i);
	if (cl > 255 || cl < 0)
		return (-1);
	while (ft_isdigit(line[*i]))
		*i += 1;
	*i += 1;
	return (cl);
}

int		create_trgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

void	mb_have_color(t_all *all, char c)
{
	if (c == 'F')
	{
		if (all->f_c == 1)
			my_exit(EXIT_FAILURE,
			"Error\nDelete one or more floor color\n", all);
		all->f_c = 1;
	}
	else if (c == 'C')
	{
		if (all->c_c == 1)
			my_exit(EXIT_FAILURE,
			"Error\nDelete one or more ceiling color\n", all);
		all->c_c = 1;
	}
}

int		is_color_f_c(t_all *all, char *line, int i)
{
	int		r;
	int		g;
	int		b;
	char	c;

	if (check_color_f_c(line) != 1)
		my_exit(EXIT_FAILURE, "Error\nIncorrect format color!\n", all);
	c = (line[i++] == 'F') ? 'F' : 'C';
	mb_have_color(all, c);
	while (is_space(line[i]) == 1)
		i++;
	if ((r = check_correct_color(line, &i)) == -1 ||
			(g = check_correct_color(line, &i)) == -1 ||
			(b = check_correct_color(line, &i)) == -1)
		my_exit(EXIT_FAILURE, "Error\nBad color!\n", all);
	if (c == 'F')
		all->floor_color = create_trgb(r, g, b);
	else if (c == 'C')
		all->ceiling_color = create_trgb(r, g, b);
	return (1);
}
