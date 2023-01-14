/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getRays.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaouan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 21:42:18 by akaouan           #+#    #+#             */
/*   Updated: 2023/01/12 21:42:28 by akaouan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"
#include "../parcing/cub.h"

void	get_hori_intercept_and_step(t_vector *intercept,
								t_vector *step,
								t_vector *player,
								float angle)
{
	intercept->y = floor(player->y / TILE_SIZE) * TILE_SIZE;
	if (walk_dir(angle) == DOWN)
		intercept->y += TILE_SIZE;
	intercept->x = player->x + (intercept->y - player->y) / tan(angle);
	step->y = TILE_SIZE;
	if (walk_dir(angle) == UP)
		step->y *= -1;
	step->x = TILE_SIZE / tan(angle);
	if (turn_dir(angle) == LEFT_DIR && step->x > 0)
		step->x *= -1;
	if (turn_dir(angle) == RIGHT_DIR && step->x < 0)
		step->x *= -1;
}

void	get_verti_intercept_and_step(t_vector *intercept,
								t_vector *step,
								t_vector *player,
								float angle)
{
	intercept->x = floor(player->x / TILE_SIZE) * TILE_SIZE;
	if (turn_dir(angle) == RIGHT_DIR)
		intercept->x += TILE_SIZE;
	intercept->y = player->y + (intercept->x - player->x) * tan(angle);
	step->x = TILE_SIZE;
	if (turn_dir(angle) == LEFT_DIR)
		step->x *= -1;
	step->y = TILE_SIZE * tan(angle);
	if (walk_dir(angle) == UP && step->y > 0)
		step->y *= -1;
	if (walk_dir(angle) == DOWN && step->y < 0)
		step->y *= -1;
}

t_vector	*horizontal_line(t_vector *player, float angle, t_map *map)
{
	t_vector	*hit_pos;
	t_vector	intercept;
	t_vector	step;
	t_vector	to_check;

	hit_pos = malloc(sizeof(t_vector));
	get_hori_intercept_and_step(&intercept, &step, player, angle);
	while (intercept.x >= 0 && intercept.x <= (map->wid * TILE_SIZE)
		&& intercept.y >= 0 && intercept.y <= (map->len * TILE_SIZE))
	{
		vector_assing(&to_check, &intercept);
		if (walk_dir(angle) == UP)
			to_check.y = to_check.y - 1;
		if (map_has_wall(&to_check, map))
		{
			vector_assing(hit_pos, &intercept);
			return (hit_pos);
		}
		else
			vector_sum(&intercept, &step);
	}
	free(hit_pos);
	return (NULL);
}

t_vector	*vertical_line(t_vector *player, float angle, t_map *map)
{
	t_vector	*hit_pos;
	t_vector	intercept;
	t_vector	step;
	t_vector	to_check;

	hit_pos = malloc(sizeof(t_vector));
	get_verti_intercept_and_step(&intercept, &step, player, angle);
	while (intercept.x >= 0 && intercept.x <= (map->wid * TILE_SIZE)
		&& intercept.y >= 0 && intercept.y <= (map->len * TILE_SIZE))
	{
		to_check.x = intercept.x;
		if (turn_dir(angle) == LEFT_DIR)
			to_check.x = to_check.x - 1;
		to_check.y = intercept.y;
		if (map_has_wall(&to_check, map))
		{
			vector_assing(hit_pos, &intercept);
			return (hit_pos);
		}
		else
			vector_sum(&intercept, &step);
	}
	free(hit_pos);
	return (NULL);
}
