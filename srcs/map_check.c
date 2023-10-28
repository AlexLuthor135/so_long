/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alappas <alappas@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 23:27:04 by alappas           #+#    #+#             */
/*   Updated: 2023/08/14 15:54:33 by alappas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	map_check(t_game *game)

{
	char	**map;
	int		x;
	int		y;

	map = game->map_copy;
	x = game->player_position_x;
	y = game->player_position_y;
	first_spread(game, map, x, y);
	while ((game->ex_check != 1) || (game->heads != game->max_score))
	{
		if (check_spread(game, map) == 0)
			second_spread(game, map);
		else if (check_spread(game, map) == 1)
		{
			return (1);
		}
	}
	return (0);
}

char	**first_spread(t_game *game, char **map, int x, int y)

{
	while (map[y][x] != WALL_SYMBOL)
	{
		enemy_parse(map, x, y);
		collect_parse(game, map, x, y);
		floor_parse(map, x, y);
		exit_parse(game, map, x, y);
		x++;
	}
	return (map);
}

char	**second_spread(t_game *game, char **map)

{
	int	x;
	int	y;

	y = 0;
	x = 0;
	while (map[y][x] != 'R')
	{
		if (x != game->map_length)
			x++;
		else
		{
			y++;
			x = 0;
		}
	}
	while (map[y][x] != WALL_SYMBOL)
	{
		enemy_parse(map, x, y);
		collect_parse(game, map, x, y);
		floor_parse(map, x, y);
		exit_parse(game, map, x, y);
		x++;
	}
	return (map);
}

int	check_spread(t_game *game, char **map)

{
	int	x;
	int	y;

	y = 0;
	while (y != game->map_height - 1)
	{
		x = 0;
		while (x != game->map_length)
		{
			if (x == game->map_length - 1)
			{
				y++;
				break ;
			}
			if (map[y][x] != 'R')
				x++;
			else if (map[y][x] == 'R')
				return (0);
		}
	}
	return (1);
}
