/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_two.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yer-retb <yer-retb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 22:20:17 by yer-retb          #+#    #+#             */
/*   Updated: 2023/01/11 17:47:54 by yer-retb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	handler_map(t_list *data, int size, t_map *d)
{
	int		i;
	char	**new;

	i = 0;
	new = malloc(sizeof(char *) * (size));
	while (i < size)
	{
		new[i] = malloc(sizeof(char) * (data->width_map + 1));
		new[i] = ft_tow(new[i], data->width_map);
		new[i] = ft_strlcpy(new[i], data->map2[i], data->width_map);
		i++;
	}
	the_wall(new, i);
	char_to_int(data, new, d);
	i = -1;
	while (data->map2[++i])
		free(data->map2[i]);
	free(data->map2);
}

int	ft_player(t_list *data, t_map *d, int i, int j)
{
	if (!latters(data->map2[i][j]))
		print_error(7);
	if (data->map2[i][j] == 'N' || data->map2[i][j] == 'S' ||
		data->map2[i][j] == 'E' || data->map2[i][j] == 'W')
	{
		d->pos_y = i;
		d->pos_x = j;
		d->side = data->map2[i][j];
		data->map2[i][j] = '0';
		return (1);
	}
	return (0);
}

void	check_map_two(t_list *data, t_map *d)
{
	int	i;
	int	j;
	int	tallest;
	int	flag;

	i = 0;
	flag = 0;
	data->width_map = 0;
	while (data->map2[i])
	{
		tallest = ft_strlen(data->map2[i]);
		if (tallest > data->width_map)
			data->width_map = tallest;
		j = 0;
		while (data->map2[i][j])
		{
			flag += ft_player(data, d, i, j);
			j++;
		}
		i++;
	}
	d->wid = data->width_map - 1;
	if (flag != 1)
		print_error(7);
	handler_map(data, i, d);
}

void	fill_the_map_two(t_list *data, int size, int i, t_map *d)
{
	int	j;
	int	x;

	j = 0;
	x = 0;
	data->map2 = malloc(sizeof (char *) * (size + 1));
	d->len = size;
	while (j < i)
		j++;
	while (data->map[j])
	{
		data->map2[x] = malloc(sizeof(char) * (ft_strlen(data->map[j]) + 1));
		data->map2[x] = ft_strlcpy2(data->map2[x], data->map[j],
				ft_strlen(data->map[j]) + 1);
		x++;
		j++;
	}
	if (x == 0)
		print_error(4);
	data->map2[x] = NULL;
	check_map_two(data, d);
}

void	map_two(t_list *data, int i, t_map *d)
{
	int	j;
	int	size;

	size = 0;
	j = 0;
	while (j < i)
		j++;
	while (data->map[j])
	{
		j++;
		size++;
	}
	fill_the_map_two(data, size, i, d);
}
