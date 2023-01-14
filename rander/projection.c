/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaouan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 21:43:14 by akaouan           #+#    #+#             */
/*   Updated: 2023/01/12 21:43:15 by akaouan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"
#include "engine.h"

void	draw_ceilling(t_data *data,
	t_projection_plan *projection, int x, int color)
{
	int	y;

	y = -1;
	while (++y < projection->top_pixel)
		my_mlx_pixel_put(data, x, y, color);
}

void	draw_floor(t_data *data,
	t_projection_plan *projection, int x, int color)
{
	int	y;

	y = projection->bottom_pixel;
	while (y < W_H)
		my_mlx_pixel_put(data, x, y++, color);
}

void	set_dir(int *dir, int side, float angle)
{
	angle = normilize_angle(angle);
	if (side == VERTICAL_HIT)
	{
		if (turn_dir(angle) == LEFT_DIR)
			*dir = WE;
		else
			*dir = EA;
	}
	else
	{
		if (walk_dir(angle) == UP)
			*dir = NO;
		else
			*dir = SO;
	}
}

void	draw_wall(t_engine *engine,
	t_projection_plan *projection, int x)
{
	int		ofx;
	int		ofy;
	int		dir;
	int		distance;
	char	*pixel;

	if (engine->rays[x].side == VERTICAL_HIT)
		ofx = (int)(engine->rays[x].position->y) % 64;
	else
		ofx = (int)(engine->rays[x].position->x) % 64;
	set_dir(&dir, engine->rays[x].side, engine->rays[x].angle);
	while (projection->top_pixel < projection->bottom_pixel)
	{
		distance = projection->top_pixel
			+ (projection->wall_height / 2) - (W_H / 2);
		ofy = (int)(distance * (float)64 / projection->wall_height);
		pixel = engine->map->txt.data[dir].buffer
			+ (ofy * engine->map->txt.data[dir].size_line)
			+ ofx * (engine->map->txt.data[dir].bits_per_pixel / 8);
		my_mlx_pixel_put(&engine->data, x, projection->top_pixel++,
			*(unsigned int *)pixel);
	}
	free(engine->rays[x].position);
}

void	projection(t_engine *engine)
{
	t_projection_plan	projection;
	int					i;

	i = -1;
	while (++i < NUM_RAYS)
	{
		projection.ray_distance = engine->rays[i].distance
			* cos(engine->rays[i].angle - engine->player.angle);
		projection.distance_projection_plane = (W_W / 2)
			/ tan((FOV * M_PI / 180) / 2);
		projection.wall_height = (TILE_SIZE / projection.ray_distance)
			* projection.distance_projection_plane;
		projection.top_pixel = (W_H / 2) - (projection.wall_height / 2);
		if (projection.top_pixel < 0)
			projection.top_pixel = 0;
		projection.bottom_pixel = (W_H / 2) + (projection.wall_height / 2);
		if (projection.bottom_pixel > W_H)
			projection.bottom_pixel = W_H;
		draw_ceilling(&engine->data, &projection, i, engine->c_color);
		draw_wall(engine, &projection, i);
		draw_floor(&engine->data, &projection, i, engine->f_color);
	}
}
