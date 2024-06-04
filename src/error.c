/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalazs <rbalazs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 22:00:10 by rbalazs           #+#    #+#             */
/*   Updated: 2024/05/15 22:06:28 by rbalazs          ###   ########.fr       */
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
