#include "../include/solong.h"

static char	**copymap(t_data *data)
{
	int		i;
	char	**copy;

	i = 0;
	copy = malloc((data->map.rows + 1) * sizeof(char *));
	if (!copy)
		ft_error(data, "Malloc failed");
	while (data->map.map[i])
	{
		if (data->map.map[i] != NULL)
			copy[i] = ft_strdup(data->map.map[i]);
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

static bool	flood_fill(char **copy, t_map *map, t_point cur)
{
	static int	check_collectibles = 0;
	static bool	exit = false;

	if (cur.x < 0 || cur.y < 0 || cur.x >= map->columns || cur.y >= map->rows)
		return (false);
	if (copy[cur.y][cur.x] == '1')
		return (false);
	if (copy[cur.y][cur.x] == 'C')
		check_collectibles++;
	if (copy[cur.y][cur.x] == 'E')
		exit = true;
	copy[cur.y][cur.x] = '1';
	flood_fill(copy, map, (t_point){cur.x + 1, cur.y});
	flood_fill(copy, map, (t_point){cur.x - 1, cur.y});
	flood_fill(copy, map, (t_point){cur.x, cur.y + 1});
	flood_fill(copy, map, (t_point){cur.x, cur.y - 1});
	return (check_collectibles == map->collectibles && exit);
}
static void check_wall(t_data *data)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (data->map.map[i])
	{
		if (data->map.map[i][0] != '1' || data->map.map[i][data->map.columns - 1] != '1')
			ft_error(data, "Walls are not valid");
		j = 0;
		if (i == 0 || i == data->map.rows - 1)
		{
			while (data->map.map[i][j])
			{
				if (data->map.map[i][j] != '1')
					ft_error(data, "Walls are not valid");
				j++;
			}
		}
		i++;
	}
	if (data->map.map[0][0] != '1')
		ft_error(data, "Map is not valid");
}
static void check_lenwall(t_data *data)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (data->map.map[i])
	{
		if (ft_strlen(data->map.map[i]) != data->map.columns)
			ft_error(data, "Map is not valid");
		i++;
	}
}


static void	count_elements(t_data *data)
{
	int	i;
	int j;

	i = 0;
	while (i < data->map.rows)
	{
		j = 0;
		while (j < data->map.columns)
		{
			if (data->map.map[i][j] == 'C')
				data->map.collectibles++;
			if (data->map.map[i][j] == 'P')
			{
				data->player_pos.x = j;
				data->player_pos.y = i;
				data->map.player++;
			}
			if (data->map.map[i][j] == 'E')
				data->map.exit++;	
			j++;
		}
		i++;
	}
}

void	check(t_data *data)
{
	char	**copy;
	count_elements(data);
	check_wall(data);
	check_lenwall(data);
	if (data->map.player != 1 || data->map.exit != 1 || data->map.collectibles == 0)
		ft_error(data, "Incorrect number of elements of exit, player or collectibles"); 
	copy = copymap(data);
	if (!flood_fill(copy, &data->map, data->player_pos))
	{
		free_matrix(copy);
		ft_error(data, "Map is not valid");
	}
	free_matrix(copy);
}
