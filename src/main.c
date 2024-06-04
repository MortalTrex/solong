/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalazs <rbalazs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 21:34:12 by rbalazs           #+#    #+#             */
/*   Updated: 2024/05/30 18:34:32 by rbalazs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/solong.h"

int exit_game(t_data *data)
{
	ft_free_all(data);
	exit(0);
	return (0);
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
	else if (key == A || key == LEFT)
		update_player_pos(data, true, -1);
	else if (key == S || key == DOWN)
		update_player_pos(data, false, 1);
	else if (key == D || key == RIGHT)
		update_player_pos(data, true, 1);
	return (EXIT_SUCCESS);
}

int main(int argc, char **argv)
{
	t_data data;
	
	if (argc != 2)
	{
		printf("Error: Invalid number of arguments\n");
		return (EXIT_FAILURE);
	}
	ft_init(&data);
	get_map(argv[1], &data);
	init_mlx(&data);
	render_map(&data);
	mlx_hook(data.mlx.win_ptr, KeyRelease, KeyReleaseMask, &ft_commands, &data.mlx);
	mlx_hook(data.mlx.win_ptr, DestroyNotify, StructureNotifyMask, &exit_game, &data.mlx);
	mlx_loop(data.mlx.mlx_ptr);
	return (EXIT_SUCCESS);
}