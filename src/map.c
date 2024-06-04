/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalazs <rbalazs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 18:23:55 by rbalazs           #+#    #+#             */
/*   Updated: 2024/05/30 18:31:02 by rbalazs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/solong.h"

static char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (src[i] != '\0' && i < n)
	{
		dest[i] = src[i];
		i += 1;
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
	size_t	beg;
	size_t	end;
	char	*trimmed_str;

	if (!s1 || !set)
		return (NULL);
	beg = 0;
	while (s1[beg] != '\0' && ft_strchr(set, s1[beg]) != NULL)
		beg += 1;
	end = ft_strlen(s1 + beg);
	while (end > beg && ft_strchr(set, s1[(beg + end) - 1]) != NULL)
		end -= 1;
	trimmed_str = malloc((end + 1) * sizeof(char));
	if (trimmed_str == NULL)
		return (NULL);
	ft_strncpy(trimmed_str, (s1 + beg), end);
	free(s1);
	return (trimmed_str);
}

//Trouve le nombre de lignes nécessaires et l'attribue à data->map.rows
static void	get_nbr_rows(char *map_file, t_data *data)
{
	int		count;
	int		map_fd;
	char	*temp;

	count = 0;
	map_fd = open(map_file, O_RDONLY);
	temp = get_next_line(map_fd);
	while (temp)
	{
		count += 1;
		free(temp);
		temp = get_next_line(map_fd);
	}
	data->map.rows = count;
	close(map_fd);
}


static void	get_lines(char *map_file, t_data *data)
{
	int	map_fd;
	int	i;

	map_fd = open(map_file, O_RDONLY);
	i = 0;
	while (i < data->map.rows)
		data->map.map[i++] = get_next_line(map_fd);
	data->map.map[i] = NULL;
	close(map_fd);
	i = 0;
	while (i < (data->map.rows - 1))
	{
		data->map.map[i] = trim_free(data->map.map[i], "\n");
		i += 1;
	}
	data->map.columns = ft_strlen(data->map.map[0]);
}

void	get_map(char *map_file, t_data *data)
{
	get_nbr_rows(map_file, data);
	data->map.map = malloc((data->map.rows + 1) * sizeof(char *));
	get_lines(map_file, data);
}