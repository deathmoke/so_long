/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccadoret <ccadoret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 10:45:34 by ccadoret          #+#    #+#             */
/*   Updated: 2024/02/26 10:45:34 by ccadoret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H

# define SO_LONG_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <math.h>

# ifndef BONUS_MODE
#  define BONUS_MODE 0
# endif

# define KEY_ESCAPE 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_Z 122
# define KEY_Q 113
# define KEY_SPACE 32

# define HIMG 50
# define WIMG 50

# define NBTEX 11
# define NBTEX_BONUS 51

# define PRIGHT 0
# define PLEFT 1
# define PUP 2
# define PDOWN 3
# define AC_BONES 4
# define AC_SMOKE 5
# define AC_TROUBLE 6
# define FLOOR 7
# define EXIT_C 8
# define EXIT_O 9
# define COLLEC 10
# define EDOWN 11
# define EUP 12
# define ERIGHT 13
# define ELEFT 14
# define ESHOOTD 15
# define ESHOOTU 16
# define ESHOOTL 17
# define ESHOOTR 18
# define PSHOOTD 19
# define PSHOOTU 20
# define PSHOOTL 21
# define PSHOOTR 22
# define DEAD 23
# define NB 24
# define NBNUL 34
# define CC 35
# define CCNUL 45
# define ON 46
# define BLACK 47
# define LITTLE_WON 48
# define BIG_WON 49
# define LITTLE_GO 50
# define BIG_GO 51
# define SNB 52

# define DIR_DOWN 0
# define DIR_UP 1
# define DIR_RIGHT 2
# define DIR_LEFT 3

# define WON 1
# define LOSE 0

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}				t_data;

typedef struct s_map
{
	int		width;
	int		height;
	char	**map;
}				t_map;

typedef struct s_character
{
	int		x;
	int		y;
	t_data	skin;
}				t_character;

typedef struct s_sprite
{
	void	*ptr;
	int		width;
	int		height;
}				t_sprite;

typedef struct s_enemies
{
	int	x;
	int	y;
	int	dir;
	int	etat;
}				t_enemies;

typedef struct s_game
{
	void		*mlx;
	void		*mlx_win;
	t_map		map;
	t_character	hero;
	int			nbcol;
	int			nbcol_var;
	int			__nbcol__;
	int			nb_enemies;
	int			compt;
	t_sprite	*sprite;
	t_enemies	*enemies;
	int			start;
}				t_game;

int			right(t_game *g);
int			left(t_game *g);
int			up(t_game *g);
int			down(t_game *g);
void		move(int keycode, t_game *game);
int			keypress(int keycode, t_game *game);
int			open_exit(t_game *game);
void		ft_putnbr(int nb);
void		ft_putchar(char c);
int			close_game(t_game *game);
void		free_struct(t_map *map);
int			check(t_map map);
int			print_game(t_game *game);
int			init_sprite(t_game *g);
void		right_utilis(t_game *g, int x, int y);
void		left_utilis(t_game *g, int x, int y);
void		up_utilis(t_game *g, int x, int y);
void		down_utilis(t_game *g, int x, int y);
int			enemies_map(t_game *g);
int			contact(t_game *g, int x, int y);
int			move_enemies(t_game *g, int m);
void		right_utilis_enemy(t_game *g, int x, int y, int m);
void		left_utilis_enemy(t_game *g, int x, int y, int m);
void		up_utilis_enemy(t_game *g, int x, int y, int m);
void		down_utilis_enemy(t_game *g, int x, int y, int m);
int			detect_player(t_game *g, int m);
int			attack(t_game *g);
char		*ft_itoa(int n);
int			putcount(t_game *g);
int			putcount_col(t_game *g);
int			putnbr_screen(t_game *g, int x, int y, int nbr);
int			putnbr_screen_small(t_game *g, int x, int y, int nbr);
int			game_over(t_game *g);
int			victory(t_game *g);
int			check_char(t_map map);
t_sprite	mk_st(void *mlx, char *path, int x, int y);
int			find_p(t_map *map, int *x, int *y);

#endif