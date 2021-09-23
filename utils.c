/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khee-seo <khee-seo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 18:24:44 by khee-seo          #+#    #+#             */
/*   Updated: 2021/09/23 20:05:05 by khee-seo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*error(char *str)
{
	int		i;

	write(1, "error\n", 6);
	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	exit(1);
}

int	ft_strlen(char const *s)
{
	int		len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*ft_strdup(char *src)
{
	char	*cpy;
	int		i;

	i = 0;
	while (src[i])
		i++;
	cpy = (char *)malloc(sizeof(char) * (i + 1));
	if (!(cpy))
		error("strdup malloc error");
	i = 0;
	while (src[i])
	{
		cpy[i] = src[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}

int	ft_strcmp(char *s1, char *s2)
{
	int		i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i] || (s1[i] == '\0' && s2[i] == '\0'))
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

int	ft_strstr(char *rd, char c)
{
	int		i;
	int		count;

	i = 0;
	count = 1;
	while (rd[i])
	{
		if (rd[i] == c)
			count++;
		i++;
	}
	if (rd[0] == c)
		count--;
	if (rd[i - 1] == c)
		count--;
	return (count);
}
