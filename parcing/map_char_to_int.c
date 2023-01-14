/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_char_to_int.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yer-retb <yer-retb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 17:47:39 by yer-retb          #+#    #+#             */
/*   Updated: 2023/01/11 19:49:33 by yer-retb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	char_to_int(t_list *data, char **new, t_map *d)
{
	int	i;
	int	j;

	i = 0;
	(void)data;
	d->map = malloc(sizeof(int *) * d->len + 1);
	while (i < d->len)
	{
		d->map[i] = malloc(sizeof (int) * (d->wid));
		j = 0;
		while (j < d->wid)
		{
			d->map[i][j] = (new[i][j] - '0');
			j++;
		}
		free(new[i]);
		i++;
	}
	free(new);
}
