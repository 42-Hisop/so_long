/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khee-seo <khee-seo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 18:27:43 by khee-seo          #+#    #+#             */
/*   Updated: 2021/09/23 20:07:21 by khee-seo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_forward(t_info *info, char **map)
{	
	if (map[info->player_y - 1][info->player_x] == '1')
		return ;
	if (map[info->player_y - 1][info->player_x] == 'E'
			&& info->collect != info->collectcount)
		return ;
	info->movecount++;
	printf("%d\n", info->movecount);
	if (map[info->player_y - 1][info->player_x] == 'C')
		info->collectcount++;
	if (map[info->player_y - 1][info->player_x] == 'E'
			&& info->collect == info->collectcount)
	{
		write(1, "you win", 7);
		exit(0);
	}
	map[info->player_y - 1][info->player_x] = 'P';
	map[info->player_y][info->player_x] = '0';
	info->player_y--;
}

void	move_backward(t_info *info, char **map)
{
	if (map[info->player_y + 1][info->player_x] == '1')
		return ;
	if (map[info->player_y + 1][info->player_x] == 'E'
			&& info->collect != info->collectcount)
		return ;
	info->movecount++;
	printf("%d\n", info->movecount);
	if (map[info->player_y + 1][info->player_x] == 'C')
		info->collectcount++;
	if (map[info->player_y + 1][info->player_x] == 'E'
			&& info->collect == info->collectcount)
	{
		write(1, "you win", 7);
		exit(0);
	}
	map[info->player_y + 1][info->player_x] = 'P';
	map[info->player_y][info->player_x] = '0';
	info->player_y++;
}

void	move_left(t_info *info, char **map)
{
	if (map[info->player_y][info->player_x - 1] == '1')
		return ;
	if (map[info->player_y][info->player_x - 1] == 'E'
			&& info->collect != info->collectcount)
		return ;
	info->movecount++;
	printf("%d\n", info->movecount);
	if (map[info->player_y][info->player_x - 1] == 'C')
		info->collectcount++;
	if (map[info->player_y][info->player_x - 1] == 'E'
			&& info->collect == info->collectcount)
	{
		write(1, "you win", 7);
		exit(0);
	}
	map[info->player_y][info->player_x - 1] = 'P';
	map[info->player_y][info->player_x] = '0';
	info->player_x--;
}

void	move_right(t_info *info, char **map)
{
	if (map[info->player_y][info->player_x + 1] == '1')
		return ;
	if (map[info->player_y][info->player_x + 1] == 'E'
			&& info->collect != info->collectcount)
		return ;
	info->movecount++;
	printf("%d\n", info->movecount);
	if (map[info->player_y][info->player_x + 1] == 'C')
		info->collectcount++;
	if (map[info->player_y][info->player_x + 1] == 'E'
			&& info->collect == info->collectcount)
	{
		write(1, "you win", 7);
		exit(0);
	}
	map[info->player_y][info->player_x + 1] = 'P';
	map[info->player_y][info->player_x] = '0';
	info->player_x++;
}

int	key_press(int key, t_info *info)
{
	if (key == 13)
		move_forward(info, info->map);
	if (key == 1)
		move_backward(info, info->map);
	if (key == 0)
		move_left(info, info->map);
	if (key == 2)
		move_right(info, info->map);
	if (key == 53)
		exit(0);
	return (0);
}
