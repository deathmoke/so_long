/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detect.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccadoret <ccadoret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 13:40:38 by ccadoret          #+#    #+#             */
/*   Updated: 2024/02/23 13:40:38 by ccadoret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "../includes/so_long.h"
#include "../includes/get_next_line.h"
#include <stdio.h>

int	print_sprite_temp(t_game *g, int s, int m)
{
	mlx_put_image_to_window(g->mlx, g->mlx_win, g->sprite[s].ptr,
		g->enemies[m].x * 50, g->enemies[m].y * 50);
	mlx_do_sync(g->mlx);
	usleep(1000000);
	return (0);
}

int	detect_player_y(t_game *g, int m)
{
	if (g->enemies[m].dir == DIR_DOWN)
	{
		if (g->hero.y == g->enemies[m].y + 1)
		{
			if (g->hero.x == g->enemies[m].x)
			{
				print_sprite_temp(g, ESHOOTD, m);
				game_over(g);
			}
		}
	}
	if (g->enemies[m].dir == DIR_UP)
	{
		if (g->hero.y == g->enemies[m].y - 1)
		{
			if (g->hero.x == g->enemies[m].x)
			{
				print_sprite_temp(g, ESHOOTU, m);
				game_over(g);
			}
		}
	}
	return (0);
}

int	detect_player_x(t_game *g, int m)
{
	if (g->enemies[m].dir == DIR_RIGHT)
	{
		if (g->hero.y == g->enemies[m].y)
		{
			if (g->hero.x == g->enemies[m].x + 1)
			{
				print_sprite_temp(g, ESHOOTR, m);
				game_over(g);
			}
		}
	}
	if (g->enemies[m].dir == DIR_LEFT)
	{
		if (g->hero.y == g->enemies[m].y)
		{
			if (g->hero.x == g->enemies[m].x - 1)
			{
				print_sprite_temp(g, ESHOOTL, m);
				game_over(g);
			}
		}
	}
	return (0);
}

int	detect_player(t_game *g, int m)
{
	if (g->enemies[m].etat == 0)
		return (1);
	detect_player_x(g, m);
	detect_player_y(g, m);
	contact(g, g->hero.x, g->hero.y);
	return (0);
}
