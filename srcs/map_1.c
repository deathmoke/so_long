/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccadoret <ccadoret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 13:41:12 by ccadoret          #+#    #+#             */
/*   Updated: 2024/02/23 13:41:12 by ccadoret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "../includes/so_long.h"
#include "../includes/get_next_line.h"

int	putbase(t_game *g, int i, int j)
{
	if (g->map.map[i][j] == '0')
		mlx_put_image_to_window(g->mlx, g->mlx_win,
			g->sprite[FLOOR].ptr, j * 50, i * 50);
	else if (g->map.map[i][j] == '1')
		mlx_put_image_to_window(g->mlx, g->mlx_win,
			g->sprite[4 + rand() % 3].ptr, j * 50, i * 50);
	return (0);
}

int	putimg(t_game *g, int i, int j)
{
	putbase(g, i, j);
	if (g->map.map[i][j] == 'C')
	{
		mlx_put_image_to_window(g->mlx, g->mlx_win,
			g->sprite[COLLEC].ptr, j * 50, i * 50);
		g->nbcol++;
		g->__nbcol__++;
	}
	else if (g->map.map[i][j] == 'P')
	{
		g->hero.x = j;
		g->hero.y = i;
		mlx_put_image_to_window(g->mlx, g->mlx_win,
			g->sprite[PDOWN].ptr, j * 50, i * 50);
	}
	else if (g->map.map[i][j] == 'E')
		mlx_put_image_to_window(g->mlx, g->mlx_win,
			g->sprite[EXIT_C].ptr, j * 50, i * 50);
	else if (g->map.map[i][j] == 'M')
		if (BONUS_MODE)
			mlx_put_image_to_window(g->mlx, g->mlx_win,
				g->sprite[EDOWN].ptr, j * 50, i * 50);
	return (0);
}

int	open_exit(t_game *game)
{
	int	i;
	int	j;

	if (game->start == 0)
		return (1);
	i = -1;
	while (game->map.map[++i])
	{
		j = -1;
		while (game->map.map[i][++j])
		{
			if (game->map.map[i][j] == 'E')
			{
				mlx_put_image_to_window(game->mlx, game->mlx_win,
					game->sprite[EXIT_O].ptr, j * 50, i * 50);
				return (0);
			}
		}
	}
	return (0);
}

int	print_game(t_game *g)
{
	int	i;
	int	j;

	i = -1;
	while (g->map.map[++i])
	{
		j = -1;
		while (g->map.map[i][++j])
			putimg(g, i, j);
	}
	if (BONUS_MODE)
	{
		i = -1;
		while (++i < 4)
			mlx_put_image_to_window(g->mlx, g->mlx_win,
				g->sprite[NBNUL].ptr, i * 50, 0);
		i = -1;
		while (++i < 4)
			mlx_put_image_to_window(g->mlx, g->mlx_win,
				g->sprite[CCNUL].ptr, i * 35, (g->map.height * 50) - 35);
	}
	return (0);
}

t_sprite	mk_st(void *mlx, char *path, int x, int y)
{
	t_sprite	s;

	s.width = x;
	s.height = y;
	s.ptr = mlx_xpm_file_to_image(mlx, path, &s.width, &s.height);
	return (s);
}
