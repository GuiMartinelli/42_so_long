/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guferrei <guferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 10:41:18 by guferrei          #+#    #+#             */
/*   Updated: 2021/08/26 15:28:12 by guferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	init_screen(void)
{
	print_img();
	movementY('S');
	return (0);
}

int	main(void)
{
	ptr.mlx = mlx_init();
	if (get_map())
	{
		printf("MAP INVALID\n");
		return (1);
	}
	load_sprite();
	make_map();
	ptr.win = mlx_new_window(ptr.mlx, (map.x * 50), (map.y * 50), "so_long");
	mlx_key_hook(ptr.win, key_input, (void *)0);
	mlx_hook(ptr.win, 17, 0L, close_game, (void *)0);
	mlx_hook(ptr.win, 12, 1L << 15, init_screen, (void *)0);
	mlx_loop(ptr.mlx);
}
