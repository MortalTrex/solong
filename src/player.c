/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalazs <rbalazs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 10:17:53 by rbalazs           #+#    #+#             */
/*   Updated: 2024/07/02 19:22:55 by rbalazs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/solong.h"

// Affiche le joueur sur la map et compte le nombre de mouvements
void	put_player_tile(t_data *data)
{
	char	*moves;

	data->map.moves++;
	mlx_put_image_to_window(data->mlx.mlx_ptr, data->mlx.win_ptr,
		data->square.player, SQUARE_SIZE * data->player_pos.x, SQUARE_SIZE
		* data->player_pos.y);
	mlx_put_image_to_window(data->mlx.mlx_ptr, data->mlx.win_ptr,
		data->square.wall, 0, 0);
	moves = ft_itoa(data->map.moves);
	mlx_string_put(data->mlx.mlx_ptr, data->mlx.win_ptr, 32, 10, 1, moves);
	free(moves);
}

static void	collect_check(t_data *data)
{
	// Si le joueur se trouve sur un collectible, en retire un
	if (data->map.map[data->player_pos.y][data->player_pos.x] == 'C')
	{
		data->map.collectibles--;
		data->map.map[data->player_pos.y][data->player_pos.x] = '0';
		return ;
	}
	// Si le joueur se trouve sur la sortie et qu'il n'y a plus de collectibles
	if (data->map.map[data->player_pos.y][data->player_pos.x] == 'E'
		&& data->map.collectibles == 0)
	{
		ft_printf("You won in %d moves!\n", data->map.moves + 1);
		exit_game(data);
	}
}

static void	update_behind(t_data *data)
{
	if (data->map.map[data->player_pos.y][data->player_pos.x] == 'E')
	{
		mlx_put_image_to_window(data->mlx.mlx_ptr, data->mlx.win_ptr,
			data->square.exit, SQUARE_SIZE * data->player_pos.x, SQUARE_SIZE
			* data->player_pos.y);
	}
	else
		mlx_put_image_to_window(data->mlx.mlx_ptr, data->mlx.win_ptr,
			data->square.floor, SQUARE_SIZE * data->player_pos.x, SQUARE_SIZE
			* data->player_pos.y);
}

void	update_player_pos(t_data *data, bool horizontal, int length)
{
	if (horizontal)
	{
		if (data->map.map[data->player_pos.y][data->player_pos.x
			+ length] == '1' && data->player_pos.y > 0 && data->player_pos.x > 0
			&& data->player_pos.y < data->map.rows
			&& data->player_pos.x < data->map.columns)
			return ;
		update_behind(data);
		data->player_pos.x += length;
	}
	if (!horizontal)
	{
		if (data->map.map[data->player_pos.y
			+ length][data->player_pos.x] == '1' && data->player_pos.y > 0
			&& data->player_pos.x > 0 && data->player_pos.y < data->map.rows
			&& data->player_pos.x < data->map.columns)
			return ;
		update_behind(data);
		data->player_pos.y += length;
	}
	collect_check(data);
	put_player_tile(data);
}