/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_move_utilis.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccadoret <ccadoret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 13:40:57 by ccadoret          #+#    #+#             */
/*   Updated: 2024/02/23 13:40:57 by ccadoret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "../includes/so_long.h"
#include "../includes/get_next_line.h"

void	right_utilis_enemy(t_game *g, int x, int y, int m)
{
	mlx_put_image_to_window(g->mlx, g->mlx_win, g->sprite[FLOOR].ptr, x, y);
	mlx_put_image_to_window(g->mlx, g->mlx_win, g->sprite[ERIGHT].ptr,
		x + WIMG, y);
	g->enemies[m].x++;
	g->enemies[m].dir = DIR_RIGHT;
	detect_player(g, m);
}

void	left_utilis_enemy(t_game *g, int x, int y, int m)
{
	mlx_put_image_to_window(g->mlx, g->mlx_win, g->sprite[FLOOR].ptr, x, y);
	mlx_put_image_to_window(g->mlx, g->mlx_win, g->sprite[ELEFT].ptr,
		x - WIMG, y);
	g->enemies[m].x--;
	g->enemies[m].dir = DIR_LEFT;
	detect_player(g, m);
}

void	up_utilis_enemy(t_game *g, int x, int y, int m)
{
	mlx_put_image_to_window(g->mlx, g->mlx_win, g->sprite[FLOOR].ptr, x, y);
	mlx_put_image_to_window(g->mlx, g->mlx_win, g->sprite[EUP].ptr,
		x, y - HIMG);
	g->enemies[m].y--;
	g->enemies[m].dir = DIR_UP;
	detect_player(g, m);
}

void	down_utilis_enemy(t_game *g, int x, int y, int m)
{
	mlx_put_image_to_window(g->mlx, g->mlx_win, g->sprite[FLOOR].ptr, x, y);
	mlx_put_image_to_window(g->mlx, g->mlx_win, g->sprite[EDOWN].ptr, x,
		y + HIMG);
	g->enemies[m].y++;
	g->enemies[m].dir = DIR_DOWN;
	detect_player(g, m);
}
