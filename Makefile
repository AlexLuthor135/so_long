SRCS		=	main.c map_render.c error_handle.c\
				image_render.c image_assign.c key_action.c\
				check_collect.c map_check.c bonus_handle.c\
				check_parses.c

UNAME_S := $(shell uname -s)

# Set the MLX and MLX_FLAGS variables based on the operating system
ifeq ($(UNAME_S),Linux)
    MLX = mlx_linux/
    MLX_FLAGS = -I -g3 -L /usr/X11/lib -Lincludes -L./mlx -lmlx -Imlx -lXext -lX11 -lz
else ifeq ($(UNAME_S),Darwin)
    MLX = mlx_mac/
    MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit
endif

# MLX_FLAGS		= 	-lmlx -framework OpenGL -framework AppKit
CC_FLAGS		=	-Wall -Wextra -Werror -g
CC				=	gcc
SRCS_F			= src/
OBJS_F			= obj/

LIBFT = inc/libft/
# MLX = mlx/

OBJS		=	$(SRCS:.c=.o)
OBJS_P		=	$(addprefix $(OBJS_F), $(OBJS))
NAME		= 	so_long

all:$(NAME)

$(OBJS_F)%.o: $(SRCS_F)%.c Makefile so_long.h
	@mkdir -p $(OBJS_F)
	@echo "Working on: $<"
	@$(CC) $(CC_FLAGS) -O3 -c $< -o $@

$(NAME): $(OBJS_P)
	@$(MAKE) -C $(MLX) 
	@$(MAKE) -C $(LIBFT) 
	@$(CC) $(CC_FLAGS) -O3 -o $(NAME) $(OBJS_P) -L$(MLX) $(MLX_FLAGS) $(LIBFT)/libft.a 
	@echo "OK"

clean:
	@rm -rf $(OBJS_F)
	@$(MAKE) clean -C $(MLX) 
	@$(MAKE) fclean -C $(LIBFT) 

fclean:	clean
	@rm -rf $(NAME)

re:		fclean all

.PHONY:	all clean fclean re