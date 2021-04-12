NAME =		cub3D

SRC =		./sources/cub3d.c \
			./sources/cub3d_utils.c \
			./sources/draw_textures_utils_utils.c \
			./sources/draw_textures_utils.c \
			./sources/draw_textures.c \
			./sources/ft_color.c \
			./sources/ft_display.c \
			./sources/ft_key.c \
			./sources/ft_textures_utils.c \
			./sources/parser.c \
			./sources/read_map.c \
			./sources/screenshot_utils.c \
			./sources/screenshot.c \
			./sources/sprites.c \
			./sources/step_by_step.c \
			./sources/valid_map.c \
			./sources/draw.c \
			./sources/ft_textures.c \
			./sources/my_hook.c \
			./sources/read_map_utils.c \
			./sources/sprites_utils.c \
			./sources/valide_map.c \

SRCB =		./sources/bonus/cub3d_bonus.c \
			./sources/bonus/cub3d_utils_bonus.c \
			./sources/bonus/draw_textures_utils_utils_bonus.c \
			./sources/bonus/draw_textures_utils_bonus.c \
			./sources/bonus/draw_textures_bonus.c \
			./sources/bonus/ft_color_bonus.c \
			./sources/bonus/ft_display_bonus.c \
			./sources/bonus/ft_key_bonus.c \
			./sources/bonus/ft_textures_utils_bonus.c \
			./sources/bonus/parser_bonus.c \
			./sources/bonus/read_map_bonus.c \
			./sources/bonus/screenshot_utils_bonus.c \
			./sources/bonus/screenshot_bonus.c \
			./sources/bonus/sprites_bonus.c \
			./sources/bonus/step_by_step_bonus.c \
			./sources/bonus/valide_map_bonus.c \
			./sources/bonus/draw_bonus.c \
			./sources/bonus/draw1_bonus.c \
			./sources/bonus/draw2_bonus.c \
			./sources/bonus/ft_textures_bonus.c \
			./sources/bonus/my_hook_bonus.c \
			./sources/bonus/read_map_utils_bonus.c \
			./sources/bonus/sprites_utils_bonus.c \
			./sources/bonus/valid_map_bonus.c

FLAGS =		-Wall -Werror -Wextra

MLX =		-framework OpenGL -framework Appkit

LIBS =		./libft/libft.a ./minilibx/libmlx.a

MAPS =		./maps/map1.cub

OBJ = 		$(SRC:%.c=%.o)

OBJS =		$(SRCB:%.c=%.o)

.PHONY: all clean fclean re

all: $(NAME)

%.o: %.c
	@gcc $(FLAGS) -c $< -o $@

$(NAME): $(OBJ)
	@rm -rf $(NAME)
	@$(MAKE) -C ./libft
	@gcc $(FLAGS) $(OBJ) $(MLX) $(LIBS) -o $(NAME)

bonus: fclean $(OBJS)
	@$(MAKE) -C ./libft
	@gcc $(FLAGS) $(OBJS) $(MLX) $(LIBS) -o $(NAME)

run: all
	@./$(NAME) $(MAPS)

save: all
	@./$(NAME) $(MAPS) "--save"

de:
	gcc -g $(MLX) $(SRC) $(LIBS)
	./a.out

deb:
	gcc -g $(MLX) $(SRCB) $(LIBS)
	./a.out

norm:
	norminette -R CheckForbiddenSourceHeader ./sources/*
	norminette -R CheckForbiddenSourceHeader ./libft/*.c ./libft/*.h

clean:
	@$(MAKE) clean -C ./libft
	@rm -rf $(OBJ) $(OBJS)

fclean: clean
	@$(MAKE) fclean -C ./libft
	@rm -rf $(NAME)

re: fclean all
