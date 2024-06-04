/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalazs <rbalazs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 21:51:50 by rbalazs           #+#    #+#             */
/*   Updated: 2024/05/27 09:32:15 by rbalazs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/solong.h"

static void ft_free_map(t_data *data)
{
    if (data->map.map != NULL)
    {
        free(data->map.map);
    }
}
static void ft_free_display(t_data *data)
{
    if (data->mlx.mlx_ptr != NULL)
    {
        mlx_destroy_window(data->mlx.mlx_ptr, data->mlx.win_ptr);
        mlx_destroy_display(data->mlx.mlx_ptr);
        free(data->mlx.mlx_ptr);
    }
    if (data->mlx.win_ptr != NULL)
    {
        mlx_destroy_window(data->mlx.mlx_ptr, data->mlx.win_ptr);
        free(data->mlx.win_ptr);
    }
}

void ft_free_all(t_data *data)
{
    ft_free_map(data);
    ft_free_display(data);
}
