/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccadoret <ccadoret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 13:41:40 by ccadoret          #+#    #+#             */
/*   Updated: 2024/02/23 13:41:40 by ccadoret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "../includes/so_long.h"
#include "../includes/get_next_line.h"
#include <stdio.h>

int	right(t_game *g)
{
	if (g->map.map[g->hero.y][g->hero.x + 1] == 'E' && g->nbcol <= 0)
		victory(g);
	if (g->map.map[g->hero.y][g->hero.x + 1] == '1'
		|| g->map.map[g->hero.y][g->hero.x + 1] == 'E')
		return (1);
	if (g->map.map[g->hero.y][g->hero.x + 1] == 'C')
	{
		g->nbcol--;
		g->nbcol_var++;
		g->map.map[g->hero.y][g->hero.x + 1] = '0';
		right_utilis(g, g->hero.x * WIMG, g->hero.y * HIMG);
		if (BONUS_MODE)
			contact(g, g->hero.x, g->hero.y);
		return (0);
	}
	right_utilis(g, g->hero.x * WIMG, g->hero.y * HIMG);
	if (BONUS_MODE)
		contact(g, g->hero.x, g->hero.y);
	return (0);
}

int	left(t_game *g)
{
	if (g->map.map[g->hero.y][g->hero.x - 1] == 'E' && g->nbcol <= 0)
		victory(g);
	if (g->map.map[g->hero.y][g->hero.x - 1] == '1'
		|| g->map.map[g->hero.y][g->hero.x - 1] == 'E')
		return (1);
	if (g->map.map[g->hero.y][g->hero.x - 1] == 'C')
	{
		g->nbcol--;
		g->nbcol_var++;
		g->map.map[g->hero.y][g->hero.x - 1] = '0';
		left_utilis(g, g->hero.x * WIMG, g->hero.y * HIMG);
		if (BONUS_MODE)
			contact(g, g->hero.x, g->hero.y);
		return (0);
	}
	left_utilis(g, g->hero.x * WIMG, g->hero.y * HIMG);
	if (BONUS_MODE)
		contact(g, g->hero.x, g->hero.y);
	return (0);
}

int	up(t_game *g)
{
	if (g->map.map[g->hero.y - 1][g->hero.x] == 'E' && g->nbcol <= 0)
		victory(g);
	if (g->map.map[g->hero.y - 1][g->hero.x] == '1'
		|| g->map.map[g->hero.y - 1][g->hero.x] == 'E')
		return (1);
	if (g->map.map[g->hero.y - 1][g->hero.x] == 'C')
	{
		g->nbcol--;
		g->nbcol_var++;
		g->map.map[g->hero.y - 1][g->hero.x] = '0';
		up_utilis(g, g->hero.x * WIMG, g->hero.y * HIMG);
		if (BONUS_MODE)
			contact(g, g->hero.x, g->hero.y);
		return (0);
	}
	up_utilis(g, g->hero.x * WIMG, g->hero.y * HIMG);
	if (BONUS_MODE)
		contact(g, g->hero.x, g->hero.y);
	return (0);
}

int	down(t_game *g)
{
	if (g->map.map[g->hero.y + 1][g->hero.x] == 'E' && g->nbcol <= 0)
		victory(g);
	if (g->map.map[g->hero.y + 1][g->hero.x] == '1'
		|| g->map.map[g->hero.y + 1][g->hero.x] == 'E')
		return (1);
	if (g->map.map[g->hero.y + 1][g->hero.x] == 'C')
	{
		g->nbcol--;
		g->nbcol_var++;
		g->map.map[g->hero.y + 1][g->hero.x] = '0';
		down_utilis(g, g->hero.x * WIMG, g->hero.y * HIMG);
		if (BONUS_MODE)
			contact(g, g->hero.x, g->hero.y);
		return (0);
	}
	down_utilis(g, g->hero.x * WIMG, g->hero.y * HIMG);
	if (BONUS_MODE)
		contact(g, g->hero.x, g->hero.y);
	return (0);
}

void	move(int keycode, t_game *game)
{
	if (game->start == 0)
		return ;
	if (keycode == KEY_W || keycode == KEY_Z)
		up(game);
	if (keycode == KEY_S)
		down(game);
	if (keycode == KEY_D)
		right(game);
	if (keycode == KEY_A || keycode == KEY_Q)
		left(game);
	if (game->nbcol == 0)
		open_exit(game);
}
