/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khee-seo <khee-seo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 18:30:10 by khee-seo          #+#    #+#             */
/*   Updated: 2021/09/23 20:04:17 by khee-seo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include "mlx/mlx.h"

typedef struct s_texture
{
	void			*image;
	unsigned int	*image_data;
	int				bpp;
	int				size_line;
	int				endian;
	int				width;
	int				height;
}					t_texture;

typedef struct s_info
{
	void			*mlx;
	void			*win;
	void			*image;
	unsigned int	*image_data;
	int				bpp;
	int				size_line;
	int				endian;
	int				player_x;
	int				player_y;
	int				screen_w;
	int				screen_h;
	int				map_w;
	int				map_h;
	int				collect;
	int				collectcount;
	int				movecount;
	char			**map;
	t_texture		*texture;
}					t_info;

int					destroy_notify(void);
void				tex_init(t_info *info, t_texture *tex, int i);
char				*map_name(int argc, char **argv);

char				*check_m(char *rd, int rd_i, char *backup, char c);
char				*ft_strjoin(char *s1, char *s2, int i, int j);
char				**ft_split(char *rd, int i, int rd_i);
char				*save(char *rd, char *buf);
char				**split_line(int fd);

void				*error(char *str);
int					ft_strlen(char const *s);
char				*ft_strdup(char *src);
int					ft_strcmp(char *s1, char *s2);
int					ft_strstr(char *rd, char c);

int					validwall(char c);
int					wallcheck_w(char **map);
int					wallcheck_h(char **map);
int					validcheck(t_info *info, char **map);
void				map_valid(char **map, t_info *info);

int					check_map_w(char **map);
int					check_map_h(char **map);
int					check_square(t_info *info, char **map, int i, int j);

void				put_tex(t_info *info, int i, int j, int n);
void				read_map(t_info *info);
void				put_base_color(t_info *info, int i, int j);
int					draw(t_info *info);

void				move_forward(t_info *info, char **map);
void				move_backward(t_info *info, char **map);
void				move_left(t_info *info, char **map);
void				move_right(t_info *info, char **map);
int					key_press(int key, t_info *info);

int					check_exit(char **map);
int					check_player(char **map);
int					check_collect(t_info *info, char **map);

#endif
