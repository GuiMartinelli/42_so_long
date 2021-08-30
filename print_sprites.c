/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_sprites.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guferrei <guferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 10:51:56 by guferrei          #+#    #+#             */
/*   Updated: 2021/08/30 08:10:01 by guferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print(t_data sprite, int x, int y)
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
			color = get_color(&sprite, countx, county);
			if (color != 1)
				print_pixel(&sprites.background, (x + countx),
					(y + county), color);
			countx++;
		}
		countx = 0;
		county++;
	}
}

void	print_player(t_data sprite, int x, int y)
{
	unsigned int	color;
	int				countx;
	int				county;

	countx = 0;
	county = 0;
	while (county < 40)
	{
		while (countx < 40)
		{
			color = get_color(&sprite, countx, county);
			if (color != 1)
				mlx_pixel_put(ptr.mlx, ptr.win, (x + countx),
					(y + county), color);
			countx++;
		}
		countx = 0;
		county++;
	}
}

void	print_enemy(void)
{
	int	count;

	count = 0;
	while (count < position.n_x)
	{
		if (position.xx[count] == 0)
			return ;
		if (count == 0)
			print(sprites.ganon, position.xx[0], position.xy[0]);
		else
			print(sprites.enemy, position.xx[count], position.xy[count]);
		count++;
	}
}

void	print_item(void)
{
	int	count;

	count = 0;
	if (position.n_c >= 4)
	{
		while (count < position.n_c)
		{
			if (position.cx[count] == 0)
				return ;
			if (count == 0)
				print(sprites.sword, position.cx[count], position.cy[count]);
			else if (count > 0 && count < 4)
				print(sprites.triforce, position.cx[count], position.cy[count]);
			else
				print(sprites.item, position.cx[count], position.cy[count]);
			count++;
		}
	}
	while (count < position.n_c)
	{
		if (position.cx[count] == 0)
			return ;
		print(sprites.item, position.cx[count], position.cy[count]);
		count++;
	}
}

int	print_img(void)
{
	mlx_put_image_to_window(ptr.mlx, ptr.win, sprites.background.img, 0, 0);
	print_enemy();
	print_item();
	return (0);
}
