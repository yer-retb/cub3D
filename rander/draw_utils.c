/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaouan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 21:41:51 by akaouan           #+#    #+#             */
/*   Updated: 2023/01/12 21:41:53 by akaouan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

int	mouse_hook(int b, int x, int y, t_engine *engine)
{
	(void)y;
	if (b == 1)
	{
		if (x < (W_W / 2))
			engine->mouse_left = 1;
		if (x > (W_W / 2))
			engine->mouse_right = 1;
	}
	return (0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	render(t_engine *engine)
{
	mlx_put_image_to_window(engine->init, engine->win, engine->data.img, 0, 0);
}

int	close_window(t_engine *engine)
{
	mlx_destroy_window(engine->init, engine->win);
	printf("Finish\n");
	free(engine);
	exit(0);
}

void	norm_angle(float *angle)
{
	if (*angle > M_PI)
		*angle -= 2 * M_PI;
	if (*angle < -M_PI)
		*angle += 2 * M_PI;
	*angle = fabs(*angle);
}
