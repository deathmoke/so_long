/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccadoret <ccadoret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 13:41:19 by ccadoret          #+#    #+#             */
/*   Updated: 2024/02/23 13:41:19 by ccadoret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "../includes/so_long.h"
#include "../includes/get_next_line.h"
#include <stdio.h>

t_sprite	make_sprite(void *mlx, char *path)
{
	t_sprite	s;

	s.width = WIMG;
	s.height = HIMG;
	s.ptr = mlx_xpm_file_to_image(mlx, path, &s.width, &s.height);
	return (s);
}

int	init_final(t_game *g)
{
	g->sprite[BLACK] = make_sprite(g->mlx, "asset/black.xpm");
	g->sprite[LITTLE_WON] = mk_st(g->mlx, "asset/basicwon.xpm", 250, 150);
	g->sprite[BIG_WON] = mk_st(g->mlx, "asset/bigwon.xpm", 1000, 600);
	g->sprite[LITTLE_GO] = mk_st(g->mlx, "asset/gameoverscreen.xpm", 250, 150);
	g->sprite[BIG_GO] = mk_st(g->mlx, "asset/biggameover.xpm", 1000, 600);
	g->sprite[SNB] = make_sprite(g->mlx, "asset/small0.xpm");
	g->sprite[SNB + 1] = mk_st(g->mlx, "asset/small1.xpm", 25, 25);
	g->sprite[SNB + 2] = mk_st(g->mlx, "asset/small2.xpm", 25, 25);
	g->sprite[SNB + 3] = mk_st(g->mlx, "asset/small3.xpm", 25, 25);
	g->sprite[SNB + 4] = mk_st(g->mlx, "asset/small4.xpm", 25, 25);
	g->sprite[SNB + 5] = mk_st(g->mlx, "asset/small5.xpm", 25, 25);
	g->sprite[SNB + 6] = mk_st(g->mlx, "asset/small6.xpm", 25, 25);
	g->sprite[SNB + 7] = mk_st(g->mlx, "asset/small7.xpm", 25, 25);
	g->sprite[SNB + 8] = mk_st(g->mlx, "asset/small8.xpm", 25, 25);
	g->sprite[SNB + 9] = mk_st(g->mlx, "asset/small9.xpm", 25, 25);
	return (0);
}

int	init_count(t_game *g)
{
	g->sprite[NB] = make_sprite(g->mlx, "asset/0.xpm");
	g->sprite[NB + 1] = make_sprite(g->mlx, "asset/1.xpm");
	g->sprite[NB + 2] = make_sprite(g->mlx, "asset/2.xpm");
	g->sprite[NB + 3] = make_sprite(g->mlx, "asset/3.xpm");
	g->sprite[NB + 4] = make_sprite(g->mlx, "asset/4.xpm");
	g->sprite[NB + 5] = make_sprite(g->mlx, "asset/5.xpm");
	g->sprite[NB + 6] = make_sprite(g->mlx, "asset/6.xpm");
	g->sprite[NB + 7] = make_sprite(g->mlx, "asset/7.xpm");
	g->sprite[NB + 8] = make_sprite(g->mlx, "asset/8.xpm");
	g->sprite[NB + 9] = make_sprite(g->mlx, "asset/9.xpm");
	g->sprite[NBNUL] = make_sprite(g->mlx, "asset/none.xpm");
	g->sprite[CC] = make_sprite(g->mlx, "asset/0c.xpm");
	g->sprite[CC + 1] = make_sprite(g->mlx, "asset/1c.xpm");
	g->sprite[CC + 2] = make_sprite(g->mlx, "asset/2c.xpm");
	g->sprite[CC + 3] = make_sprite(g->mlx, "asset/3c.xpm");
	g->sprite[CC + 4] = make_sprite(g->mlx, "asset/4c.xpm");
	g->sprite[CC + 5] = make_sprite(g->mlx, "asset/5c.xpm");
	g->sprite[CC + 6] = make_sprite(g->mlx, "asset/6c.xpm");
	g->sprite[CC + 7] = make_sprite(g->mlx, "asset/7c.xpm");
	g->sprite[CC + 8] = make_sprite(g->mlx, "asset/8c.xpm");
	g->sprite[CC + 9] = make_sprite(g->mlx, "asset/9c.xpm");
	g->sprite[CCNUL] = make_sprite(g->mlx, "asset/nonec.xpm");
	g->sprite[ON] = make_sprite(g->mlx, "asset/on.xpm");
	return (0);
}

int	init_sprite_enemies(t_game *g)
{
	g->sprite[EDOWN] = make_sprite(g->mlx, "asset/enemy_down.xpm");
	g->sprite[EUP] = make_sprite(g->mlx, "asset/enemy_up.xpm");
	g->sprite[ERIGHT] = make_sprite(g->mlx, "asset/enemy_right.xpm");
	g->sprite[ELEFT] = make_sprite(g->mlx, "asset/enemy_left.xpm");
	g->sprite[ESHOOTD] = make_sprite(g->mlx, "asset/enemy_shoot_d.xpm");
	g->sprite[ESHOOTU] = make_sprite(g->mlx, "asset/enemy_shoot_u.xpm");
	g->sprite[ESHOOTR] = make_sprite(g->mlx, "asset/enemy_shoot_r.xpm");
	g->sprite[ESHOOTL] = make_sprite(g->mlx, "asset/enemy_shoot_l.xpm");
	g->sprite[PSHOOTD] = make_sprite(g->mlx, "asset/player_shoot_d.xpm");
	g->sprite[PSHOOTU] = make_sprite(g->mlx, "asset/player_shoot_u.xpm");
	g->sprite[PSHOOTR] = make_sprite(g->mlx, "asset/player_shoot_r.xpm");
	g->sprite[PSHOOTL] = make_sprite(g->mlx, "asset/player_shoot_l.xpm");
	g->sprite[DEAD] = make_sprite(g->mlx, "asset/dead_body.xpm");
	init_count(g);
	enemies_map(g);
	return (0);
}

int	init_sprite(t_game *g)
{
	g->sprite = malloc(sizeof(t_sprite) * (NBTEX + (NBTEX_BONUS * BONUS_MODE)));
	g->sprite[PRIGHT] = make_sprite(g->mlx, "asset/player_right.xpm");
	g->sprite[PLEFT] = make_sprite(g->mlx, "asset/player_left.xpm");
	g->sprite[PUP] = make_sprite(g->mlx, "asset/player_up.xpm");
	g->sprite[PDOWN] = make_sprite(g->mlx, "asset/player_down.xpm");
	g->sprite[AC_BONES] = make_sprite(g->mlx, "asset/acid2.xpm");
	g->sprite[AC_SMOKE] = make_sprite(g->mlx, "asset/water.xpm");
	g->sprite[AC_TROUBLE] = make_sprite(g->mlx, "asset/acid3.xpm");
	g->sprite[FLOOR] = make_sprite(g->mlx, "asset/test.xpm");
	g->sprite[EXIT_C] = make_sprite(g->mlx, "asset/exit.xpm");
	g->sprite[EXIT_O] = make_sprite(g->mlx, "asset/exit_open.xpm");
	g->sprite[COLLEC] = make_sprite(g->mlx, "asset/collectible.xpm");
	if (BONUS_MODE)
	{
		init_sprite_enemies(g);
		init_final(g);
	}
	return (0);
}
