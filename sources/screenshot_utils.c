/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screenshot_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heusebio <heusebio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 14:26:30 by heusebio          #+#    #+#             */
/*   Updated: 2020/10/27 14:26:32 by heusebio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	search_pxl(t_win *img, int line, int *index, int size_line)
{
	char	cash;
	int		i;

	i = 4;
	while (--i >= 0)
	{
		cash = img->addr[*index + line * img->size_line];
		img->addr[*index + line * img->size_line] = img->addr[size_line - i +
		(line * img->size_line - 1)];
		img->addr[size_line - i + (line * img->size_line - 1)] = cash;
		*index += 1;
	}
}

void	ft_revers_info(t_win *img)
{
	int		line;
	int		index;
	int		size_line;

	line = -1;
	while (++line < img->heigth)
	{
		index = 0;
		size_line = img->size_line;
		while (index < size_line)
		{
			search_pxl(img, line, &index, size_line);
			size_line -= 4;
		}
	}
}

/*
** 59 - signature
** 60 - file size
** 61 - reserved
** 62 - file offset
*/

void	ft_bit_map_file_header(int fd, int file_size, int offbits)
{
	write(fd, "BM", 2);
	write(fd, &file_size, 4);
	write(fd, "\0\0\0\0", 4);
	write(fd, &offbits, 4);
}

/*
** 75 - header size
** 76 - image width
** 77 - image height
** 78 - planes
** 79 - bitcount
*/

void	ft_bit_map_info_header(t_win *img, int fd, int size, int biplanes)
{
	write(fd, &size, 4);
	write(fd, &img->width, 4);
	write(fd, &img->heigth, 4);
	write(fd, &biplanes, 2);
	write(fd, &img->bpp, 2);
	write(fd, "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0", 28);
}
