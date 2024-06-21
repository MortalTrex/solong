/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalazs <rbalazs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 21:51:50 by rbalazs           #+#    #+#             */
/*   Updated: 2024/06/21 19:13:05 by rbalazs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/solong.h"

void    ft_error(t_data *data, char *str)
{
    write(2, "Error : ", 8);
    while (*str)
    {
        write(2, str, 1);
        str++;
    }
    write(2, "\n", 1);
    ft_free_all(data);
    exit(EXIT_FAILURE);
}
void	free_matrix(char **matrix)
{
	size_t	i;

	i = 0;
	if (!matrix)
		return ;
	while (matrix[i])
	{
		free(matrix[i]);
		matrix[i] = NULL;
		i++;
	}
	if (i > 0)
		free(matrix);
	matrix = NULL;
}

void	destroy_tiles(t_data *data)
{
	if (data->tiles.wall)
		mlx_destroy_image(data->mlx.mlx_ptr, data->tiles.wall);
	if (data->tiles.floor)
		mlx_destroy_image(data->mlx.mlx_ptr, data->tiles.floor);
	if (data->tiles.player)
		mlx_destroy_image(data->mlx.mlx_ptr, data->tiles.player);
	if (data->tiles.collectible)
		mlx_destroy_image(data->mlx.mlx_ptr, data->tiles.collectible);
	if (data->tiles.exit)
		mlx_destroy_image(data->mlx.mlx_ptr, data->tiles.exit);
}


void ft_free_all(t_data *data)
{
    if (!data)
        return ;
    destroy_tiles(data);
    if (data->mlx.win_ptr != NULL)
        mlx_destroy_window(data->mlx.mlx_ptr, data->mlx.win_ptr);
    if (data->mlx.mlx_ptr != NULL)
    {
        mlx_destroy_display(data->mlx.mlx_ptr);
        free(data->mlx.mlx_ptr);
    }
    if (data->map.map != NULL)
        free_matrix(data->map.map);
}
