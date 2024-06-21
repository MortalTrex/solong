/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalazs <rbalazs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 21:34:12 by rbalazs           #+#    #+#             */
/*   Updated: 2024/06/21 18:25:19 by rbalazs          ###   ########.fr       */
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
			{
				data->map.total_collectibles += 1;
				mlx_put_image_to_window(data->mlx.mlx_ptr, data->mlx.win_ptr,
					data->tiles.collectible, TILE_SIZE * j, TILE_SIZE * i);
			}
			if (data->map.map[i][j] == 'E')
				mlx_put_image_to_window(data->mlx.mlx_ptr, data->mlx.win_ptr,
					data->tiles.exit, TILE_SIZE * j, TILE_SIZE * i);
			if (data->map.map[i][j] == 'P')
			{
				mlx_put_image_to_window(data->mlx.mlx_ptr, data->mlx.win_ptr,
					data->tiles.player, TILE_SIZE * j, TILE_SIZE * i);
				data->player_pos.x = j;
				data->player_pos.y = i;
			}
		}
	}
	//put_player_tile(data);
}

int exit_game(t_data *data)
{
	ft_free_all(data);
	exit(EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}

void	init_mlx(t_data *data)
{
	data->mlx.mlx_ptr = mlx_init();
	if (!data->mlx.mlx_ptr)
		ft_error(data, "MLX Init Error\n");
	data->mlx.win_ptr = mlx_new_window(data->mlx.mlx_ptr,
			data->map.columns * TILE_SIZE, data->map.rows * TILE_SIZE,
			"so_long");
	if (!data->mlx.win_ptr)
		ft_error(data, "MLX Window Error\n");
}

int ft_commands(int key, t_data *data)
{
	if (key == ESC)
		exit_game(data);
	else if (key == W || key == UP)
		update_player_pos(data, false, -1);
	else if (key == S || key == DOWN)
		update_player_pos(data, false, 1);
	else if (key == A || key == LEFT)
		update_player_pos(data, true, -1);
	else if (key == D || key == RIGHT)
		update_player_pos(data, true, 1);
	return (EXIT_SUCCESS);
}


int main(int argc, char **argv)
{
	t_data data;
	
	if (argc != 2)
		ft_error(&data, "Wrong number of arguments\n");
	if (*argv[1] == '\0')
		ft_error(&data, "Empty argument\n");
	
	//Initialisation de tout à NULL
	//ft_init(&data);
	bzero(&data, sizeof(t_data));
	
	//Récupération des infos la map en colonnes et lignes
	init_map(argv[1], &data);

	//CheckerDiego
	check(data);
	
	//Initialisation de la fenêtre
	init_mlx(&data);

	//Chargement des textures
	open_xpm(&data);

	//Affichage de la map
	render_tiles(&data);

	//Gestion des événements
	mlx_hook(data.mlx.win_ptr, KEYPRESS_EVENT, (1L << 0), ft_commands, &data);
	mlx_hook(data.mlx.win_ptr, DESTROY_NOTIFY_EVENT, (1L << 17), exit_game, &data);
	mlx_loop(data.mlx.mlx_ptr);

	return (EXIT_SUCCESS);
}
