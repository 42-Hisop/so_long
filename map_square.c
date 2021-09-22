#include "so_long.h"

int		check_exit(char **map)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'E')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

int		check_collect(t_info *info, char **map)
{
	int	i;
	int	j;

	info->collect = 0;
	info->collectcount = 0;
	info->movecount = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				info->collect++;
			j++;
		}
		i++;
	}
	return (info->collect);
}

int		check_map_w(char **map)
{
	int		count;
	int		i;
	int		j;

	count = 0;
	while (map[0][count])
		count++;
	i = 1;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
			j++;
		if (j != count)
			error("not square");
		i++;
	}
	return (count);
}

int			check_map_h(char **map)
{
	int	count;
	int	i;
	int	j;

	count = 0;
	while (map[count][0])
		count++;
	i = 1;
	j = 0;
	while (map[j][i])
	{
		while (map[j][i])
			j++;
		if (j != count)
			error("nor square");
		i++;
		j = 0;
	}
	return (count);
}

int		check_square(t_info *info, char **map, int i, int j)
{
	int	map_w;
	int	map_h;

	map_w = check_map_w(map);
	info->map_w = map_w;
	info->screen_w = map_w * 64;
	while (map[i])
		i++;
	map[i] = (char *)malloc(sizeof(char) * map_w);
	while (j < map_w)
	{
		map[i][j] = '\0';
		j++;
	}
	map[i + 1] = NULL;
	map_h = check_map_h(map);
	info->map_h = map_h;
	info->screen_h = map_h * 64;
	return (0);
}
