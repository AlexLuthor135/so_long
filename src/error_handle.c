/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alappas <alappas@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 20:10:12 by alappas           #+#    #+#             */
/*   Updated: 2023/08/12 23:49:02 by alappas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	error_walls(t_game *game)

{
	int	x;
	int	y;
	int	z;

	z = game->map_height;
	y = 0;
	x = 0;
	while (x != game->map_length)
	{
		if (game->map_data[y][x] != WALL_SYMBOL ||
		game->map_data[z - 1][x] != WALL_SYMBOL)
			return (1);
		else
			x++;
	}
	y = 1;
	while (y != z - 1)
	{
		if (game->map_data[y][0] != WALL_SYMBOL ||
		game->map_data[y][x - 1] != WALL_SYMBOL)
			return (1);
		else
			y++;
	}
	return (0);
}

int	error_index(t_game *game)

{
	if (game->i_player != 1)
	{
		ft_printf("Wrong starting position\n");
		return (1);
	}
	else if (game->i_exit != 1)
	{
		ft_printf("Wrong exit position\n");
		return (1);
	}
	else if (game->i_collect < 1)
	{
		ft_printf("Wrong amount of collectables\n");
		return (1);
	}
	else
		return (0);
}

int	error_symbols(t_game *game)

{
	int		x;
	int		y;
	char	**map;

	map = game->map_data;
	y = 0;
	while (y != game->map_height)
	{
		x = 0;
		while (x != game->map_length)
		{
			if (map[y][x] == '1' || map[y][x] == '0' || map[y][x] == 'P'
				|| map[y][x] == 'E' || map[y][x] == 'C' || map[y][x] == 'M')
				x++;
			else
				return (1);
		}
		y++;
	}
	return (0);
}

int	error_rectangle(t_game *game)

{
	int	i;

	i = 0;
	while (i < game->map_height)
	{
		if (ft_strlen(game->map_data[0]) == ft_strlen(game->map_data[i]))
			i++;
		else
			return (1);
	}
	return (0);
}

int	error_handle(t_game *game)

{
	if (error_index(game) == 1)
		exit_game();
	else if (error_rectangle(game) == 1)
	{
		ft_printf("Map is not a rectangle\n");
		exit_game();
	}
	else if (error_symbols(game) == 1)
	{
		ft_printf("Wrong map characters\n");
		exit_game();
	}
	else if (error_walls(game) == 1)
	{
		ft_printf("Wrong wall allocation\n");
		exit_game();
	}
	else if (map_check(game) == 1)
	{
		ft_printf("This quest can't be completed, you're doomed to fail\n");
		exit_game();
	}
	return (0);
}
