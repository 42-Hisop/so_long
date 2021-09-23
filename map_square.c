/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_square.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khee-seo <khee-seo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 18:19:47 by khee-seo          #+#    #+#             */
/*   Updated: 2021/09/23 19:14:44 by khee-seo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map_w(char **map)
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

int	check_map_h(char **map)
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

int	check_square(t_info *info, char **map, int i, int j)
{
	int	map_w;
	int	map_h;

	map_w = check_map_w(map);
	info->map_w = map_w;
	info->screen_w = map_w * 64;
	while (map[i])
		i++;
	map[i] = (char *)malloc(sizeof(char) * map_w);
	if (!(map[i]))
		error("malloc error");
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
