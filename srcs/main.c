/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccadoret <ccadoret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 13:41:08 by ccadoret          #+#    #+#             */
/*   Updated: 2024/02/23 13:41:08 by ccadoret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "../includes/so_long.h"
#include "../includes/get_next_line.h"
#include <stdio.h>

int	print_check(t_game game)
{
	if (!check(game.map))
	{
		free_struct(&game.map);
		write(1, "Invalid map !\nPlease enter a correct map\n", 41);
		exit(1);
	}
	return (0);
}

int	len_tab(int fd)
{
	char	*str;
	int		i;

	i = 0;
	str = get_next_line(fd);
	while (str != NULL)
	{
		i++;
		free(str);
		str = get_next_line(fd);
	}
	free(str);
	return (i);
}

int	open_file(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		write(1, "error while opening fd\n", 23);
		exit(1);
	}
	return (fd);
}

void	create_map(t_map *map, char *path)
{
	int		size;
	int		i;
	int		fd;

	i = -1;
	fd = open_file(path);
	size = len_tab(fd);
	close(fd);
	fd = open_file(path);
	map->map = malloc(sizeof(char *) * (size + 1));
	if (map->map == NULL)
		return ;
	while (++i < size)
		map->map[i] = get_next_line(fd);
	map->map[i] = NULL;
	map->height = size;
	map->width = ft_strlen(map->map[i - 1]);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		return (1);
	game.compt = 0;
	create_map(&game.map, argv[1]);
	print_check(game);
	game.mlx = mlx_init();
	init_sprite(&game);
	game.mlx_win = mlx_new_window(game.mlx, game.map.width * 50,
			game.map.height * 50, "so_long");
	game.nbcol = 0;
	game.nbcol_var = 0;
	game.start = 1;
	game.__nbcol__ = 0;
	print_game(&game);
	mlx_hook(game.mlx_win, 2, (1L << 0), keypress, &game);
	mlx_hook(game.mlx_win, 17, (1L << 17), close_game, &game);
	mlx_loop(game.mlx);
	return (0);
}
