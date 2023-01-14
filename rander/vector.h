/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaouan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 21:43:50 by akaouan           #+#    #+#             */
/*   Updated: 2023/01/12 21:43:51 by akaouan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

typedef struct vector
{
	float	x;
	float	y;

}	t_vector;

void	vector_sum(t_vector *vec1, t_vector *vec2);
void	vector_assing(t_vector *vec1, t_vector *vec2);
#endif
