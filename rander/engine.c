/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaouan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 21:42:01 by akaouan           #+#    #+#             */
/*   Updated: 2023/01/12 21:42:02 by akaouan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"
#include "player.h"
#include "../parcing/cub.h"

void	catch_keyboard_events(t_engine *engine)
{
	engine->player.angle = normilize_angle(engine->player.angle);
	if (engine->up == W)
		player_movement(engine, UP, 1);
	if (engine->down == S)
		player_movement(engine, DOWN, -1);
	if (engine->right == D)
		player_movement(engine, RIGHT, -1);
	if (engine->left == A)
		player_movement(engine, LEFT, 1);
	if (engine->left_arrow == LEFT_ARROW)
		update_player_dir(engine, LEFT_DIR);
	if (engine->right_arrow == RIGHT_ARROW)
		update_player_dir(engine, RIGHT_DIR);
	if (engine->mouse_left)
	{
		update_player_dir(engine, LEFT_DIR);
		engine->mouse_left = 0;
	}
	if (engine->mouse_right)
	{
		update_player_dir(engine, RIGHT_DIR);
		engine->mouse_right = 0;
	}
}

void	update(t_engine *engine)
{
	catch_keyboard_events(engine);
	raycast(engine);
	projection(engine);
}

int	loop(t_engine *engine)
{
	update(engine);
	render(engine);
	return (0);
}

int	keyboard_events(int keycode, t_engine *engine)
{
	if (keycode == ESC)
		close_window(engine);
	if (keycode == W)
		engine->up = keycode;
	if (keycode == S)
		engine->down = keycode;
	if (keycode == A)
		engine->left = keycode;
	if (keycode == D)
		engine->right = keycode;
	if (keycode == LEFT_ARROW)
		engine->left_arrow = keycode;
	if (keycode == RIGHT_ARROW)
		engine->right_arrow = keycode;
	return (0);
}

int	key_release(int keycode, t_engine *engine)
{
	if (keycode == W)
		engine->up = -1;
	if (keycode == S)
		engine->down = -1;
	if (keycode == A)
		engine->left = -1;
	if (keycode == D)
		engine->right = -1;
	if (keycode == LEFT_ARROW)
		engine->left_arrow = -1;
	if (keycode == RIGHT_ARROW)
		engine->right_arrow = -1;
	return (0);
}
