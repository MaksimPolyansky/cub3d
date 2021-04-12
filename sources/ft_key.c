/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heusebio <heusebio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 14:25:45 by heusebio          #+#    #+#             */
/*   Updated: 2020/10/27 14:25:52 by heusebio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		key_press(int key, t_all *all)
{
	if (key == 13 && all->key->forward == 0)
		all->key->forward = 1;
	if (key == 1 && all->key->back == 0)
		all->key->back = 1;
	if (key == 123 && all->key->turn_left == 0)
		all->key->turn_left = 1;
	if (key == 124 && all->key->turn_right == 0)
		all->key->turn_right = 1;
	if (key == 0 && all->key->left == 0)
		all->key->left = 1;
	if (key == 2 && all->key->right == 0)
		all->key->right = 1;
	if (key == 126 && all->key->up == 0)
		all->key->up = 1;
	if (key == 125 && all->key->down == 0)
		all->key->down = 1;
	if (key == 53)
		my_exit(EXIT_SUCCESS, "See u later)))\n", all);
	return (1);
}

int		key_releas(int key, t_all *all)
{
	if (key == 13 && all->key->forward == 1)
		all->key->forward = 0;
	if (key == 1 && all->key->back == 1)
		all->key->back = 0;
	if (key == 123 && all->key->turn_left == 1)
		all->key->turn_left = 0;
	if (key == 124 && all->key->turn_right == 1)
		all->key->turn_right = 0;
	if (key == 0 && all->key->left == 1)
		all->key->left = 0;
	if (key == 2 && all->key->right == 1)
		all->key->right = 0;
	if (key == 126 && all->key->up == 1)
		all->key->up = 0;
	if (key == 125 && all->key->down == 1)
		all->key->down = 0;
	return (1);
}
