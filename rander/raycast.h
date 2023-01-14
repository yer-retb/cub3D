/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaouan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 21:43:29 by akaouan           #+#    #+#             */
/*   Updated: 2023/01/12 21:43:30 by akaouan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCAST_H
# define RAYCAST_H

# include <stdlib.h>
# include <math.h>
# include "vector.h"
# include <limits.h>
# include "../parcing/cub.h"

# define W_W 1280
# define W_H 720
# define TILE_SIZE 64
# define SCALE 1
# define NUM_RAYS W_W
# define VERTICAL_HIT 0
# define HORIZONTAL_HIT 1

enum e_move
{
	UP = 12,
	DOWN = 13,
	LEFT = 3,
	RIGHT = 4,
	LEFT_DIR = 5,
	RIGHT_DIR = 6
};
typedef struct ray
{
	float		distance;
	float		angle;
	int			side;
	t_vector	*position;
}	t_ray;
typedef struct projection
{
	float	wall_height;
	float	ray_distance;
	float	distance_projection_plane;
	int		top_pixel;
	int		bottom_pixel;
}	t_projection_plan;
t_vector	*vertical_line(t_vector *player, float angle, t_map *map);
t_vector	*horizontal_line(t_vector *player, float angle, t_map *map);
float		dist(t_vector *start, t_vector *end);
float		normilize_angle(float angel);
int			walk_dir(float angle);
int			turn_dir(float angle);
int			map_has_wall(t_vector *vector, t_map *map);
void		vector_sum(t_vector *vec1, t_vector *vec2);
void		vector_assing(t_vector *vec1, t_vector *vec2);
#endif
