/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guferrei <guferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 11:53:20 by guferrei          #+#    #+#             */
/*   Updated: 2021/08/26 15:14:17 by guferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	movementY(char c)
{
	if (c == 'W')
	{
		if (*(map.map[(position.py - 10) / 50]
				+ ((position.px + 20) / 50)) == '1')
			return ;
		print_img();
		position.py -= 10;
		if (position.py % 20 == 0)
			print_player(sprites.back1, position.px, position.py);
		else
			print_player(sprites.back2, position.px, position.py);
	}
	else if (c == 'S')
	{
		if (*(map.map[(position.py + 30) / 50]
				+ ((position.px + 20) / 50)) == '1')
			return ;
		print_img();
		position.py += 10;
		if (position.py % 20 == 0)
			print_player(sprites.front1, position.px, position.py);
		else
			print_player(sprites.front2, position.px, position.py);
	}
}

void	movementX(char c)
{
	if (c == 'A')
	{
		if (*(map.map[(position.py + 20) / 50]
				+ ((position.px - 10) / 50)) == '1')
			return ;
		print_img();
		position.px -= 10;
		if (position.px % 20 == 0)
			print_player(sprites.left1, position.px, position.py);
		else
			print_player(sprites.left2, position.px, position.py);
	}
	else if (c == 'D')
	{
		if (*(map.map[(position.py + 20) / 50]
				+ ((position.px + 30) / 50)) == '1')
			return ;
		print_img();
		position.px += 10;
		if (position.px % 20 == 0)
			print_player(sprites.right1, position.px, position.py);
		else
			print_player(sprites.right2, position.px, position.py);
	}
}

int	close_game(void)
{
	exit(1);
	return (1);
}

int	key_input(int key)
{
	if (key == 65307)
		close_game();
	if (key == 119)
		movementY('W');
	if (key == 115)
		movementY('S');
	if (key == 97)
		movementX('A');
	if (key == 100)
		movementX('D');
	get_itens(position.px, position.py);
	enemies(position.px, position.py);
	finish(position.px, position.py);
	mlx_string_put(ptr.mlx, ptr.win, 20, 20, 0xFF0000, ft_itoa(ptr.moves));
	ptr.moves++;
	return (0);
}
