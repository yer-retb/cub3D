/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaouan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 21:43:43 by akaouan           #+#    #+#             */
/*   Updated: 2023/01/12 21:43:44 by akaouan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

void	vector_sum(t_vector *vec1, t_vector *vec2)
{
	vec1->x += vec2->x;
	vec1->y += vec2->y;
}

void	vector_assing(t_vector *vec1, t_vector *vec2)
{
	vec1->x = vec2->x;
	vec1->y = vec2->y;
}
