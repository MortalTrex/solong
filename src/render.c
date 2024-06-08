/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalazs <rbalazs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 10:18:07 by rbalazs           #+#    #+#             */
/*   Updated: 2024/06/05 17:26:13 by rbalazs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/solong.h"

void	render_tiles(t_data *data)
{
	int		i;
	int		j;

	i = -1;
	while (++i < data->map.rows)
	{
		j = -1;
		while (++j < data->map.columns)
		{
			if (data->map.map[i][j] == '1')
				mlx_put_image_to_window(data->mlx.mlx_ptr, data->mlx.win_ptr,
					data->tiles.wall, TILE_SIZE * j, TILE_SIZE * i);
            if (data->map.map[i][j] == '0')
				mlx_put_image_to_window(data->mlx.mlx_ptr, data->mlx.win_ptr,
					data->tiles.floor, TILE_SIZE * j, TILE_SIZE * i);
			if (data->map.map[i][j] == 'C')
				mlx_put_image_to_window(data->mlx.mlx_ptr, data->mlx.win_ptr,
					data->tiles.collectible, TILE_SIZE * j, TILE_SIZE * i);
			if (data->map.map[i][j] == 'E')
				mlx_put_image_to_window(data->mlx.mlx_ptr, data->mlx.win_ptr,
					data->tiles.exit, TILE_SIZE * j, TILE_SIZE * i);
		}
	}
	put_player_tile(data);
}
