/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_engine.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaouan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 21:42:33 by akaouan           #+#    #+#             */
/*   Updated: 2023/01/12 21:42:35 by akaouan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"
#include "player.h"
#include "../parcing/cub.h"

void	init_pos_dir(t_player *player, t_map *map)
{
	if (map->side == 'N')
		player->angle = (270 * M_PI) / 180;
	else if (map->side == 'W')
		player->angle = (180 * M_PI) / 180;
	else if (map->side == 'S')
		player->angle = (90 * M_PI) / 180;
	else if (map->side == 'E')
		player->angle = 0;
	player->position.x = ((map->pos_x + 1)
			* TILE_SIZE) - (TILE_SIZE / 2);
	player->position.y = ((map->pos_y + 1)
			* TILE_SIZE) - (TILE_SIZE / 2);
	player->rotation_speed = (3 * M_PI) / 180;
	player->move_speed = 3;
}

void	get_textures_buffer(void *init, t_text *textures)
{
	char	*texture;
	void	*img;
	int		i;

	i = -1;
	while (++i < 4)
	{
		texture = (char *)*(&textures->no + i);
		img = mlx_xpm_file_to_image(init, texture,
				&textures->data[i].width, &textures->data[i].height);
		textures->data[i].buffer = mlx_get_data_addr(img,
				&textures->data[i].bits_per_pixel,
				&textures->data[i].size_line,
				&textures->data[i].endian);
	}
}

void	init_engine(t_engine **engine, t_map *map)
{
	(*engine) = malloc(sizeof(t_engine));
	(*engine)->init = mlx_init();
	(*engine)->win = mlx_new_window((*engine)->init, W_W, W_H, "cube");
	(*engine)->data.img = mlx_new_image((*engine)->init, W_W, W_H);
	(*engine)->data.addr = mlx_get_data_addr((*engine)->data.img,
			&(*engine)->data.bits_per_pixel,
			&(*engine)->data.line_length, &(*engine)->data.endian);
	(*engine)->map = map;
	(*engine)->c_color = ((map->coler.c_r << 16)
			| (map->coler.c_g << 8)
			| (map->coler.c_b));
	(*engine)->f_color = ((map->coler.f_r << 16)
			| (map->coler.f_g << 8)
			| (map->coler.f_b));
	init_pos_dir(&(*engine)->player, (*engine)->map);
	get_textures_buffer((*engine)->init, &map->txt);
	(*engine)->up = -1;
	(*engine)->down = -1;
	(*engine)->left = -1;
	(*engine)->right = -1;
	(*engine)->left_arrow = -1;
	(*engine)->right_arrow = -1;
}
