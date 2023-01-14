/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaouan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 21:42:47 by akaouan           #+#    #+#             */
/*   Updated: 2023/01/12 21:42:49 by akaouan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"
#include "engine.h"
#include "raycast.h"

void	left_right(t_vector **arr, t_engine *engine, int dir)
{
	if (dir > 0)
	{
		arr[0]->x = engine->player.position.x
			+ (cos((engine->player.angle - (M_PI / 2))) * 10);
		arr[0]->y = engine->player.position.y
			+ (sin((engine->player.angle - (M_PI / 2))) * 10);
	}
	else
	{
		arr[0]->x = engine->player.position.x
			+ (cos((engine->player.angle + (M_PI / 2))) * 10);
		arr[0]->y = engine->player.position.y
			+ (sin((engine->player.angle + (M_PI / 2))) * 10);
	}
	if (map_has_wall(arr[0], engine->map))
		return ;
	arr[0]->x = engine->player.position.x
		+ (cos((engine->player.angle - ((M_PI / 2) * dir)))
			* engine->player.move_speed);
	arr[0]->y = engine->player.position.y
		+ (sin((engine->player.angle - ((M_PI / 2) * dir)))
			* engine->player.move_speed);
	vector_assing(&engine->player.position, arr[0]);
}

void	set_pos(t_vector **arr, t_engine *engine, int dir)
{
	arr[0]->x = engine->player.position.x
		+ (cos(engine->player.angle) * 10) * dir;
	arr[0]->y = engine->player.position.y
		+ (sin(engine->player.angle) * 10) * dir;
	arr[1]->x = engine->player.position.x
		+ (cos(engine->player.angle - (90 * M_PI / 180)) * 10) * dir;
	arr[1]->y = engine->player.position.y
		+ (sin(engine->player.angle - (90 * M_PI / 180)) * 10) * dir;
	arr[2]->x = engine->player.position.x
		+ (cos(engine->player.angle - (30 * M_PI / 180)) * 10) * dir;
	arr[2]->y = engine->player.position.y
		+ (sin(engine->player.angle - (30 * M_PI / 180)) * 10) * dir;
	arr[3]->x = engine->player.position.x
		+ (cos(engine->player.angle + (30 * M_PI / 180)) * 10) * dir;
	arr[3]->y = engine->player.position.y
		+ (sin(engine->player.angle + (30 * M_PI / 180)) * 10) * dir;
}

void	up_down(t_vector **arr, t_engine *engine, int dir)
{
	t_vector	next_move;

	set_pos(arr, engine, dir);
	if (map_has_wall(arr[0], engine->map)
		|| map_has_wall(arr[1], engine->map)
		|| map_has_wall(arr[2], engine->map)
		|| map_has_wall(arr[3], engine->map))
		return ;
	next_move.x = engine->player.position.x
		+ (cos(engine->player.angle) * engine->player.move_speed) * dir;
	next_move.y = engine->player.position.y
		+ (sin(engine->player.angle) * engine->player.move_speed) * dir;
	vector_assing(&engine->player.position, &next_move);
}

void	player_movement(t_engine *engine, int move, int dir)
{
	t_vector	end_front_pos;
	t_vector	end_left_pos;
	t_vector	end_right_pos;
	t_vector	end_back_pos;
	t_vector	*arr[4];

	arr[0] = &end_front_pos;
	arr[1] = &end_back_pos;
	arr[2] = &end_left_pos;
	arr[3] = &end_right_pos;
	if (move == UP || move == DOWN)
	{
		up_down(arr, engine, dir);
	}
	else if (move == LEFT || move == RIGHT)
		left_right(arr, engine, dir);
}

void	update_player_dir(t_engine *engine, int dir)
{
	t_player	*player;

	player = &engine->player;
	if (dir == LEFT_DIR)
		player->angle -= player->rotation_speed;
	else
		player->angle += player->rotation_speed;
}
