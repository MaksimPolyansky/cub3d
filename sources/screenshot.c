/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screenshot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heusebio <heusebio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 14:26:36 by heusebio          #+#    #+#             */
/*   Updated: 2020/10/28 08:56:31 by heusebio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_save(t_all *all)
{
	int		fd;
	int		index;

	my_hook(all);
	fd = open("screenshot.bmp", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR | S_IROTH);
	ft_bit_map_file_header(fd,
	14 + 40 + 4 + all->img->width * all->img->heigth * 4, 14 + 40 + 4);
	ft_bit_map_info_header(all->img, fd, 40, 1);
	ft_revers_info(all->img);
	index = all->img->width * all->img->heigth;
	while (--index >= 0)
		write(fd, &all->img->addr[index * all->img->bpp / 8], 4);
	close(fd);
}

void	search_save(t_all *all, int ac, char **av)
{
	if (ac > 3)
		my_exit(EXIT_FAILURE, "Error\nDelete one or more arguments!\n", all);
	if (ac == 3)
	{
		if (ft_strlen(av[2]) == 6 &&
		ft_strncmp(av[2], "--save", ft_strlen(av[2])) == 0)
		{
			ft_save(all);
			all->save = 1;
		}
		else
			my_exit(EXIT_FAILURE, "Error\nIncorrect input for image!\n", all);
	}
	else
		all->save = 0;
}
