/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interact.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccadoret <ccadoret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 13:41:04 by ccadoret          #+#    #+#             */
/*   Updated: 2024/02/23 13:41:04 by ccadoret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "../includes/so_long.h"
#include "../includes/get_next_line.h"

int	bonus_keypress(int keycode, t_game *game)
{
	int	m;

	m = -1;
	if (keycode == KEY_SPACE)
	{
		attack(game);
		while (++m < game->nb_enemies)
			if (game->enemies[m].etat == 1)
				move_enemies(game, m);
	}
	if (game->start == 1)
	{
		m = -1;
		while (++m < game->nb_enemies)
			detect_player(game, m);
		putcount(game);
		putcount_col(game);
	}
	return (0);
}

void	free_tab(char **tab)
{
	int	i;

	i = -1;
	if (!tab || *tab == NULL)
		return ;
	while (tab[++i])
		free(tab[i]);
	free(tab);
}

int	close_game(t_game *game)
{
	int	i;

	i = -1;
	free_tab(game->map.map);
	while (++i < NBTEX + (NBTEX_BONUS * BONUS_MODE))
		mlx_destroy_image(game->mlx, game->sprite[i].ptr);
	free(game->sprite);
	if (BONUS_MODE)
		free(game->enemies);
	mlx_destroy_window(game->mlx, game->mlx_win);
	if (game->mlx)
		mlx_destroy_display(game->mlx);
	mlx_loop_end(game->mlx);
	free(game->mlx);
	exit(0);
}

int	keypress(int keycode, t_game *game)
{
	int	m;

	m = -1;
	if (keycode == KEY_ESCAPE)
		close_game(game);
	if (game->start == 0)
		return (0);
	if (keycode == KEY_A || keycode == KEY_W || keycode == KEY_D
		|| keycode == KEY_S || keycode == KEY_Z || keycode == KEY_Q)
	{
		move(keycode, game);
		if (BONUS_MODE)
			while (++m < game->nb_enemies)
				if (game->enemies[m].etat == 1)
					move_enemies(game, m);
	}
	if (BONUS_MODE)
		bonus_keypress(keycode, game);
	return (0);
}
