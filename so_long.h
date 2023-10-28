/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alappas <alappas@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 19:55:29 by alappas           #+#    #+#             */
/*   Updated: 2023/08/27 20:01:48 by alappas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define WALL_SYMBOL	49
# define FLOOR_SYMBOL	48
# define COLLECT_SYMBOL	67
# define PLAYER_SYMBOL	80
# define EXIT_SYMBOL	69
# define OPEN_SYMBOL	79
# define ENEMY_SYMBOL	77

# define WALL 		"sprites/Wall.xpm"
# define FLOOR 		"sprites/Floor.xpm"
# define EXIT		"sprites/Exit.xpm"
# define EXIT_C		"sprites/Exit_C.xpm"
# define COLLECT	"sprites/Djinn.xpm"
# define PUP		"sprites/Isaac-UP.xpm"
# define PDOWN		"sprites/Isaac-DOWN.xpm"
# define PLEFT		"sprites/Isaac-LEFT.xpm"
# define PRIGHT		"sprites/Isaac-RIGHT.xpm"
# define PCOLLECT	"sprites/Isaac_C.xpm"
# define PDEAD		"sprites/Isaac-DEAD.xpm"
# define FRAME		"sprites/Frame.xpm"
# define M1			"sprites/Menardi1.xpm"

# define KEY_W		13
# define KEY_A		0
# define KEY_S		1
# define KEY_D		2
# define KEY_ESC	53

# include "mlx/mlx.h"
# include "incl/libft/libft.h"
# include "incl/get_next_line/get_next_line.h"
# include "incl/ft_printf/ft_printf.h"

typedef struct s_game {
	int		map_height;
	int		map_length;
	int		player_position_x;
	int		player_position_y;
	int		exit_x;
	int		exit_y;
	int		game_score;
	int		max_score;
	char	**map_data;
	char	**map_copy;
	int		game_over;
	int		steps;
	void	*wall;
	void	*exit;
	void	*exit_closed;
	void	*p_up;
	void	*p_down;
	void	*p_left;
	void	*p_right;
	void	*p_collect;
	void	*p_dead;
	void	*floor;
	void	*collect;
	void	*frame;
	void	*m1;
	void	*mlx;
	void	*win;
	char	*str;
	int		x;
	int		y;
	int		i_player;
	int		i_exit;
	int		i_collect;
	int		heads;
	int		ex_check;
}	t_game;

char	**map_render(t_game *game, char *map);
void	image_render(t_game *game);
void	image_assign(t_game *game);
int		key_action(int key, t_game *game);
void	shadow_change(t_game *game);
void	check_collect(t_game *game);
int		check_complete(t_game *game);
void	check_maxscore(t_game *game);
int		exit_game(void);
void	free_map(t_game *game);
void	win_state(t_game *game);
int		error_handle(t_game *game);
void	error_fd(void);
int		map_check(t_game *game);
char	**first_spread(t_game *game, char **map, int x, int y);
char	**second_spread(t_game *game, char **map);
int		check_spread(t_game *game, char **map);
void	collect_parse(t_game *game, char **map, int x, int y);
void	floor_parse(char **map, int x, int y);
void	exit_parse(t_game *game, char **map, int x, int y);
void	image_error(t_game *game);
int		check_ext(char *argv);
void	char_steps(int key, t_game *game);
void	step_change(t_game *game, int i);
void	score_handle(t_game *game);
void	bonus_render(t_game *game);
int		enemy_touch(t_game *game);
void	lose_state(t_game *game);
void	enemy_parse(char **map, int x, int y);
void	enemy_alloc(t_game *game, int y, int x);
#endif