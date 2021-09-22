#include "so_long.h"

int		destroy_notify(t_info *info)
{
	exit(0);
	return(0);
}

void	tex_init(t_info *info, t_texture *tex, int i)
{
	tex[0].image = mlx_xpm_file_to_image(info->mlx, "image/wall.xpm",
			&tex[0].width, &tex[0].height);
	tex[0].image_data = (unsigned int *)mlx_get_data_addr(tex[0].image,
			&tex[0].bpp, &tex[0].size_line, &tex[0].endian);
	tex[1].image = mlx_xpm_file_to_image(info->mlx, "image/player.xpm",
			&tex[1].width, &tex[1].height);
	tex[1].image_data = (unsigned int *)mlx_get_data_addr(tex[1].image,
			&tex[1].bpp, &tex[1].size_line, &tex[1].endian);
	tex[2].image = mlx_xpm_file_to_image(info->mlx, "image/collectible.xpm",
			&tex[2].width, &tex[2].height);
	tex[2].image_data = (unsigned int *)mlx_get_data_addr(tex[2].image,
			&tex[2].bpp, &tex[2].size_line, &tex[2].endian);
	tex[3].image = mlx_xpm_file_to_image(info->mlx, "image/exit.xpm",
			&tex[3].width, &tex[3].height);
	tex[3].image_data = (unsigned int *)mlx_get_data_addr(tex[3].image,
			&tex[3].bpp, &tex[3].size_line, &tex[3].endian);
	while (i < 4 && (tex[i].width && tex[i].height))
		i++;
	if (i != 4)
		error("texture open error");
}

char	*map_name(int argc, char **argv)
{
	int		i;
	char	*new;
	
	if (argc != 2)
		error("argc not 2");
	new = ft_strdup(argv[1]);
	i = 0;
	while (new[i])
		i++;
	if (ft_strcmp(&new[i - 4], ".ber"))
		error("other extension");
	return (new);
}

int	main(int argc, char **argv)
{
	char		*map_n;
	int			fd;
	t_info		info;
	t_texture	tex[4];

	info.texture = tex;
	map_n = map_name(argc, argv);
	fd = open(map_n, O_RDONLY);
	if (fd == -1)
		error("file open error");
	info.map = split_line(fd);
	close(fd);
	free(map_n);
	map_valid(info.map, &info);
	info.mlx = mlx_init();
	info.win = mlx_new_window(info.mlx, info.screen_w,
			info.screen_h, "so_long");
	tex_init(&info, tex, 0);
	mlx_hook(info.win, 2, 0, key_press, &info);
	mlx_hook(info.win, 17, 0, destroy_notify, &info);
	mlx_loop_hook(info.mlx, draw, &info);
	mlx_loop(info.mlx);
	return (1);
}
