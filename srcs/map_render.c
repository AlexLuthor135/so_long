/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alappas <alappas@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 19:02:58 by alappas           #+#    #+#             */
/*   Updated: 2023/08/04 19:30:05 by alappas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	count_y(int fd)

{
	int		i;
	char	*s;

	i = 0;
	s = get_next_line(fd);
	while (s)
	{
		free(s);
		s = get_next_line(fd);
		i++;
	}
	free(s);
	return (i);
}

char	**map_render(t_game *game, char *map)


{
	int		fd;
	int		i;
	char	**world;
	char	*str;

	i = 0;
	fd = open(map, O_RDONLY);
	if (fd < 0)
		error_fd();
	game->map_height = (count_y(fd));
	world = ft_calloc((sizeof(char *)) * game->map_height, 1);
	if (!world)
		return (NULL);
	close(fd);
	fd = open(map, O_RDONLY);
	str = get_next_line(fd);
	while (str)
	{
		world[i] = str;
		str = get_next_line(fd);
		i++;
	}
	close(fd);
	return (world);
}

void	error_fd(void)

{
	ft_printf("Invalid read\n");
	exit_game();
}
