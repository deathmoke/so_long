/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_contact.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccadoret <ccadoret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 13:40:53 by ccadoret          #+#    #+#             */
/*   Updated: 2024/02/23 13:40:53 by ccadoret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "../includes/so_long.h"
#include "../includes/get_next_line.h"

int	find_nbenemies(t_game *g)
{
	int	i;
	int	j;

	i = -1;
	g->nb_enemies = 0;
	while (++i < g->map.height)
	{
		j = -1;
		while (++j < g->map.width)
			if (g->map.map[i][j] == 'M')
				g->nb_enemies++;
	}
	return (0);
}

int	enemies_map(t_game *g)
{
	int	i;
	int	j;
	int	indice;

	i = -1;
	indice = -1;
	find_nbenemies(g);
	g->enemies = malloc(sizeof(t_enemies) * g->nb_enemies);
	while (++i < g->map.height)
	{
		j = -1;
		while (++j < g->map.width)
		{
			if (g->map.map[i][j] == 'M')
			{
				g->enemies[++indice].x = j;
				g->enemies[indice].y = i;
				g->enemies[indice].dir = 0;
				g->enemies[indice].etat = 1;
			}
		}
	}
	return (0);
}

int	contact(t_game *g, int x, int y)
{
	int	i;

	i = -1;
	while (++i < g->nb_enemies)
	{
		if (g->enemies[i].x == x && g->enemies[i].y == y)
			if (g->enemies[i].etat == 1)
				game_over(g);
	}
	return (0);
}
