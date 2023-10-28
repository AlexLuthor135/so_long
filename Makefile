SRCS		=	main.c map_render.c error_handle.c\
				image_render.c image_assign.c key_action.c\
				check_collect.c map_check.c bonus_handle.c\
				check_parses.c

MLX_FLAGS		= 	-lmlx -framework OpenGL -framework AppKit
CC_FLAGS		=	-Wall -Wextra -Werror -g
CC				=	gcc
SRCS_F			= srcs/
OBJS_F			= objs/

LIBFT = incl/libft/
PRINTF = incl/ft_printf/
MLX = mlx/
GNL = incl/get_next_line/

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
	@$(MAKE) -C $(PRINTF) 
	@$(MAKE) -C $(GNL)
	@$(CC) $(CC_FLAGS) -O3 -L$(MLX) $(MLX_FLAGS) $(PRINTF)/libftprintf.a $(GNL)/get_next_line.a $(LIBFT)/libft.a -o $(NAME) $(OBJS_P)
	@echo "OK"

clean:
	@rm -rf $(OBJS_F)
	@$(MAKE) clean -C $(MLX) 
	@$(MAKE) fclean -C $(LIBFT) 
	@$(MAKE) fclean -C $(PRINTF) 
	@$(MAKE) fclean -C $(GNL)

fclean:	clean
	@rm -rf $(NAME)

re:		fclean all

.PHONY:	all clean fclean re