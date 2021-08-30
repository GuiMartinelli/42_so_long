/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guferrei <guferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 13:14:33 by guferrei          #+#    #+#             */
/*   Updated: 2021/08/26 14:31:39 by guferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "mlx/mlx.h"
# include "libft/libft.h"
# include <stdbool.h>
# include <fcntl.h>
# include <stdio.h>

struct	s_ptr
{
	void	*mlx;
	void	*win;
	int		moves;
}		ptr;

struct	s_map
{
	char	*map[20];
	int		x;
	int		y;
}		map;

typedef struct s_data
{
	void	*img;
	char	*add;
	int		bits_per_pixel;
	int		line;
	int		endian;
	int		x;
	int		y;
	bool	equip;
}				t_data;

struct	s_sprites
{
	t_data	front1;
	t_data	front2;
	t_data	back1;
	t_data	back2;
	t_data	left1;
	t_data	left2;
	t_data	right1;
	t_data	right2;
	t_data	sword;
	t_data	ganon;
	t_data	triforce;
	t_data	item;
	t_data	exit;
	t_data	enemy;
	t_data	floor;
	t_data	wall;
	t_data	background;
}		sprites;

struct	s_position
{
	int	px;
	int	py;
	int	cx[10];
	int	cy[10];
	int	n_c;
	int	xx[10];
	int	xy[10];
	int	n_x;
}		position;

struct	s_itens
{
	bool	sword;
	int		triforce;
	int		colectibles;
}		itens;

int				get_map(void);
void			load_sprite(void);
void			load_img(t_data *sprite, char *string);
void			print_pixel(t_data *data, int x, int y, int color);
unsigned int	get_color(t_data *data, int x, int y);
int				map_test(void);
void			make_map(void);
void			get_position(void);
int				print_img(void);
void			print_item(void);
void			print_enemy(void);
void			print(t_data sprite, int x, int y);
void			print_player(t_data sprite, int x, int y);
int				key_input(int key);
void			movementY(char c);
void			get_itens(int x, int y);
void			get_sword(int n);
void			enemies(int x, int y);
void			finish(int x, int y);
void			kill_ganon(void);
void			kill(int count);
void			death(void);
int				close_game(void);

#endif