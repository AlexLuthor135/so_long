/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alappas <alappas@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 00:07:03 by alappas           #+#    #+#             */
/*   Updated: 2023/10/21 19:59:27 by alappas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	score_handle(t_game *game)

{
	mlx_put_image_to_window(game->mlx, game->win,
		game->frame, 0, -2);
	mlx_string_put(game->mlx, game->win, 25, 24, -1, "Number of steps:");
	game->str = ft_itoa(game->steps);
	mlx_string_put(game->mlx, game->win, 140, 24, -1, game->str);
	free (game->str);
}

void	lose_state(t_game *game)

{
	int	x;
	int	y;

	x = game->player_position_x;
	y = game->player_position_y;
	mlx_put_image_to_window(game->mlx, game->win, game->floor, x * 32, y * 32);
	mlx_put_image_to_window(game->mlx, game->win, game->p_dead, x * 32, y * 32);
}
