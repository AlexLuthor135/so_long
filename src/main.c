/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alappas <alappas@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 16:54:23 by alappas           #+#    #+#             */
/*   Updated: 2024/05/21 22:36:47 by alappas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	empty_map(t_game *game)
{
	int	i;

	i = 0;
	if (!game->map_data || !game->map_data[0]
		|| ft_strlen(game->map_data[0]) < 3)
	{
		ft_printf("Empty/Wrong map\n");
		if (game->map_data)
		{
			while (game->map_data[i])
			{
				free(game->map_data[i]);
				i++;
			}
			free(game->map_data);
		}
		if (game)
			free(game);
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)

{
	t_game	*game;

	if (argc != 2)
		return (ft_printf("Wrong amount of arguments\n"), 0);
	if (check_ext(argv[1]) == 1)
		return (0);
	game = ft_calloc(sizeof(t_game), 1);
	game->map_data = map_render(game, argv[1]);
	if (empty_map(game) == 1)
		return (0);
	game->map_copy = map_render(game, argv[1]);
	game->map_length = ft_strlen(game->map_data[0]) - 1;
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->map_length * 32,
			game->map_height * 32, "Golden Sun");
	printf("I am here\n");
	image_render(game);
	image_assign(game);
	error_handle(game);
	mlx_hook(game->win, 17, 1L << 0, exit_game, game);
	mlx_key_hook(game->win, key_action, game);
	mlx_loop(game->mlx);
	return (0);
}

int	check_ext(char *s2)

{
	char	*s1;
	int		i;
	int		j;

	s1 = ".ber";
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	while (i >= 0)
	{
		if (s1[i] == s2[j])
		{
			i--;
			j--;
		}
		else
		{
			ft_printf("Wrong map extension\n");
			return (1);
		}
	}
	return (0);
}

int	exit_game(void)

{
	exit(0);
	return (0);
}
