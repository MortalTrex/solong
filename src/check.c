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

// static bool	flood_fill(char **copy, t_map *map, t_point cur)
// {
// 	static int	check_collectibles;
// 	static bool	exit;
// 	static bool	col;

// 	exit = false;
// 	col = false;
	
// 	check_collectibles = 0;
// 	if (copy[cur.y][cur.x] == '1')
// 		return (false);
// 	if (copy[cur.y][cur.x] == 'C')
// 		check_collectibles++;
// 	if (copy[cur.y][cur.x] == 'E')
// 		exit = true;
// 	if (check_collectibles == map->collectibles)
// 		col = true;
// 	copy[cur.y][cur.x] = '1';
// 	flood_fill(copy, map, (t_point){cur.x + 1, cur.y});
// 	flood_fill(copy, map, (t_point){cur.x - 1, cur.y});
// 	flood_fill(copy, map, (t_point){cur.x, cur.y + 1});
// 	flood_fill(copy, map, (t_point){cur.x, cur.y - 1});
// 	return (col && exit);
// }

static bool	flood_fill(t_map *map, t_point curr, char **sol_grid)
{
	static int		coins = 0;
	static bool		found_exit = false;

	if (sol_grid[curr.y][curr.x] == '1')
		return (false);
	else if (sol_grid[curr.y][curr.x] == 'C')
		coins += 1;
	else if (sol_grid[curr.y][curr.x] == 'E')
		found_exit = true;
	sol_grid[curr.y][curr.x] = '1';
	flood_fill(map, (t_point){curr.x + 1, curr.y}, sol_grid);
	flood_fill(map, (t_point){curr.x - 1, curr.y}, sol_grid);
	flood_fill(map, (t_point){curr.x, curr.y + 1}, sol_grid);
	flood_fill(map, (t_point){curr.x, curr.y - 1}, sol_grid);
	return (coins == map->collectibles && found_exit);
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
	copy = copymap(data);
	if (!flood_fill(&data->map, data->player_pos, copy))
	{
		free_matrix(copy);
		ft_error(data, "Map is not valid");
	}
	free_matrix(copy);
}
