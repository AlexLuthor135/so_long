/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_collect.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alappas <alappas@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 22:12:39 by alappas           #+#    #+#             */
/*   Updated: 2024/05/15 19:42:47 by alappas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_collect(t_game *game)

{
	int	y;
	int	x;

	y = game->player_position_y;
	x = game->player_position_x;
	if (game->map_data[y][x] == COLLECT_SYMBOL)
	{
		game->game_score += 1;
		game->map_data[y][x] = FLOOR_SYMBOL;
		if (game->game_score == game->max_score)
		{
			mlx_put_image_to_window(game->mlx, game->win,
				game->exit, game->exit_x * 32,
				game->exit_y * 32);
			game->map_data[game->exit_y][game->exit_x] = OPEN_SYMBOL;
		}
	}
}

int	check_complete(t_game *game)

{
	int	x;
	int	y;

	x = game->player_position_x;
	y = game->player_position_y;
	if (game->game_score == game->max_score)
	{
		if (game->map_data[y][x] == OPEN_SYMBOL)
		{
			win_state(game);
			return (0);
		}
	}
	if (game->map_data[y][x] == ENEMY_SYMBOL)
	{
		lose_state(game);
		return (2);
	}
	return (1);
}

void	win_state(t_game *game)

{
	mlx_put_image_to_window(game->mlx, game->win,
		game->success, game->exit_x * 32,
		game->exit_y * 32);
}
