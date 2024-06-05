/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalazs <rbalazs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 21:46:39 by rbalazs           #+#    #+#             */
/*   Updated: 2024/05/27 09:07:35 by rbalazs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/solong.h"

static void ft_init_point(t_data *data)
{
    data->player_pos.x = 0;
    data->player_pos.y = 0;
}
static void ft_init_map(t_data *data)
{
    data->map.map = NULL;
    data->map.rows = 0;
    data->map.columns = 0;
    data->map.collectibles = 0;
    data->map.exit = 0;
    data->map.player = 0;
    data->map.moves = -1;
}

static void ft_init_display(t_data *data)
{
    data->mlx.mlx_ptr = NULL;
    data->mlx.win_ptr = NULL;
}

static void ft_init_tiles(t_data *data)
{
    data->tiles.wall = NULL;
    data->tiles.floor = NULL;
    data->tiles.player = NULL;
    data->tiles.collectible = NULL;
    data->tiles.exit = NULL;
}

void    ft_init(t_data *data)
{
    ft_init_point(data);
    ft_init_map(data);
    ft_init_display(data);
    ft_init_tiles(data);
}
