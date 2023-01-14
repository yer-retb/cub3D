/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaouan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 21:43:22 by akaouan           #+#    #+#             */
/*   Updated: 2023/01/12 21:43:24 by akaouan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"
#include "engine.h"

t_ray	*init_ray(t_vector *position, float distance, float angle, int side)
{
	t_ray	*ray;

	ray = malloc(sizeof(t_ray));
	ray->distance = distance;
	ray->position = position;
	ray->angle = angle;
	ray->side = side;
	return (ray);
}

t_ray	*get_smallest_ray(t_vector *player, float angle, t_map *map)
{
	t_vector	*hori_line;
	t_vector	*verti_line;
	float		verti_size;
	float		hori_size;

	hori_line = horizontal_line(player, angle, map);
	verti_line = vertical_line(player, angle, map);
	hori_size = dist(player, hori_line);
	verti_size = dist(player, verti_line);
	if (hori_size < verti_size)
	{
		free(verti_line);
		return (init_ray(hori_line, hori_size, angle, HORIZONTAL_HIT));
	}
	else
	{
		free(hori_line);
		return (init_ray(verti_line, verti_size, angle, VERTICAL_HIT));
	}
	ft_free_d(map);
}

void	raycast(t_engine *engine)
{
	t_ray	*ray;
	float	angle;
	float	inc_angle;
	int		i;

	ray = NULL;
	angle = engine->player.angle - ((FOV * (M_PI / 180)) / 2);
	inc_angle = (FOV * (M_PI / 180)) / W_W;
	i = -1;
	while (++i < (W_W))
	{
		angle = normilize_angle(angle);
		ray = get_smallest_ray(&engine->player.position, angle, engine->map);
		engine->rays[i].angle = ray->angle;
		engine->rays[i].distance = ray->distance;
		engine->rays[i].position = ray->position;
		engine->rays[i].side = ray->side;
		free(ray);
		angle += inc_angle;
	}
}
