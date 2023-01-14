/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaouan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 21:43:36 by akaouan           #+#    #+#             */
/*   Updated: 2023/01/12 21:43:38 by akaouan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

float	dist(t_vector *start, t_vector *end)
{
	float	deltax;
	float	deltay;

	if (!end)
		return (__FLT_MAX__);
	deltax = fabs(end->x - start->x);
	deltay = fabs(end->y - start->y);
	return (sqrt((deltax * deltax) + (deltay * deltay)));
}

float	normilize_angle(float angel)
{
	angel = remainder(angel, (2 * M_PI));
	if (angel < 0)
		angel = ((float)2 * M_PI) + angel;
	return (angel);
}

int	walk_dir(float angle)
{
	if (angle > 0 && angle < M_PI)
		return (DOWN);
	return (UP);
}

int	turn_dir(float angle)
{
	if (angle < (M_PI / 2) || angle > (3 * M_PI / 2))
		return (RIGHT_DIR);
	return (LEFT_DIR);
}

int	map_has_wall(t_vector *vector, t_map *map)
{
	int	map_x;
	int	map_y;

	if (vector->x < 0 || vector->x > (map->wid * 64)
		|| vector->y < 0 || vector->y > (map->len * 64))
		return (1);
	map_x = floor(vector->x / TILE_SIZE);
	map_y = floor(vector->y / TILE_SIZE);
	if (map_x >= map->wid
		|| map_y >= map->len)
		return (1);
	else if (map->map[map_y][map_x] == 1)
		return (1);
	else
		return (0);
}
