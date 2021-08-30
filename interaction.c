/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interaction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guferrei <guferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 08:30:50 by guferrei          #+#    #+#             */
/*   Updated: 2021/08/30 08:07:51 by guferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_itens(int x, int y)
{
	int	count;

	count = 0;
	while (count < position.n_c)
	{
		if ((x > position.cx[count] && x < (position.cx[count] + 50)
				&& y > position.cy[count] && y < (position.cy[count] + 50))
			|| ((x + 40) > position.cx[count]
				&& (x + 40) < (position.cx[count] + 50)
				&& (y + 40) > position.cy[count]
				&& (y + 40) < (position.cy[count] + 50)))
		{
			print(sprites.floor, position.cx[count], position.cy[count]);
			get_sword(count);
			return ;
		}
		else
			count++;
	}
}

void	get_sword(int n)
{
	if (position.n_c >= 4)
	{
		if (n == 0)
		{
			load_img(&sprites.front1, "./textures/front_s1.xpm");
			load_img(&sprites.front2, "./textures/front_s2.xpm");
			load_img(&sprites.back1, "./textures/back_s1.xpm");
			load_img(&sprites.back2, "./textures/back_s2.xpm");
			load_img(&sprites.right1, "./textures/right_s1.xpm");
			load_img(&sprites.right2, "./textures/right_s2.xpm");
			load_img(&sprites.sword, "./textures/no_sword.xpm");
			print(sprites.sword, position.cx[0], position.cy[0]);
			itens.sword = true;
		}
		else if (n > 0 && n < 4)
			itens.triforce++;
	}
	position.cx[n] = 0;
	itens.colectibles++;
}

void	enemies(int x, int y)
{
	int	count;

	count = 0;
	while (count < position.n_x)
	{
		if ((x > position.xx[count] && x < (position.xx[count] + 50)
				&& y > position.xy[count] && y < (position.xy[count] + 50))
			|| ((x + 40) > position.xx[count]
				&& (x + 40) < (position.xx[count] + 50)
				&& (y + 40) > position.xy[count]
				&& (y + 40) < (position.xy[count] + 80)))
		{
			if (count == 0 && itens.sword && itens.triforce == 3)
				kill_ganon();
			else if (itens.sword && count != 0)
				kill(count);
			else
				death();
		}
		count++;
	}
}

void	finish(int x, int y)
{
	if (*(map.map[y / 50] + (x / 50)) == 'E'
		|| (*(map.map[(y + 40) / 50] + ((x + 40) / 50)) == 'E'))
	{
		if (itens.colectibles == position.n_c)
			death();
	}
}
