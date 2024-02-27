/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccadoret <ccadoret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 13:42:00 by ccadoret          #+#    #+#             */
/*   Updated: 2024/02/23 13:42:00 by ccadoret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "../includes/so_long.h"
#include "../includes/get_next_line.h"
#include <stdio.h>
#include <unistd.h>

t_map	mapdup(t_map *map)
{
	t_map	newmap;
	int		i;
	int		j;

	newmap.width = map->width;
	newmap.height = map->height;
	i = -1;
	newmap.map = malloc(sizeof(char *) * (map->height + 1));
	if (!newmap.map)
		return (newmap);
	while (++i < map->height)
	{
		newmap.map[i] = malloc(sizeof(char) * (map->width + 1));
		if (!newmap.map[i])
		{
			free_struct(&newmap);
			return (newmap);
		}
		j = -1;
		while (++j < map->width)
			newmap.map[i][j] = map->map[i][j];
		newmap.map[i][j] = '\0';
	}
	newmap.map[i] = NULL;
	return (newmap);
}

int	test_way(t_map *map, int x, int y)
{
	int	nbcol;

	if (x < 0 || y < 0 || x >= map->width || y >= map->height)
		return (0);
	if (map->map[y][x] == 'X' || map->map[y][x] == '1')
		return (0);
	nbcol = 0;
	if (map->map[y][x] == 'C' || map->map[y][x] == 'E')
	{
		map->map[y][x] = 'X';
		nbcol++;
		if (map->map[y][x] != 'E')
		{
			nbcol += test_way(map, x, y + 1);
			nbcol += test_way(map, x + 1, y);
			nbcol += test_way(map, x, y - 1);
			nbcol += test_way(map, x - 1, y);
		}
	}
	map->map[y][x] = 'X';
	nbcol += test_way(map, x, y + 1);
	nbcol += test_way(map, x + 1, y);
	nbcol += test_way(map, x, y - 1);
	nbcol += test_way(map, x - 1, y);
	return (nbcol);
}

int	check_obj(t_map map)
{
	int	nbcol;
	int	e;
	int	i;
	int	j;

	nbcol = 0;
	i = -1;
	e = 0;
	while (map.map[++i])
	{
		j = -1;
		while (map.map[i][++j])
		{
			if (map.map[i][j] == 'M' && !BONUS_MODE)
				return (0);
			if (map.map[i][j] == 'C')
				nbcol++;
			if (map.map[i][j] == 'E')
				e++;
		}
	}
	if (e == 1)
		return (nbcol);
	return (0);
}

int	check_first(t_map map)
{
	int	i;
	int	j;
	int	p;
	int	nbcol;

	i = -1;
	p = 0;
	while (++i < map.height)
	{
		j = -1;
		while (++j < map.width)
		{
			if ((i == 0 || j == 0 || i == map.height - 1
					|| j == map.width - 1) && (map.map[i][j] != '1'))
				return (0);
			if (map.map[i][j] == 'P')
				p++;
		}
	}
	nbcol = check_obj(map);
	if (nbcol == 0 || p == 0)
		return (0);
	return (1);
}

int	check(t_map map)
{
	t_map	testmap;
	int		nbcol;
	int		i;
	int		j;

	testmap = mapdup(&map);
	if (!testmap.map)
		return (0);
	nbcol = check_obj(testmap);
	if (!check_first(testmap) || nbcol == 0 || !check_char(testmap))
	{
		free_struct(&testmap);
		return (0);
	}
	find_p(&testmap, &j, &i);
	if (nbcol + 1 != test_way(&testmap, j, i))
	{
		free_struct(&testmap);
		return (0);
	}
	free_struct(&testmap);
	return (nbcol);
}
