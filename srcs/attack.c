/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attack.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccadoret <ccadoret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 13:40:32 by ccadoret          #+#    #+#             */
/*   Updated: 2024/02/23 13:40:32 by ccadoret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "../includes/so_long.h"
#include "../includes/get_next_line.h"

int	attack_up(t_game *g, int m)
{
	int	x;
	int	y;

	x = g->hero.x;
	y = g->hero.y;
	mlx_put_image_to_window(g->mlx, g->mlx_win,
		g->sprite[PSHOOTU].ptr, x * 50, y * 50);
	mlx_put_image_to_window(g->mlx, g->mlx_win,
		g->sprite[DEAD].ptr, x * 50, (y - 1) * 50);
	g->map.map[y - 1][x] = 'C';
	g->enemies[m].etat = 0;
	return (0);
}

int	attack_down(t_game *g, int m)
{
	int	x;
	int	y;

	x = g->hero.x;
	y = g->hero.y;
	mlx_put_image_to_window(g->mlx, g->mlx_win,
		g->sprite[PSHOOTD].ptr, x * 50, y * 50);
	mlx_put_image_to_window(g->mlx, g->mlx_win,
		g->sprite[DEAD].ptr, x * 50, (y + 1) * 50);
	g->map.map[y + 1][x] = 'C';
	g->enemies[m].etat = 0;
	return (0);
}

int	attack_left(t_game *g, int m)
{
	int	x;
	int	y;

	x = g->hero.x;
	y = g->hero.y;
	mlx_put_image_to_window(g->mlx, g->mlx_win,
		g->sprite[PSHOOTL].ptr, x * 50, y * 50);
	mlx_put_image_to_window(g->mlx, g->mlx_win,
		g->sprite[DEAD].ptr, (x - 1) * 50, y * 50);
	g->map.map[y][x - 1] = 'C';
	g->enemies[m].etat = 0;
	return (0);
}

int	attack_right(t_game *g, int m)
{
	int	x;
	int	y;

	x = g->hero.x;
	y = g->hero.y;
	mlx_put_image_to_window(g->mlx, g->mlx_win,
		g->sprite[PSHOOTR].ptr, x * 50, y * 50);
	mlx_put_image_to_window(g->mlx, g->mlx_win,
		g->sprite[DEAD].ptr, (x + 1) * 50, y * 50);
	g->map.map[y][x + 1] = 'C';
	g->enemies[m].etat = 0;
	return (0);
}

int	attack(t_game *g)
{
	int	i;

	i = -1;
	while (++i < g->nb_enemies)
		if (g->enemies[i].x == g->hero.x && g->enemies[i].y == g->hero.y - 1)
			if (g->enemies[i].etat)
				attack_up(g, i);
	i = -1;
	while (++i < g->nb_enemies)
		if (g->enemies[i].x == g->hero.x && g->enemies[i].y == g->hero.y + 1)
			if (g->enemies[i].etat)
				attack_down(g, i);
	i = -1;
	while (++i < g->nb_enemies)
		if (g->enemies[i].x == g->hero.x - 1 && g->enemies[i].y == g->hero.y)
			if (g->enemies[i].etat)
				attack_left(g, i);
	i = -1;
	while (++i < g->nb_enemies)
		if (g->enemies[i].x == g->hero.x + 1 && g->enemies[i].y == g->hero.y)
			if (g->enemies[i].etat)
				attack_right(g, i);
	return (0);
}
