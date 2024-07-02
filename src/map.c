/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalazs <rbalazs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 18:23:55 by rbalazs           #+#    #+#             */
/*   Updated: 2024/07/02 19:20:25 by rbalazs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/solong.h"

// Copie src dans dest jusqu'à n caractères ou jusqu'à la fin de src
static char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (src[i] != '\0' && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	if (i < n && src[i] == '\0')
	{
		while (dest[i] != '\0')
			dest[i++] = '\0';
	}
	dest[i] = '\0';
	return (dest);
}

char	*trim_free(char *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*trimmed_str;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] != '\0' && ft_strchr(set, s1[start]) != NULL)
		start += 1;
	end = ft_strlen(s1 + start);
	while (end > start && ft_strchr(set, s1[(start + end) - 1]) != NULL)
		end -= 1;
	trimmed_str = malloc((end + 1) * sizeof(char));
	if (trimmed_str == NULL)
		return (NULL);
	ft_strncpy(trimmed_str, (s1 + start), end);
	free(s1);
	return (trimmed_str);
}

// Trouve le nombre de lignes nécessaires et l'attribue à data->map.rows
static void	get_rows(char *map_file, t_data *data)
{
	int		count;
	int		map_fd;
	char	*temp;

	count = 0;
	map_fd = open(map_file, O_RDONLY);
	if (map_fd == -1)
		ft_error(data, "Map file not found\n");
	temp = get_next_line(map_fd);
	while (temp)
	{
		count += 1;
		free(temp);
		temp = get_next_line(map_fd);
	}
	if (count == 0)
		ft_error(data, "Empty map\n");
	data->map.rows = count;
	close(map_fd);
}

static void	get_columns(char *map_file, t_data *data)
{
	int	map_fd;
	int	i;

	map_fd = open(map_file, O_RDONLY);
	if (map_fd == -1)
		ft_error(data, "Map file not found\n");
	i = 0;
	while (i < data->map.rows)
		data->map.map[i++] = get_next_line(map_fd);
	data->map.map[i] = NULL;
	close(map_fd);
	i = 0;
	while (i < (data->map.rows - 1))
	{
		data->map.map[i] = trim_free(data->map.map[i], "\n");
		i++;
	}
	data->map.columns = ft_strlen(data->map.map[0]);
	data->map.map[data->map.rows] = NULL;
}

void	init_map(char *map_file, t_data *data)
{
	get_rows(map_file, data);
	data->map.map = malloc((data->map.rows + 1) * sizeof(char *));
	if (data->map.map == NULL)
		ft_error(data, "Malloc Error\n");
	get_columns(map_file, data);
}