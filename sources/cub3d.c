/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heusebio <heusebio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 14:24:54 by heusebio          #+#    #+#             */
/*   Updated: 2020/10/28 13:18:51 by heusebio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_pixel_put(t_all *all, int x, int y, int color)
{
	char	*dst;

	if (y < all->heigth && x < all->width && y > 0 && x > 0)
	{
		dst = all->img->addr + (y * all->img->size_line +
		x * (all->img->bpp / 8));
		*(unsigned int*)dst = color;
	}
}

void	my_zero1(t_all *all)
{
	int		i;

	i = -1;
	if (!(all->textures = (t_textures**)malloc(sizeof(t_textures*) * 6)))
		my_exit(EXIT_FAILURE, "Error\nBad malloc!\n", all);
	while (++i < 6)
	{
		if (!(all->textures[i] = (t_textures*)malloc(sizeof(t_textures))))
			my_exit(EXIT_FAILURE, "Error\nBad malloc!\n", all);
		ft_bzero(all->textures[i], sizeof(t_textures));
	}
}

t_all	*my_zero(void)
{
	t_all	*all;

	if (!(all = malloc(sizeof(t_all))))
		my_exit(EXIT_FAILURE, "Error\nBad malloc!\n", all);
	ft_bzero(all, sizeof(t_all));
	all->map_str = ft_strdup("");
	all->lives = 5;
	if (!(all->plr = malloc(sizeof(t_plr))))
		my_exit(EXIT_FAILURE, "Error\nBad malloc!\n", all);
	ft_bzero(all->plr, sizeof(t_plr));
	if (!(all->key = malloc(sizeof(t_key))))
		my_exit(EXIT_FAILURE, "Error\nBad malloc!\n", all);
	ft_bzero(all->key, sizeof(t_key));
	if (!(all->img = malloc(sizeof(t_win))))
		my_exit(EXIT_FAILURE, "Error\nBad malloc!\n", all);
	ft_bzero(all->img, sizeof(t_win));
	if (!(all->mlx = mlx_init()))
		my_exit(1, "Error\nI'm so sorry...\nMLX dont want to work\n", all);
	my_zero1(all);
	return (all);
}

int		mlxlib_turn_on(t_all *all)
{
	if (!(all->win = mlx_new_window(all->mlx, all->width, all->heigth,
															"cub3D")))
		return (-1);
	if (!(all->img->img = mlx_new_image(all->mlx, all->img->width,
													all->img->heigth)))
		return (-1);
	if (!(all->img->addr = mlx_get_data_addr(all->img->img, &all->img->bpp,
								&all->img->size_line, &all->img->endian)))
		return (-1);
	return (1);
}

int		main(int ac, char **av)
{
	t_all	*all;

	all = my_zero();
	if (ac < 2)
		my_exit(-1, "I need a map!", all);
	parser(all, av[1]);
	if (mlxlib_turn_on(all) == -1)
		my_exit(EXIT_FAILURE,
		"Error\nI'm so sorry...\nMLX dont want to work\n", all);
	search_save(all, ac, av);
	mlx_hook(all->win, 2, 1L << 0, key_press, all);
	mlx_hook(all->win, 3, 1L << 1, key_releas, all);
	mlx_hook(all->win, 17, 1L << 17, close_game, all);
	mlx_loop_hook(all->mlx, my_hook, all);
	if (all->save == 0)
		mlx_loop(all->mlx);
	my_exit(EXIT_SUCCESS, "Screenshot done!)\n", all);
	return (0);
}
