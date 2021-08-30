/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guferrei <guferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 13:57:58 by guferrei          #+#    #+#             */
/*   Updated: 2021/08/26 14:33:17 by guferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_texture(t_data *texture, int x, int y)
{
	unsigned int	color;
	int				countx;
	int				county;

	countx = 0;
	county = 0;
	while (county < 50)
	{
		while (countx < 50)
		{
			color = get_color(texture, countx, county);
			print_pixel(&sprites.background, (x + countx), (y + county), color);
			countx++;
		}
		countx = 0;
		county++;
	}
}

void	make_map(void)
{
	int	countX;
	int	countY;

	countX = 0;
	countY = 0;
	sprites.background.img = mlx_new_image(ptr.mlx, (map.x * 50), (map.y * 50));
	sprites.background.add = mlx_get_data_addr(sprites.background.img,
			&sprites.background.bits_per_pixel, &sprites.background.line,
			&sprites.background.endian);
	while (countY < map.y)
	{
		while (countX < map.x)
		{
			if (*(map.map[countY] + countX) == '1')
				print_texture(&sprites.wall, (countX * 50), (countY * 50));
			else if (*(map.map[countY] + countX) == 'E')
				print_texture(&sprites.exit, (countX * 50), (countY * 50));
			else
				print_texture(&sprites.floor, (countX * 50), (countY * 50));
			countX++;
		}
		countX = 0;
		countY++;
	}
	get_position();
}

int	map_test(void)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < map.y)
	{
		while (x < map.x)
		{
			if (*(map.map[y] + x) == '0' || *(map.map[y] + x) == '1'
				|| *(map.map[y] + x) == 'P' || *(map.map[y] + x) == 'C'
				|| *(map.map[y] + x) == 'X' || *(map.map[y] + x) == 'E')
				x++;
			else
				return (1);
		}
		x = 0;
		y++;
	}
	return (0);
}
