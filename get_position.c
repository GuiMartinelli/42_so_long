/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_position.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guferrei <guferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 07:42:37 by guferrei          #+#    #+#             */
/*   Updated: 2021/08/25 11:04:46 by guferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_position(void)
{
	int	x;
	int	y;

	x = 1;
	y = 1;
	while (y < map.y)
	{
		while (x < map.x)
		{
			if (*(map.map[y] + x) == 'P')
			{
				position.px = x * 50;
				position.py = y * 50;
				return ;
			}
			x++;
		}
		x = 1;
		y++;
	}
}

void	item_position(void)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < map.y)
	{
		while (x < map.x)
		{
			if (*(map.map[y] + x) == 'C')
			{
				position.cx[position.n_c] = x * 50;
				position.cy[position.n_c] = y * 50;
				position.n_c++;
			}
			x++;
		}
		x = 1;
		y++;
	}
}

void	enemy_position(void)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < map.y)
	{
		while (x < map.x)
		{
			if (*(map.map[y] + x) == 'X')
			{
				position.xx[position.n_x] = x * 50;
				position.xy[position.n_x] = y * 50;
				position.n_x++;
			}
			x++;
		}
		x = 1;
		y++;
	}
}

void	get_position(void)
{
	player_position();
	item_position();
	enemy_position();
	print_item();
	print_enemy();
}
