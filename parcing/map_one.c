/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_one.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yer-retb <yer-retb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 20:20:41 by yer-retb          #+#    #+#             */
/*   Updated: 2023/01/12 02:05:57 by yer-retb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	check_map_one(t_list *data, t_map *d)
{
	int	i;

	check_no(data, d);
	check_so(data, d);
	check_we(data, d);
	check_ea(data, d);
	check_f(data, d);
	check_c(data, d);
	i = -1;
	while (data->map1[++i])
		free(data->map1[i]);
	free(data->map1);
}

void	fill_the_map_one(t_list *data, int size, t_map *d)
{
	int	i;

	i = 0;
	while (i < size)
	{
		data->map1[i] = ft_malloc(sizeof(char) * \
			ft_strlen(data->map[i]), data);
		data->map1[i] = data->map[i];
		if (ft_strlen(data->map[i]) > 1)
			data->con++;
		i++;
	}
	if (data->con != 6)
		print_error(7);
	data->map1[i] = NULL;
	check_map_one(data, d);
}

void	map_one(t_list *data, t_map *d)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j] == ' ' || data->map[i][j] == '\t')
			j++;
		if (data->map[i][j] == '1')
			break ;
		i++;
	}
	data->map1 = malloc(sizeof (char *) * (i + 1));
	fill_the_map_one(data, i, d);
	map_two(data, i, d);
}
