/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mortaltrex <mortaltrex@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 21:27:30 by rbalazs           #+#    #+#             */
/*   Updated: 2024/06/24 01:40:48 by mortaltrex       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

///////////////////////////////////////////DEFINE///////////////////////////////////////////

//TEXTURES
# define WALL "./textures/wall.xpm"
# define FLOOR "./textures/floor.xpm"
# define PLAYER "./textures/player.xpm"
# define COLLECTIBLE "./textures/coin.xpm"
# define EXIT "./textures/exit.xpm"
# define SQUARE_SIZE 64

//KEYS
# define W 119
# define A 97
# define S 115
# define D 100
# define UP 65362
# define LEFT 65361
# define DOWN 65364
# define RIGHT 65363
# define ESC 65307

# define KEYPRESS 2
# define DESTROY_NOTIFY 17

///////////////////////////////////////////INCLUDE///////////////////////////////////////////

# include "../lib/mlx/mlx.h"
# include "../lib/libft/libft.h"
# include "../lib/gnl/get_next_line.h"
# include "../lib/ft_printf/ft_printf.h"
# include "./structures.h"

# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <stdlib.h>
# include <time.h>
# include <stdio.h>

///////////////////////////////////////////PROTOTYPES///////////////////////////////////////////

//INIT
void    ft_init(t_data *data);
 
//FREE
void ft_free_all(t_data *data);
int exit_game(t_data *data);
void	free_matrix(char **matrix);

//ERROR
void    ft_error(t_data *data, char *str);

//RENDER
void    render_tiles(t_data *data);
void    render_map(t_data *data);

//PLAYER
void    update_player_pos(t_data *data, bool horizontal, int length);
void    put_player_tile(t_data *data);
void	init_map(char *map_file, t_data *data);

//CHECK
void check(t_data data);

#endif