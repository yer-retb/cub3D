/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaouan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 21:42:10 by akaouan           #+#    #+#             */
/*   Updated: 2023/01/12 21:42:11 by akaouan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENGINE_H
# define ENGINE_H

# include <mlx.h>
// # include "../Libft/libft.h"
# include <stdlib.h>
# include <math.h>
# include "player.h"
# include "raycast.h"
# include "../parcing/cub.h"

enum e_keycode
{
	ESC = 53,
	W = 13,
	S = 1,
	D = 2,
	A = 0,
	LEFT_ARROW = 123,
	RIGHT_ARROW = 124
};
typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		w;
	int		h;
}	t_data;

typedef struct engine
{
	void		*init;
	void		*win;
	t_data		data;
	t_player	player;
	t_ray		rays[NUM_RAYS];
	t_map		*map;
	int			up;
	int			down;
	int			left;
	int			right;
	int			left_arrow;
	int			right_arrow;
	int			mouse_left;
	int			mouse_right;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
	int			c_color;
	int			f_color;
}	t_engine;

typedef struct sprite_infos
{
	float	height;
	float	width;
	float	left_x;
	float	right_x;
	int		top_pixel;
	int		bottom_pixel;
}	t_sprite_infos;

void	raycast(t_engine *engine);
void	player_movement(t_engine *engine, int move, int dir);
void	update_player_dir(t_engine *engine, int dir);
void	init_engine(t_engine **engine, t_map *map);
void	delete_node_elements(void *content);
void	projection(t_engine *engine);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	clear_window(t_data *data);
int		close_window(t_engine *engine);
void	render_map_sprite(t_engine *engine);
void	render_sprite_projection(t_engine *engine);
int		loop(t_engine *engine);
int		key_release(int keycode, t_engine *engine);
int		keyboard_events(int keycode, t_engine *engine);
void	render(t_engine *engine);
void	norm_angle(float *angle);
int		mouse_hook(int b, int x, int y, t_engine *engine);
#endif
