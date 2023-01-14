/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaouan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 21:42:40 by akaouan           #+#    #+#             */
/*   Updated: 2023/01/12 21:42:42 by akaouan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"
#include "../parcing/cub.h"

int	main(int argc, char **argv)
{
	t_engine	*engine;
	t_map		*map;

	map = parcing_map(argc, argv);
	init_engine(&engine, map);
	mlx_hook(engine->win, 2, (1L << 0), keyboard_events, engine);
	mlx_hook(engine->win, 3, (1L << 1), key_release, engine);
	mlx_hook(engine->win, 17, 0, close_window, engine);
	mlx_loop_hook(engine->init, loop, engine);
	mlx_mouse_hook(engine->win, mouse_hook, engine);
	mlx_loop(engine->init);
}
