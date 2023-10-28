/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_parses.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alappas <alappas@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 18:56:04 by alappas           #+#    #+#             */
/*   Updated: 2023/08/13 17:00:41 by alappas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	collect_parse(t_game *game, char **map, int x, int y)

{
	if (map[y][x] == COLLECT_SYMBOL)
	{
		game->heads += 1;
		map[y][x] = 'B';
	}
	if (map[y - 1][x] == COLLECT_SYMBOL)
	{
		game->heads += 1;
		map[y - 1][x] = 'R';
	}
	if (map[y + 1][x] == COLLECT_SYMBOL)
	{
		game->heads += 1;
		map[y + 1][x] = 'R';
	}
	if (map[y][x - 1] == COLLECT_SYMBOL)
	{
		game->heads += 1;
		map[y][x - 1] = 'R';
	}
}

void	floor_parse(char **map, int x, int y)

{
	if (map[y][x] == 'R' || map[y][x] == FLOOR_SYMBOL)
		map[y][x] = 'B';
	if (map[y - 1][x] == FLOOR_SYMBOL)
		map[y - 1][x] = 'R';
	if (map[y + 1][x] == FLOOR_SYMBOL)
		map[y + 1][x] = 'R';
	if (map[y][x - 1] == FLOOR_SYMBOL)
		map[y][x - 1] = 'R';
}

void	enemy_parse(char **map, int x, int y)

{
	if (map[y][x + 1] == ENEMY_SYMBOL)
		map[y][x + 1] = '1';
	if (map[y + 1][x] == ENEMY_SYMBOL)
		map[y + 1][x] = '1';
	if (map[y - 1][x] == ENEMY_SYMBOL)
		map[y - 1][x] = '1';
	if (map[y][x - 1] == ENEMY_SYMBOL)
		map[y][x - 1] = '1';
}

void	exit_parse(t_game *game, char **map, int x, int y)

{
	if (map[y - 1][x] == 'E' || map[y + 1][x] == 'E' || 
		map[y][x + 1] == 'E' || map[y][x - 1] == 'E')
	{
		game->ex_check += 1;
		map[game->exit_y][game->exit_x] = WALL_SYMBOL;
	}
}
