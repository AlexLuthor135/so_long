/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_action.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alappas <alappas@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 19:47:58 by alappas           #+#    #+#             */
/*   Updated: 2023/08/23 21:08:31 by alappas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	char_action(int key, t_game *game)

{
	int		x;
	int		y;

	x = game->player_position_x;
	y = game->player_position_y;
	shadow_change(game);
	if (key == KEY_W && game->map_data[y - 1][x] != WALL_SYMBOL &&
		game->map_data[y - 1][x] != EXIT_SYMBOL)
		step_change(game, 1);
	else if (key == KEY_A && game->map_data[y][x - 1] != WALL_SYMBOL &&
		game->map_data[y][x - 1] != EXIT_SYMBOL)
		step_change(game, 2);
	else if (key == KEY_S && game->map_data[y + 1][x] != WALL_SYMBOL &&
		game->map_data[y + 1][x] != EXIT_SYMBOL)
		step_change(game, 3);
	else if (key == KEY_D && game->map_data[y][x + 1] != WALL_SYMBOL
		&& game->map_data[y][x + 1] != EXIT_SYMBOL)
		step_change(game, 4);
	shadow_change(game);
	printf("Number of steps done: %d\n", game->steps);
}

void	step_change(t_game *game, int i)

{
	if (i == 1)
	{
		game->player_position_y -= 1;
		game->steps += 1;
	}
	else if (i == 2)
	{
		game->player_position_x -= 1;
		game->steps += 1;
	}
	else if (i == 3)
	{
		game->player_position_y += 1;
		game->steps += 1;
	}
	else if (i == 4)
	{
		game->player_position_x += 1;
		game->steps += 1;
	}
}

void	shadow_change(t_game *game)

{
	mlx_put_image_to_window(game->mlx, game->win,
		game->floor, game->player_position_x * 32,
		game->player_position_y * 32);
}

int	char_pic(int key, t_game *game)

{
	int	x;
	int	y;

	x = game->player_position_x;
	y = game->player_position_y;
	if (game->map_data[y][x] == COLLECT_SYMBOL)
		mlx_put_image_to_window(game->mlx, game->win,
			game->p_collect, x * 32, y * 32);
	else if (key == KEY_W)
		mlx_put_image_to_window(game->mlx, game->win,
			game->p_up, x * 32, y * 32);
	else if (key == KEY_A)
		mlx_put_image_to_window(game->mlx, game->win,
			game->p_left, x * 32, y * 32);
	else if (key == KEY_S)
		mlx_put_image_to_window(game->mlx, game->win,
			game->p_down, x * 32, y * 32);
	else if (key == KEY_D)
		mlx_put_image_to_window(game->mlx, game->win,
			game->p_right, x * 32, y * 32);
	return (0);
}

int	key_action(int key, t_game *game)

{
	if ((key == KEY_W || key == KEY_A || key == KEY_S || key == KEY_D)
		&& check_complete(game) != 0 && check_complete(game) != 2)
	{
		char_action(key, game);
		char_pic(key, game);
		check_collect(game);
		score_handle(game);
		if (check_complete(game) == 0)
			win_state(game);
	}
	if (key == KEY_ESC)
		exit_game();
	return (0);
}
