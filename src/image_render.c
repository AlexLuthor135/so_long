/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_render.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alappas <alappas@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 16:33:24 by alappas           #+#    #+#             */
/*   Updated: 2024/05/15 19:45:56 by alappas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	image_render(t_game *game)
{
	if (!game)
		return ;
	game->wall = mlx_xpm_file_to_image(game->mlx, WALL, &game->x, &game->y);
	game->exit = mlx_xpm_file_to_image(game->mlx, EXIT, &game->x, &game->y);
	game->floor = mlx_xpm_file_to_image(game->mlx, FLOOR, &game->x, &game->y);
	game->collect = mlx_xpm_file_to_image(game->mlx,
			COLLECT, &game->x, &game->y);
	game->p_up = mlx_xpm_file_to_image(game->mlx, PUP, &game->x, &game->y);
	game->p_down = mlx_xpm_file_to_image(game->mlx, PDOWN, &game->x, &game->y);
	game->p_left = mlx_xpm_file_to_image(game->mlx, PLEFT, &game->x, &game->y);
	game->p_right = mlx_xpm_file_to_image(game->mlx,
			PRIGHT, &game->x, &game->y);
	game->exit_closed = mlx_xpm_file_to_image(game->mlx,
			EXIT_C, &game->x, &game->y);
	game->p_collect = mlx_xpm_file_to_image(game->mlx,
			PCOLLECT, &game->x, &game->y);
	game->frame = mlx_xpm_file_to_image(game->mlx,
			FRAME, &game->x, &game->y);
	game->success = mlx_xpm_file_to_image(game->mlx,
			SUCCESS, &game->x, &game->y);
	bonus_render(game);
	image_error(game);
}

void	bonus_render(t_game *game)
{
	game->m1 = mlx_xpm_file_to_image(game->mlx, M1, &game->x, &game->y);
	game->p_dead = mlx_xpm_file_to_image(game->mlx, PDEAD, &game->x, &game->y);
}

void	image_error(t_game *game)

{
	if (game->wall == NULL || game->exit == NULL || game->floor == NULL
		|| game->p_up == NULL || game->p_down == NULL || game->p_left == NULL
		|| game->p_right == NULL || game->exit_closed == NULL
		|| game->p_collect == NULL || game->collect == NULL
		|| game->frame == NULL || game->m1 == NULL || game->p_dead == NULL
		|| game->success == NULL)
	{
		ft_printf("Invalid sprite path\n");
		exit_game();
	}
}
