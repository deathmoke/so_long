/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putcount.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccadoret <ccadoret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 13:41:46 by ccadoret          #+#    #+#             */
/*   Updated: 2024/02/23 13:41:46 by ccadoret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "../includes/so_long.h"
#include "../includes/get_next_line.h"

int	putcount(t_game *g)
{
	char	*str;
	int		i;

	str = ft_itoa(g->compt);
	i = -1;
	while (str[++i])
		mlx_put_image_to_window(g->mlx, g->mlx_win,
			g->sprite[NB + str[i] - '0'].ptr, i * 50, 0);
	free(str);
	return (0);
}

int	putcount_col(t_game *g)
{
	char	*str;
	int		i;
	int		j;

	str = ft_itoa(g->nbcol_var);
	i = -1;
	while (str[++i])
		mlx_put_image_to_window(g->mlx, g->mlx_win,
			g->sprite[CC + str[i] - '0'].ptr, i * 35,
			(g->map.height * 50) - 35);
	mlx_put_image_to_window(g->mlx, g->mlx_win,
		g->sprite[ON].ptr, i * 35, (g->map.height * 50) - 35);
	i++;
	free(str);
	str = ft_itoa(g->__nbcol__);
	j = -1;
	while (str[++j])
		mlx_put_image_to_window(g->mlx, g->mlx_win,
			g->sprite[CC + str[j] - '0'].ptr, (i + j) * 35,
			(g->map.height * 50) - 35);
	free(str);
	return (0);
}

int	putnbr_screen(t_game *g, int x, int y, int nbr)
{
	char	*str;
	int		i;

	str = ft_itoa(nbr);
	i = -1;
	while (str[++i])
		mlx_put_image_to_window(g->mlx, g->mlx_win,
			g->sprite[NB + str[i] - '0'].ptr, x + i * 50, y);
	free(str);
	return (0);
}

int	putnbr_screen_small(t_game *g, int x, int y, int nbr)
{
	char	*str;
	int		i;

	str = ft_itoa(nbr);
	i = -1;
	while (str[++i])
		mlx_put_image_to_window(g->mlx, g->mlx_win,
			g->sprite[SNB + str[i] - '0'].ptr, x + i * 25, y);
	free(str);
	return (0);
}
