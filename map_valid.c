/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_valid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khee-seo <khee-seo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 18:29:36 by khee-seo          #+#    #+#             */
/*   Updated: 2021/09/23 20:00:02 by khee-seo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	validinwall(char c)
{
	if (c == '0' || c == 'C' || c == 'E' || c == 'P')
		return (1);
	return (0);
}

int	wallcheck_w(char **map)
{
	int	i;
	int	j;
	int	flag;

	i = 0;
	while (map[i])
	{
		flag = 0;
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '1' && flag == 0)
				flag = 1;
			if (validinwall(map[i][j]) && flag == 0)
				return (1);
			if (validinwall(map[i][j]) && map[i][j + 1] == '\0')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	wallcheck_h(char **map)
{
	int		i;
	int		j;
	int		flag;

	i = 0;
	j = 0;
	while (map[j][i])
	{
		flag = 0;
		while (map[j])
		{
			if (map[j][i] == '1' && flag == 0)
				flag = 1;
			if (validinwall(map[j][i]) && flag == 0)
				return (1);
			if (validinwall(map[j][i]) && map[j + 1][i] == '\0')
				return (1);
			j++;
		}
		i++;
		j = 0;
	}
	return (0);
}

int	validcheck(t_info *info, char **map)
{
	int		i;
	int		j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				info->player_x = j;
				info->player_y = i;
			}
			if (!(map[i][j] == '0' || map[i][j] == '1' || map[i][j] == 'C'
				|| map[i][j] == 'E' || map[i][j] == 'P'))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	map_valid(char **map, t_info *info)
{
	check_square(info, map, 0, 0);
	if (validcheck(info, map))
		error("map error_unvalid");
	if (wallcheck_w(map))
		error("map error_w");
	if (wallcheck_h(map))
		error("map error_h");
	if (check_collect(info, map) == 0)
		error("collect count zero");
	if (check_exit(map) == 0)
		error("exit count zero");
	if (check_player(map) != 1)
		error("player not 1");
}
