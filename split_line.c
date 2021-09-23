/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khee-seo <khee-seo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 18:22:20 by khee-seo          #+#    #+#             */
/*   Updated: 2021/09/23 20:02:32 by khee-seo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*check_m(char *rd, int rd_i, char *backup, char c)
{
	int		count;

	count = 1;
	while (rd[rd_i] && rd[rd_i] != c)
	{
		rd_i++;
		count++;
	}
	backup = (char *)malloc(sizeof(char) * count + 1);
	if (!(backup))
		error("split malloc error");
	return (backup);
}

char	*ft_strjoin(char *s1, char *s2, int i, int j)
{
	char	*new;

	if (s1 == 0 || s2 == 0)
		return (0);
	new = (char *)malloc(sizeof(char) * (ft_strlen(s1)
				+ ft_strlen(s2) + 1));
	if (!(new))
		error("strjoin malloc error");
	while (s1[i])
	{
		new[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		new[i] = s2[j];
		i++;
		j++;
	}
	new[i] = '\0';
	return (new);
}

char	**ft_split(char *rd, int i, int rd_i)
{
	int		j;
	char	**backup;

	backup = (char **)malloc(sizeof(char *) * (ft_strstr(rd, '\n') + 2));
	if (!(backup))
		error("split malloc error");
	while (i < ft_strstr(rd, '\n'))
	{
		j = 0;
		backup[i] = check_m(rd, rd_i, backup[i], '\n');
		while (rd[rd_i] && rd[rd_i] != '\n')
		{
			backup[i][j] = rd[rd_i];
			j++;
			rd_i++;
		}
		backup[i][j] = '\0';
		if (rd[rd_i] == '\n')
			rd_i++;
		i++;
	}
	backup[i] = NULL;
	free(rd);
	return (backup);
}

char	*save(char *rd, char *buf)
{
	char	*temp;

	if (rd == NULL)
		rd = ft_strdup(buf);
	else
	{
		temp = ft_strjoin(rd, buf, 0, 0);
		free(rd);
		rd = temp;
	}
	return (rd);
}

char	**split_line(int fd)
{
	char	buf[2];
	char	*rd;
	char	**backup;

	rd = NULL;
	while (1)
	{
		if (0 == read(fd, buf, 1))
			break ;
		buf[1] = '\0';
		rd = save(rd, buf);
	}
	backup = ft_split(rd, 0, 0);
	return (backup);
}
