/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guferrei <guferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 10:53:17 by guferrei          #+#    #+#             */
/*   Updated: 2021/08/26 14:37:44 by guferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "so_long.h"

int	map_check_obj(void)
{
	int		count;
	int		exit;
	bool	item;
	bool	enemy;
	int		player;

	count = 0;
	exit = 0;
	player = 0;
	while (count < map.y)
	{
		if (ft_strchr(map.map[count], 'P'))
			player++;
		if (ft_strchr(map.map[count], 'E'))
			exit++;
		if (ft_strchr(map.map[count], 'C'))
			item = true;
		if (ft_strchr(map.map[count], 'X'))
			enemy = true;
		count++;
	}
	if (player == 1 && exit == 1 && item && enemy)
		return (0);
	else
		return (1);
}

int	map_checkX(int n)
{
	int	count;

	count = 0;
	while (*(map.map[n] + count))
	{
		if (*(map.map[n] + count) != '1')
			return (1);
		else
			count++;
	}
	return (0);
}

int	map_checkY(int n)
{
	int	count;

	count = 0;
	while (count < map.y)
	{
		if (*(map.map[count] + n) != '1')
			return (1);
		else
			count++;
	}
	return (0);
}

int	map_check_size(void)
{
	int		count;
	int		size;

	count = 0;
	while (count < map.y)
	{
		size = ft_strlen(map.map[count]);
		if (size != map.x)
			return (1);
		else
			count++;
	}
	return (0);
}

int	get_map(void)
{
	int		fd;
	int		y;
	int		ret;

	ret = 1;
	y = 0;
	fd = open("./levels/map.ber", O_RDONLY);
	if (fd == -1)
		return (1);
	while (ret != 0)
	{
		map.map[y] = malloc(20 * (sizeof(char *)));
		ret = get_next_line(fd, &map.map[y]);
		y++;
	}
	map.x = (int)ft_strlen((const char *)map.map[0]);
	map.y = y;
	close(fd);
	if (map_checkX(0) || map_checkX((map.y - 1))
		|| map_checkY(0) || map_checkY((map.x - 1))
		|| map_check_obj() || map_check_size() || map_test())
		return (1);
	else
		return (0);
}
