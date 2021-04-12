/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heusebio <heusebio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 14:26:22 by heusebio          #+#    #+#             */
/*   Updated: 2020/10/28 10:18:24 by heusebio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		is_map(t_all *all, char *line)
{
	int		i;
	char	*save;

	i = 0;
	while (is_space(line[i]) == 1)
		i++;
	if (line[i] == '1')
	{
		save = all->map_str;
		all->map_str = ft_strjoin(save, line);
		free(save);
		save = all->map_str;
		all->map_str = ft_strjoin(all->map_str, "\n");
		free(save);
		return (1);
	}
	return (-1);
}

int		check_name_file(char *name)
{
	int	name_len;

	name_len = ft_strlen(name);
	if (name[name_len - 4] != '.' || name[name_len - 3] != 'c' ||
			name[name_len - 2] != 'u' || name[name_len - 1] != 'b')
		return (-1);
	return (1);
}

void	read_map(t_all *all, char *name)
{
	int		fd;
	char	*line;
	int		res;

	if (check_name_file(name) == -1)
		my_exit(EXIT_FAILURE, "Error\nIncorrect map-format!\n", all);
	if ((fd = open(name, O_RDONLY)) == -1)
		my_exit(EXIT_FAILURE, "Error\nI can't open map-file!\n", all);
	while ((res = get_next_line(fd, &line)) != -1)
	{
		if (line && after_read_map(all, line, res) == -1)
			my_exit(EXIT_FAILURE,
			"Error\nInvalid map-file!\nGive me good map-file!)\n", all);
		free(line);
		line = NULL;
		if (res == 0)
			break ;
	}
	close(fd);
}
