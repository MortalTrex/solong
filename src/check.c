#include "../include/solong.h"

static char	**copymap(t_data data)
{
	int		i;
	char	**copy;

	i = 0;
	printf("ROWS : %d\n", data.map.rows);
	copy = malloc((data.map.rows + 1) * sizeof(char *));
	if (!copy)
		ft_error(&data, "Malloc failed");
	while (data.map.map[i])
	{
		if (data.map.map[i] != NULL)
			copy[i] = ft_strdup(data.map.map[i]);
		i++;
	}
	copy[i] = NULL;
	printf("i : %d\n", i);
	return (copy);
}

static bool	floodfill(char **copy, t_map *map, t_point cur)
{
	static int	check_collectibles;
	static bool	exit;
	static bool	col;

	exit = false;
	col = false;
	if (cur.y < 0 || cur.y >= map->rows || cur.x < 0 || cur.x >= map->columns
		|| copy[cur.y][cur.x] == '1')
		return (false);
	check_collectibles = 0;
	if (copy[cur.y][cur.x] == '0')
		return (false);
	if (copy[cur.y][cur.x] == 'C')
		check_collectibles++;
	if (copy[cur.y][cur.x] == 'E')
		exit = true;
	if (check_collectibles == map->collectibles)
		col = true;
	copy[cur.y][cur.x] = '0';
	floodfill(copy, map, (t_point){cur.x - 1, cur.y});
	floodfill(copy, map, (t_point){cur.x + 1, cur.y});
	floodfill(copy, map, (t_point){cur.x, cur.y - 1});
	floodfill(copy, map, (t_point){cur.x, cur.y + 1});
	return (col && exit);
}

void	free_copy(char **copy, t_data *data)
{
	int	i;

	i = 0;
	if (!copy)
		return ;
	while (i < data->map.rows)
	{
		free(copy[i]);
		copy[i] = NULL;
		i++;
	}
	if (i > 0)
		free(copy);
	copy = NULL;
}

void	check(t_data data)
{
	char	**copy;

	copy = copymap(data);
	printf("Test case 1:\n");
	for (int i = 0; i < data.map.rows; i++)
	{
		for (int j = 0; j < data.map.columns; j++)
		{
			printf("%c", copy[i][j]);
		}
		printf("\n");
	}
	if (floodfill(copy, &data.map, data.player_pos) == false)
	{
		free_matrix(copy);
		ft_error(&data, "Map is not valid");
	}
	printf("Test case 2:\n");
	for (int i = 0; i < data.map.rows; i++)
	{
		for (int j = 0; j < data.map.columns; j++)
		{
			printf("%c", copy[i][j]);
		}
		printf("\n");
	}
	free_matrix(copy);
	exit(EXIT_SUCCESS);
}
