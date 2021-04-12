/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heusebio <heusebio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 13:57:25 by heusebio          #+#    #+#             */
/*   Updated: 2020/10/28 11:10:16 by heusebio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include "../minilibx/mlx.h"
# include <math.h>
# include <fcntl.h>
# include <limits.h>
# include <time.h>
# include <signal.h>

# define SCALE 64
# define SPEED SCALE * 0.2
# define TURN 0.1
# define PI 3.1415926535
# define ANGLE PI / 3
# define MAP_SCALE 5

typedef struct			s_plr
{
	float				x;
	float				y;
	float				dir;
	float				start;
	float				end;
	float				long_ray;
	int					line_x;
	float				overlook;
}						t_plr;

typedef struct			s_map
{
	char				**map;
	int					width;
	int					height;
	int					x;
	int					y;
}						t_map;

typedef struct			s_textures
{
	int					width;
	int					heigth;
	void				*img;
	int					*addr;
	int					size_line;
	int					bpp;
	int					endian;
	int					check;
	int					tex_x;
	int					tex_y;
	int					**tex_array;
	float				tex_scale;
	int					offset_x;
	int					offset_y;
}						t_textures;

typedef struct			s_win
{
	int					width;
	int					heigth;
	void				*img;
	char				*addr;
	int					size_line;
	int					bpp;
	int					endian;
}						t_win;

typedef struct			s_key
{
	int					forward;
	int					back;
	int					left;
	int					right;
	int					turn_left;
	int					turn_right;
	int					up;
	int					down;
}						t_key;

typedef struct			s_sprites
{
	int					x;
	int					y;
	int					flag_invis;
	float				dist;
	float				sprite_angle;
	float				sprite_h;
	float				sprite_x;
	float				sprite_y;
	struct s_sprites	*next;
}						t_sprites;

typedef struct			s_all
{
	void				*mlx;
	void				*win;
	int					width;
	int					heigth;
	int					floor_color;
	int					f_c;
	int					ceiling_color;
	int					c_c;
	int					save;
	char				*map_str;
	int					point;
	int					lives;
	int					index;
	int					color;
	int					offset_x;
	int					offset_y;
	float				*all_dist;
	int					pid;
	t_textures			**textures;
	t_sprites			*sprites;
	t_win				*img;
	t_map				*map;
	t_plr				*plr;
	t_key				*key;
}						t_all;

/*
** Mandaroty
*/

void					my_pixel_put(t_all *all, int x, int y, int color);
int						close_game(t_all *all);
void					my_exit(int nbr, char *str, t_all *all);
int						is_space(int c);
void					draw_high_ray(t_all *all, float dist);
float					ver_inter(t_all *all, float start);
float					hor_inter(t_all *all, float start);
void					draw_ray(t_all *all);
int						is_color_f_c(t_all *all, char *line, int i);
int						is_display(t_all *all, char *line);
int						key_press(int key, t_all *all);
int						key_releas(int key, t_all *all);
void					make_reverce_array(t_all *all, int index);
void					make_array(t_all *all, int index);
int						check_file(char *name);
int						len_name(char *line);
void					parser(t_all *all, char *name);
void					start_pos(t_all *all, int y, int x, char c);
void					my_listnew(t_all *all, int y, int x);
void					read_map(t_all *all, char *name);
int						is_map(t_all *all, char *line);
void					ft_revers_info(t_win *img);
void					ft_bit_map_file_header(int fd, int file_size,
						int offbits);
void					ft_bit_map_info_header(t_win *img, int fd,
						int size, int biplanes);
void					search_save(t_all *all, int ac, char **av);
void					draw_sprites(t_all *all);
void					move_right(t_all *all);
void					move_left(t_all *all);
void					move_back(t_all *all);
void					move_forvard(t_all *all);
void					check_info(t_all *all);
int						my_hook(t_all *all);
void					draw_texture(t_all *all, float high, float y, int dist);
void					dist_shade(t_all *all, int color, float dist);
int						is_texture(t_all *all, char *line);
void					ft_run_on_map(t_all *all, t_map *map);
int						after_read_map(t_all *all, char *line, int res);
void					get_color_and_inter(t_all *all, t_sprites *tmp);
int						valid_sym(t_map *map, int y, int x);
int						valid_sym1(t_map *map, int y, int x);
int						check_map_symbol(t_map *map);

#endif
