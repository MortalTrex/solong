/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalazs <rbalazs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 10:17:53 by rbalazs           #+#    #+#             */
/*   Updated: 2024/05/30 17:39:19 by rbalazs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/solong.h"

void	put_player_tile(t_data *data)
{
	char	*moves_str;

	data->map.moves += 1;
	mlx_put_image_to_window(data->mlx.mlx_ptr, data->mlx.win_ptr, data->tiles.player,
		TILE_SIZE * data->player_pos.x, TILE_SIZE * data->player_pos.y);
	mlx_put_image_to_window(data->mlx.mlx_ptr, data->mlx.win_ptr,
		data->tiles.wall, 0, 0);
	moves_str = ft_itoa(data->map.moves);
	mlx_string_put(data->mlx.mlx_ptr, data->mlx.win_ptr, 32, 10, 1, moves_str);
	free(moves_str);
}

static void	which_tile(t_data *data)
{
	if (data->map.map[data->player_pos.y]
		[data->player_pos.x] == 'C')
	{
		data->map.map[data->player_pos.y]
		[data->player_pos.x] = 0;
		data->map.collectibles -= 1;
		return ;
	}
	if (data->map.map[data->player_pos.y][data->player_pos.x] == 'E'
		&& data->map.collectibles == 0)
	{
		ft_printf("You won in %d moves!\n", data->map.moves);
        exit(0);
	}
}

/* Overloads the player tile that is left behind when the player moves */
static void	update_left_behind_tile(t_data *data)
{
	if (data->map.map[data->player_pos.y]
		[data->player_pos.x] == 'E')
	{
		mlx_put_image_to_window(
			data->mlx.mlx_ptr, data->mlx.win_ptr, data->tiles.exit,
			TILE_SIZE * data->player_pos.x,
			TILE_SIZE * data->player_pos.y);
	}
	else
		mlx_put_image_to_window(
			data->mlx.mlx_ptr, data -> mlx.win_ptr, data->tiles.floor,
			TILE_SIZE * data->player_pos.x,
			TILE_SIZE * data->player_pos.y);
}

void	update_player_pos(t_data *data, bool horizontal, int length)
{
	if (horizontal)
	{
		if (data->map.map[data->player_pos.y]
			[data->player_pos.x + length] == 1)
			return ;
		update_left_behind_tile(data);
		data->player_pos.x += length;
	}
	else
	{
		if (data->map.map[data->player_pos.y + length]
			[data->player_pos.x] == 1)
			return ;
		update_left_behind_tile(data);
		data->player_pos.y += length;
	}
	which_tile(data);
	put_player_tile(data);
}