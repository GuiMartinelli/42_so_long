/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guferrei <guferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 14:18:55 by guferrei          #+#    #+#             */
/*   Updated: 2021/08/26 15:33:42 by guferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

unsigned int	get_color(t_data *data, int x, int y)
{
	char	*color;

	color = data->add + (y * data->line + x * (data->bits_per_pixel / 8));
	return (*(unsigned int *)color);
}

void	print_pixel(t_data *data, int x, int y, int color)
{
	char	*dest;

	dest = data->add + (y * data->line + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dest = color;
}

void	death(void)
{
	position.n_c = 0;
	position.n_x = 0;
	itens.triforce = 0;
	itens.colectibles = 0;
	ptr.moves = 0;
	load_sprite();
	make_map();
}

void	kill(int count)
{
	print(sprites.floor, position.xx[count], position.xy[count]);
	position.xx[count] = 0;
}

void	kill_ganon(void)
{
	print(sprites.floor, position.xx[0], position.xy[0]);
	position.xx[0] = 0;
}
