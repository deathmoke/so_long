/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_utilis.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccadoret <ccadoret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 13:41:34 by ccadoret          #+#    #+#             */
/*   Updated: 2024/02/23 13:41:34 by ccadoret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "../includes/so_long.h"
#include "../includes/get_next_line.h"

void	right_utilis(t_game *g, int x, int y)
{
	mlx_put_image_to_window(g->mlx, g->mlx_win, g->sprite[FLOOR].ptr, x, y);
	mlx_put_image_to_window(g->mlx, g->mlx_win, g->sprite[PRIGHT].ptr,
		x + WIMG, y);
	g->hero.x++;
	g->compt++;
	ft_putnbr(g->compt);
	write(1, "\n", 1);
}

void	left_utilis(t_game *g, int x, int y)
{
	mlx_put_image_to_window(g->mlx, g->mlx_win, g->sprite[FLOOR].ptr, x, y);
	mlx_put_image_to_window(g->mlx, g->mlx_win, g->sprite[PLEFT].ptr,
		x - WIMG, y);
	g->hero.x--;
	g->compt++;
	ft_putnbr(g->compt);
	write(1, "\n", 1);
}

void	up_utilis(t_game *g, int x, int y)
{
	mlx_put_image_to_window(g->mlx, g->mlx_win, g->sprite[FLOOR].ptr, x, y);
	mlx_put_image_to_window(g->mlx, g->mlx_win, g->sprite[PUP].ptr,
		x, y - HIMG);
	g->hero.y--;
	g->compt++;
	ft_putnbr(g->compt);
	write(1, "\n", 1);
}

void	down_utilis(t_game *g, int x, int y)
{
	mlx_put_image_to_window(g->mlx, g->mlx_win, g->sprite[FLOOR].ptr, x, y);
	mlx_put_image_to_window(g->mlx, g->mlx_win, g->sprite[PDOWN].ptr,
		x, y + HIMG);
	g->hero.y++;
	g->compt++;
	ft_putnbr(g->compt);
	write(1, "\n", 1);
}
