/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khee-seo <khee-seo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 18:25:14 by khee-seo          #+#    #+#             */
/*   Updated: 2021/09/23 19:39:45 by khee-seo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_tex(t_info *info, int i, int j, int n)
{
	mlx_put_image_to_window_scale(info->mlx, info->win,
		info->texture[n].image, 0, 0, 32, 32, j * 64, i * 64, 64, 64,
		0xFFFFFFFF);
}

void	read_map(t_info *info)
{
	int	i;
	int	j;

	i = 0;
	while (i <= info->map_h)
	{
		j = 0;
		while (j <= info->map_w)
		{
			if (info->map[i][j] == '1')
				put_tex(info, i, j, 0);
			if (info->map[i][j] == 'P')
				put_tex(info, i, j, 1);
			if (info->map[i][j] == 'C')
				put_tex(info, i, j, 2);
			if (info->map[i][j] == 'E')
				put_tex(info, i, j, 3);
			j++;
		}
		i++;
	}
}

void	put_base_color(t_info *info, int i, int j)
{
	while (i < info->screen_h)
	{
		j = 0;
		while (j < info->screen_w)
		{
			info->image_data[info->size_line / 4 * i + j] = 0xCCCCFF;
			j++;
		}
		i++;
	}
}

int	draw(t_info *info)
{
	info->image = mlx_new_image(info->mlx, info->screen_w, info->screen_h);
	info->image_data = (unsigned int *)mlx_get_data_addr(info->image,
			&info->bpp, &info->size_line, &info->endian);
	put_base_color(info, 0, 0);
	mlx_put_image_to_window(info->mlx, info->win, info->image, 0, 0);
	read_map(info);
	return (0);
}
