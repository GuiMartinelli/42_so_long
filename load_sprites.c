/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guferrei <guferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 13:46:46 by guferrei          #+#    #+#             */
/*   Updated: 2021/08/26 15:12:53 by guferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_img(t_data *sprite, char *string)
{
	sprite->img = mlx_xpm_file_to_image(ptr.mlx, string,
			&sprite->x, &sprite->y);
	sprite->add = mlx_get_data_addr(sprite->img, &sprite->bits_per_pixel,
			&sprite->line, &sprite->endian);
}

void	load_sprite(void)
{
	load_img(&sprites.front1, "./textures/front_1.xpm");
	load_img(&sprites.front2, "./textures/front_2.xpm");
	load_img(&sprites.back1, "./textures/back_1.xpm");
	load_img(&sprites.back2, "./textures/back_2.xpm");
	load_img(&sprites.left1, "./textures/left_1.xpm");
	load_img(&sprites.left2, "./textures/left_2.xpm");
	load_img(&sprites.right1, "./textures/right_1.xpm");
	load_img(&sprites.right2, "./textures/right_2.xpm");
	load_img(&sprites.floor, "./textures/floor.xpm");
	load_img(&sprites.wall, "./textures/wall.xpm");
	load_img(&sprites.exit, "./textures/zelda.xpm");
	load_img(&sprites.enemy, "./textures/enemy.xpm");
	load_img(&sprites.ganon, "./textures/ganon.xpm");
	load_img(&sprites.item, "./textures/rupee.xpm");
	load_img(&sprites.sword, "./textures/sword.xpm");
	load_img(&sprites.triforce, "./textures/triforce.xpm");
}
