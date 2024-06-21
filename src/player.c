/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalazs <rbalazs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 10:17:53 by rbalazs           #+#    #+#             */
/*   Updated: 2024/06/21 14:53:00 by rbalazs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/solong.h"

//Affiche le joueur sur la map et compte le nombre de mouvements
void	put_player_tile(t_data *data)
{
	char	*moves_str;

	data->map.moves += 1;
	ft_printf("Moves: %d\n", data->map.moves);
	mlx_put_image_to_window(data->mlx.mlx_ptr, data->mlx.win_ptr, data->tiles.player,
		TILE_SIZE * data->player_pos.x, TILE_SIZE * data->player_pos.y);
	mlx_put_image_to_window(data->mlx.mlx_ptr, data->mlx.win_ptr,
		data->tiles.wall, 0, 0);
	//Affiche le nombre de mouvements sur la fenêtre
	moves_str = ft_itoa(data->map.moves);
	mlx_string_put(data->mlx.mlx_ptr, data->mlx.win_ptr, 32, 10, 1, moves_str);
	free(moves_str);
}

static void	which_tile(t_data *data)
{
	//Si le joueur se trouve sur un collectible, en retire un
	if (data->map.map[data->player_pos.y][data->player_pos.x] == 'C')
	{
		data->map.map[data->player_pos.y][data->player_pos.x] = '0';
		data->map.collectibles += 1;
		return ;
	}
	//Si le joueur se trouve sur la sortie et qu'il n'y a plus de collectibles
	if (data->map.map[data->player_pos.y][data->player_pos.x] == 'E'
		&& data->map.collectibles == data->map.total_collectibles)
	{
		ft_printf("You won in %d moves!\n", data->map.moves + 1);
        exit_game(data);
	}
}


static void	update_left_behind_tile(t_data *data)
{
	//Si le joueur se trouve sur la sortie, on affiche la sortie
	if (data->map.map[data->player_pos.y]
		[data->player_pos.x] == 'E')
	{
		mlx_put_image_to_window(
			data->mlx.mlx_ptr, data->mlx.win_ptr, data->tiles.exit,
			TILE_SIZE * data->player_pos.x,
			TILE_SIZE * data->player_pos.y);
	}
	else
	//Sinon, on affiche le sol
		mlx_put_image_to_window(
			data->mlx.mlx_ptr, data -> mlx.win_ptr, data->tiles.floor,
			TILE_SIZE * data->player_pos.x,
			TILE_SIZE * data->player_pos.y);
}

void	update_player_pos(t_data *data, bool horizontal, int length)
{
	//Si le joueur est sur le bord de la map au niveau du x, on ne le déplace pas
	if (horizontal)
	{
		if (data->map.map[data->player_pos.y][data->player_pos.x + length] == '1' && data->player_pos.y > 0 && data->player_pos.x > 0 && data->player_pos.y < data->map.rows && data->player_pos.x < data->map.columns)
			return ;
		update_left_behind_tile(data);
		data->player_pos.x += length;
	}
	//Si le joueur est sur le bord de la map au niveau du y, on ne le déplace pas
	if (!horizontal)
	{
		if (data->map.map[data->player_pos.y + length][data->player_pos.x] == '1' && data->player_pos.y > 0 && data->player_pos.x > 0 && data->player_pos.y < data->map.rows && data->player_pos.x < data->map.columns)
			return ;
		update_left_behind_tile(data);
		data->player_pos.y += length;
	}
	//Vérifie si le joueur est sur un collectible ou la sortie
	which_tile(data);
	//Affiche le joueur sur la map
	put_player_tile(data);
}