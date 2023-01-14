/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_one_utile.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yer-retb <yer-retb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 20:26:34 by yer-retb          #+#    #+#             */
/*   Updated: 2023/01/11 19:00:26 by yer-retb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	check_no(t_list *data, t_map *d)
{
	int		i;
	int		j;
	int		no;

	i = 0;
	no = 0;
	while (data->map1[i])
	{
		j = 0;
		while (data->map1[i][j] && data->map1[i][j] != '\n')
		{
			while (data->map1[i][j] == ' ' || data->map1[i][j] == '\t')
				j++;
			if (data->map1[i][j] == 'N' && data->map1[i][j + 1] == 'O')
				no += norm_check_pos(d, data->map1[i], j, C_N);
			j++;
		}
		i++;
	}
	if (no != 5)
	{
		printf("\033[1;31mERROR : `NO' NOT EXIST\n");
		exit(EXIT_FAILURE);
	}
}

void	check_so(t_list *data, t_map *d)
{
	int		i;
	int		j;
	int		so;

	i = 0;
	so = 0;
	while (data->map1[i])
	{
		j = 0;
		while (data->map1[i][j] && data->map1[i][j] != '\n')
		{
			while (data->map1[i][j] == ' ' || data->map1[i][j] == '\t')
				j++;
			if (data->map1[i][j] == 'S' && data->map1[i][j + 1] == 'O')
				so += norm_check_pos(d, data->map1[i], j, C_S);
			j++;
		}
		i++;
	}
	if (so != 5)
	{
		printf("\033[1;31mERROR : `SO' NOT EXIST\n");
		exit(EXIT_FAILURE);
	}
}

void	check_we(t_list *data, t_map *d)
{
	int		i;
	int		j;
	int		we;

	i = 0;
	we = 0;
	while (data->map1[i])
	{
		j = 0;
		while (data->map1[i][j] && data->map1[i][j] != '\n')
		{
			while (data->map1[i][j] == ' ' || data->map1[i][j] == '\t')
				j++;
			if (data->map1[i][j] == 'W' && data->map1[i][j + 1] == 'E')
				we += norm_check_pos(d, data->map1[i], j, C_W);
			j++;
		}
		i++;
	}
	if (we != 5)
	{
		printf("\033[1;31mERROR : `WE' NOT EXIST\n");
		exit(EXIT_FAILURE);
	}
}

void	check_ea(t_list *data, t_map *d)
{
	int		i;
	int		j;
	int		ea;

	i = 0;
	ea = 0;
	while (data->map1[i])
	{
		j = 0;
		while (data->map1[i][j] && data->map1[i][j] != '\n')
		{
			while (data->map1[i][j] == ' ' || data->map1[i][j] == '\t')
				j++;
			if (data->map1[i][j] == 'E' && data->map1[i][j + 1] == 'A')
				ea += norm_check_pos(d, data->map1[i], j, C_E);
			j++;
		}
		i++;
	}
	if (ea != 5)
	{
		printf("\033[1;31mERROR : `EA' NOT EXIST\n");
		exit(EXIT_FAILURE);
	}
}
