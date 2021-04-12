/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heusebio <heusebio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 10:36:30 by heusebio          #+#    #+#             */
/*   Updated: 2020/10/28 10:37:07 by heusebio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int		is_space(int c)
{
	if (c == ' ')
		return (1);
	return (0);
}

void	my_exit(int nbr, char *str, t_all *all)
{
	all->color = 1;
	ft_putstr_fd(str, 1);
	exit(nbr);
}

int		close_game(t_all *all)
{
	my_exit(EXIT_SUCCESS, "See u later)\n", all);
	return (1);
}
