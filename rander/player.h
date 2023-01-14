/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaouan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 21:43:05 by akaouan           #+#    #+#             */
/*   Updated: 2023/01/12 21:43:06 by akaouan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

# define FOV 60
# include "vector.h"

typedef struct player
{
	t_vector	position;
	float		angle;
	float		move_speed;
	float		rotation_speed;
	int			direction;
}	t_player;
#endif
