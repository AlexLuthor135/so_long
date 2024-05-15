/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_assign.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alappas <alappas@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 17:26:56 by alappas           #+#    #+#             */
/*   Updated: 2024/05/15 19:44:31 by alappas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	image_alloc(t_game *game, char c, int y, int x)

{
	if (c == WALL_SYMBOL)
		mlx_put_image_to_window(game->mlx, game->win, game->wall, y, x);
	else if (c == FLOOR_SYMBOL)
		mlx_put_image_to_window(game->mlx, game->win, game->floor, y, x);
	else if (c == PLAYER_SYMBOL)
	{
		mlx_put_image_to_window(game->mlx, game->win, game->p_down, y, x);
		game->i_player += 1;
	}
	else if (c == EXIT_SYMBOL)
	{
		mlx_put_image_to_window(game->mlx, game->win, game->exit_closed, y, x);
		game->i_exit += 1;
	}
	else if (c == COLLECT_SYMBOL)
	{
		mlx_put_image_to_window(game->mlx, game->win, game->collect, y, x);
		game->i_collect += 1;
	}
	else if (c == ENEMY_SYMBOL)
		enemy_alloc(game, y, x);
}

void	enemy_alloc(t_game *game, int y, int x)

{
	mlx_put_image_to_window(game->mlx, game->win, game->m1, y, x);
}

void	coords_assign(t_game *game, int y, int x)

{
	if (game->map_data[y][x] == PLAYER_SYMBOL)
	{
		game->player_position_x = x;
		game->player_position_y = y;
	}
	else if (game->map_data[y][x] == COLLECT_SYMBOL)
		game->max_score += 1;
	else if (game->map_data[y][x] == EXIT_SYMBOL)
	{
		game->exit_x = x;
		game->exit_y = y;
	}
}

void	image_assign(t_game *game)

{
	int		x;
	int		y;

	y = 0;
	while (y != game->map_height)
	{
		x = 0;
		while (x != game->map_length)
		{
			coords_assign(game, y, x);
			image_alloc(game, game->map_data[y][x], x * 32, y * 32);
			x++;
		}
		y++;
	}
}
