/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_enemies.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccadoret <ccadoret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 13:41:24 by ccadoret          #+#    #+#             */
/*   Updated: 2024/02/23 13:41:24 by ccadoret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "../includes/so_long.h"
#include "../includes/get_next_line.h"

int	right_enemy(t_game *g, int m)
{
	if (g->map.map[g->enemies[m].y][g->enemies[m].x + 1] == '1' ||
		g->map.map[g->enemies[m].y][g->enemies[m].x + 1] == 'E' ||
		g->map.map[g->enemies[m].y][g->enemies[m].x + 1] == 'C')
		return (1);
	right_utilis_enemy(g, g->enemies[m].x * WIMG, g->enemies[m].y * HIMG, m);
	return (0);
}

int	left_enemy(t_game *g, int m)
{
	if (g->map.map[g->enemies[m].y][g->enemies[m].x - 1] == '1' ||
		g->map.map[g->enemies[m].y][g->enemies[m].x - 1] == 'E' ||
		g->map.map[g->enemies[m].y][g->enemies[m].x - 1] == 'C')
		return (1);
	left_utilis_enemy(g, g->enemies[m].x * WIMG, g->enemies[m].y * HIMG, m);
	return (0);
}

int	up_enemy(t_game *g, int m)
{
	if (g->map.map[g->enemies[m].y - 1][g->enemies[m].x] == '1' ||
		g->map.map[g->enemies[m].y - 1][g->enemies[m].x] == 'E' ||
		g->map.map[g->enemies[m].y - 1][g->enemies[m].x] == 'C')
		return (1);
	up_utilis_enemy(g, g->enemies[m].x * WIMG, g->enemies[m].y * HIMG, m);
	return (0);
}

int	down_enemy(t_game *g, int m)
{
	if (g->map.map[g->enemies[m].y + 1][g->enemies[m].x] == '1' ||
		g->map.map[g->enemies[m].y + 1][g->enemies[m].x] == 'E' ||
		g->map.map[g->enemies[m].y + 1][g->enemies[m].x] == 'C')
		return (1);
	down_utilis_enemy(g, g->enemies[m].x * WIMG, g->enemies[m].y * HIMG, m);
	return (0);
}

int	move_enemies(t_game *g, int m)
{
	int	r;

	if (g->start == 0)
		return (1);
	r = rand() % 5;
	if (r == DIR_LEFT)
		left_enemy(g, m);
	if (r == DIR_RIGHT)
		right_enemy(g, m);
	if (r == DIR_UP)
		up_enemy(g, m);
	if (r == DIR_DOWN)
		down_enemy(g, m);
	return (0);
}
