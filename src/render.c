/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalazs <rbalazs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 10:18:07 by rbalazs           #+#    #+#             */
/*   Updated: 2024/05/27 12:40:00 by rbalazs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/solong.h"

static void	open_xpm(t_data *data)
{	
	int	img_size;

	img_size = TILE_SIZE;
    data->tiles.wall = mlx_xpm_file_to_image(data->mlx.mlx_ptr,
			WALL_TILE, &img_size, &img_size);
    data->tiles.floor = mlx_xpm_file_to_image(data->mlx.mlx_ptr,
			FLOOR_TILE, &img_size, &img_size);
    data->tiles.player = mlx_xpm_file_to_image(data->mlx.mlx_ptr,
			PLAYER_TILE, &img_size, &img_size);
    data->tiles.collectible = mlx_xpm_file_to_image(data->mlx.mlx_ptr,
			COLLECTIBLE_TILE, &img_size, &img_size);
    data->tiles.exit = mlx_xpm_file_to_image(data->mlx.mlx_ptr,
			EXIT_TILE, &img_size, &img_size);
}

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

void	render_map(t_data *data)
{
	open_xpm(data);
	render_tiles(data);
}

