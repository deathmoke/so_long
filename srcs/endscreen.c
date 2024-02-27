/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   endscreen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccadoret <ccadoret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 13:40:46 by ccadoret          #+#    #+#             */
/*   Updated: 2024/02/23 13:40:46 by ccadoret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "../includes/so_long.h"
#include "../includes/get_next_line.h"

int	put_nb_on_screen(t_game *g, int score_bonus)
{
	if (g->map.height >= 12 && g->map.width >= 20)
	{
		putnbr_screen(g, g->map.width * 50 / 2,
			g->map.height * 50 / 2 - 100, g->compt);
		score_bonus = -g->nbcol;
		putnbr_screen(g, g->map.width * 50 / 2,
			g->map.height * 50 / 2, score_bonus);
		score_bonus = g->compt - (score_bonus * 10);
		putnbr_screen(g, g->map.width * 50 / 2,
			g->map.height * 50 / 2 + 100, score_bonus);
	}
	else
	{
		putnbr_screen_small(g, g->map.width * 50 / 2,
			g->map.height * 50 / 2 - 26, g->compt);
		score_bonus = -g->nbcol;
		putnbr_screen_small(g, g->map.width * 50 / 2,
			g->map.height * 50 / 2, score_bonus);
		score_bonus = g->compt - (score_bonus * 10);
		putnbr_screen_small(g, g->map.width * 50 / 2 + 30,
			g->map.height * 50 / 2 + 26, score_bonus);
	}
	return (0);
}

int	put_screen(t_game *g, int end, int i, int j)
{
	if (end == WON)
	{
		if (g->map.height >= 12 && g->map.width >= 20)
			mlx_put_image_to_window(g->mlx, g->mlx_win,
				g->sprite[BIG_WON].ptr,
				((j * 50) - 1000) / 2, ((i * 50) - 600) / 2);
		else
			mlx_put_image_to_window(g->mlx, g->mlx_win,
				g->sprite[LITTLE_WON].ptr,
				((j * 50) - 250) / 2, ((i * 50) - 150) / 2);
	}
	if (end == LOSE)
	{
		if (g->map.height >= 12 && g->map.width >= 20)
			mlx_put_image_to_window(g->mlx, g->mlx_win,
				g->sprite[BIG_GO].ptr,
				((j * 50) - 1000) / 2, ((i * 50) - 600) / 2);
		else
			mlx_put_image_to_window(g->mlx, g->mlx_win,
				g->sprite[LITTLE_GO].ptr,
				((j * 50) - 250) / 2, ((i * 50) - 150) / 2);
	}
	return (0);
}

int	print_screen(t_game *g, int end)
{
	int	i;
	int	j;

	i = -1;
	mlx_do_sync(g->mlx);
	while (++i < g->map.height)
	{
		j = -1;
		while (++j < g->map.width)
		{
			mlx_do_sync(g->mlx);
			usleep(1000);
			mlx_put_image_to_window(g->mlx, g->mlx_win,
				g->sprite[BLACK].ptr, j * 50, i * 50);
		}
	}
	put_screen(g, end, i, j);
	return (0);
}

int	victory(t_game *g)
{
	if (!BONUS_MODE)
		close_game(g);
	print_screen(g, WON);
	put_nb_on_screen(g, 0);
	g->start = 0;
	return (0);
}

int	game_over(t_game *g)
{
	if (!BONUS_MODE)
		close_game(g);
	g->start = 0;
	mlx_do_sync(g->mlx);
	usleep(200000);
	print_screen(g, LOSE);
	return (0);
}
