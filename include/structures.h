/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalazs <rbalazs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 21:28:46 by rbalazs           #+#    #+#             */
/*   Updated: 2024/05/27 09:06:12 by rbalazs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

#ifndef STRUCTURES_H
#   define STRUCTURES_H

typedef struct s_point {
	int	x;
	int	y;
}				t_point;

typedef struct s_map
{
    char **map;
	int    rows;
	int columns;
	int collectibles;
	int exit;
	int player;
    int moves;
	t_point			player_pos;
} t_map;

typedef struct s_tiles {
	void	*wall;
	void	*floor;
	void	*player;
	void	*collectible;
	void	*exit;
}				t_tiles;

typedef struct s_mlx {
    void		*mlx_ptr;
    void		*win_ptr;
}				t_mlx;

typedef struct s_data {
    t_mlx mlx;
    t_map map; 
    t_tiles tiles;
}				t_data;

static inline t_data	init_game(void)
{
	return ((t_data){
		.map.map = NULL,
		.map.rows = 0,
		.map.columns = 0,
		.map.collectibles = 0,
		.map.exit = 0,
		.map.player = 0,
		.tiles.collectible = NULL,
		.tiles.exit = NULL,
		.tiles.floor = NULL,
		.tiles.player = NULL,
		.tiles.wall = NULL,
		.map.moves = -1,
	});
}

#endif
