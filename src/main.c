/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalazs <rbalazs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 21:34:12 by rbalazs           #+#    #+#             */
/*   Updated: 2024/06/26 15:19:59 by rbalazs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/solong.h"

static void	open_xpm(t_data *data)
{
	int	img_size;

	img_size = SQUARE_SIZE;
	data->square.wall = mlx_xpm_file_to_image(data->mlx.mlx_ptr, WALL,
			&img_size, &img_size);
	data->square.floor = mlx_xpm_file_to_image(data->mlx.mlx_ptr, FLOOR,
			&img_size, &img_size);
	data->square.player = mlx_xpm_file_to_image(data->mlx.mlx_ptr, PLAYER,
			&img_size, &img_size);
	data->square.collectible = mlx_xpm_file_to_image(data->mlx.mlx_ptr,
			COLLECTIBLE, &img_size, &img_size);
	data->square.exit = mlx_xpm_file_to_image(data->mlx.mlx_ptr, EXIT,
			&img_size, &img_size);
}

void put_textures(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (++i < data->map.rows)
	{
		j = -1;
		while (++j < data->map.columns)
		{
			if (data->map.map[i][j] == '1')
				mlx_put_image_to_window(data->mlx.mlx_ptr, data->mlx.win_ptr,
					data->square.wall, SQUARE_SIZE * j, SQUARE_SIZE * i);
			if (data->map.map[i][j] == '0')
				mlx_put_image_to_window(data->mlx.mlx_ptr, data->mlx.win_ptr,
					data->square.floor, SQUARE_SIZE * j, SQUARE_SIZE * i);
			if (data->map.map[i][j] == 'C')
			{
				mlx_put_image_to_window(data->mlx.mlx_ptr, data->mlx.win_ptr,
					data->square.collectible, SQUARE_SIZE * j, SQUARE_SIZE * i);
			}
			if (data->map.map[i][j] == 'E')
				mlx_put_image_to_window(data->mlx.mlx_ptr, data->mlx.win_ptr,
					data->square.exit, SQUARE_SIZE * j, SQUARE_SIZE * i);
			if (data->map.map[i][j] == 'P')
			{
				mlx_put_image_to_window(data->mlx.mlx_ptr, data->mlx.win_ptr,
					data->square.player, SQUARE_SIZE * j, SQUARE_SIZE * i);
				data->player_pos.x = j;
				data->player_pos.y = i;
			}
		}
	}
}

int	exit_game(t_data *data)
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
	data->mlx.win_ptr = mlx_new_window(data->mlx.mlx_ptr, data->map.columns
			* SQUARE_SIZE, data->map.rows * SQUARE_SIZE, "so_long");
	if (!data->mlx.win_ptr)
		ft_error(data, "MLX Window Error\n");
}

int	ft_commands(int key, t_data *data)
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

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		ft_error(&data, "Wrong number of arguments\n");
	if (*argv[1] == '\0')
		ft_error(&data, "Empty argument\n");
	bzero(&data, sizeof(t_data));
	init_map(argv[1], &data);
	check(&data);
	init_mlx(&data);
	open_xpm(&data);
	put_textures(&data);
	mlx_hook(data.mlx.win_ptr, KEYPRESS, KeyPressMask, ft_commands, &data);
	mlx_hook(data.mlx.win_ptr, DESTROY_NOTIFY, StructureNotifyMask, exit_game, &data);
	mlx_loop(data.mlx.mlx_ptr);
	return (EXIT_SUCCESS);
}
