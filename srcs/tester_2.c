/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccadoret <ccadoret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 13:41:54 by ccadoret          #+#    #+#             */
/*   Updated: 2024/02/23 13:41:54 by ccadoret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccadoret <ccadoret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 13:41:49 by ccadoret          #+#    #+#             */
/*   Updated: 2024/02/23 13:41:49 by ccadoret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "../includes/so_long.h"
#include "../includes/get_next_line.h"

void	free_struct(t_map *map)
{
	int	i;

	i = -1;
	while (map->map[++i])
		free(map->map[i]);
	free(map->map);
}

int	check_char(t_map map)
{
	int	i;
	int	j;

	i = -1;
	while (map.map[++i])
	{
		j = -1;
		while (map.map[i][++j])
		{
			if (map.map[i][j] == 'M' && !BONUS_MODE)
				return (0);
			if (map.map[i][j] != 'M' && map.map[i][j] != 'E'
				&& map.map[i][j] != 'P' && map.map[i][j] != '0'
				&& map.map[i][j] != '1' && map.map[i][j] != 'C' && map.map)
				return (0);
		}
	}
	return (1);
}

int	find_p(t_map *map, int *x, int *y)
{
	int	i;
	int	j;

	i = -1;
	while (map->map[++i])
	{
		j = -1;
		while (map->map[i][++j] && map->map[i][j] != 'P')
			continue ;
		if (map->map[i][j] == 'P')
			break ;
	}
	*x = j;
	*y = i;
	return (0);
}
