/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalazs <rbalazs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 10:17:53 by rbalazs           #+#    #+#             */
/*   Updated: 2024/06/08 16:09:03 by rbalazs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/solong.h"

//Affiche le joueur sur la map et compte le nombre de mouvements
void	put_player_tile(t_data *data)
{
	char	*moves_str;

	data->map.moves += 1;
	mlx_put_image_to_window(data->mlx.mlx_ptr, data->mlx.win_ptr, data->tiles.player,
		TILE_SIZE * data->map.player_pos.x, TILE_SIZE * data->map.player_pos.y);
	mlx_put_image_to_window(data->mlx.mlx_ptr, data->mlx.win_ptr,
		data->tiles.wall, 0, 0);
	//Affiche le nombre de mouvements sur la fenêtre
	moves_str = ft_itoa(data->map.moves);
	if (moves_str == NULL)
		ft_error(data, "Memory Error (moves)\n");
	mlx_string_put(data->mlx.mlx_ptr, data->mlx.win_ptr, 32, 10, 1, moves_str);
	free(moves_str);
}

static void	which_tile(t_data *data)
{
	//Si le joueur se trouve sur un collectible, en retire un
	if (data->map.map[data->map.player_pos.y][data->map.player_pos.x] == 'C')
	{
		data->map.map[data->map.player_pos.y][data->map.player_pos.x] = 0;
		data->map.collectibles -= 1;
		return ;
	}
	//Si le joueur se trouve sur la sortie et qu'il n'y a plus de collectibles
	if (data->map.map[data->map.player_pos.y][data->map.player_pos.x] == 'E' 
		&& data->map.collectibles == 0)
	{
		ft_printf("You won in %d moves!\n", data->map.moves);
        exit_game(data);
	}
}


static void	update_left_behind_tile(t_data *data)
{
	//Si le joueur se trouve sur la sortie, on affiche la sortie
	if (data->map.map[data->map.player_pos.y]
		[data->map.player_pos.x] == 'E')
	{
		mlx_put_image_to_window(
			data->mlx.mlx_ptr, data->mlx.win_ptr, data->tiles.exit,
			TILE_SIZE * data->map.player_pos.x,
			TILE_SIZE * data->map.player_pos.y);
	}
	else
	//Sinon, on affiche le sol
		mlx_put_image_to_window(
			data->mlx.mlx_ptr, data -> mlx.win_ptr, data->tiles.floor,
			TILE_SIZE * data->map.player_pos.x,
			TILE_SIZE * data->map.player_pos.y);
}

void	update_player_pos(t_data *data, bool horizontal, int length)
{
	//Si le joueur est sur le bord de la map au niveau du x, on ne le déplace pas
	if (horizontal)
	{
		if (data->map.map[data->map.player_pos.y]
			[data->map.player_pos.x + length] == 1)
			return ;
		update_left_behind_tile(data);
		data->map.player_pos.x += length;
	}
	else
	//Si le joueur est sur le bord de la map au niveau du y, on ne le déplace pas
	{
		if (data->map.map[data->map.player_pos.y + length]
			[data->map.player_pos.x] == 1)
			return ;
		update_left_behind_tile(data);
		data->map.player_pos.y += length;
	}
	//Vérifie si le joueur est sur un collectible ou la sortie
	which_tile(data);
	//Affiche le joueur sur la map
	put_player_tile(data);
}