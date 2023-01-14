/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_one_utile_l.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yer-retb <yer-retb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 20:31:16 by yer-retb          #+#    #+#             */
/*   Updated: 2023/01/11 19:39:18 by yer-retb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	valid_number(char *str, t_map *d, int flag)
{
	int	j;
	int	i;

	j = 0;
	i = 0;
	while (str[j] != '\0')
	{
		if (str[j] == ',' || str[j] == '\n')
		{
			ft_is_valid_num(ft_substr(str, 0, j), d, flag);
			if (str[j])
			{
				if (str[j + 1] == '\0')
					break ;
				str += j + 1;
				i++;
			}
			j = 0;
		}
		j++;
	}
}

void	collect_numbers(char *str, t_map *d, int flag)
{
	int		j;
	int		quot;

	j = 0;
	quot = 0;
	while (str[j])
	{
		if (ft_isdigit(str[j]) || str[j] == ',' || str[j] == '\n')
		{
			if (str[j] == ',')
			{
				if (ft_isdigit(str[j + 1]) == 0)
					print_error(8);
				quot++;
			}
			j++;
		}
		else
			print_error(8);
	}
	if (quot != 2)
		print_error(8);
	valid_number(str, d, flag);
}

int	check_floor_ceilling(char *str, int j, t_map *d, int flag)
{
	j += 1;
	if (str[j] != ' ')
		print_error(8);
	while (str[j] == ' ' || str[j] == '\t')
		j++;
	if (ft_isdigit(str[j]) == 0)
		print_error(8);
	str += j;
	collect_numbers(str, d, flag);
	return (5);
}

void	check_f(t_list *data, t_map *d)
{
	int		i;
	int		j;
	int		ff;

	i = 0;
	ff = 0;
	while (data->map1[i])
	{
		j = 0;
		while (data->map1[i][j] && data->map1[i][j] != '\n')
		{
			while (data->map1[i][j] == ' ' || data->map1[i][j] == '\t')
				j++;
			if (data->map1[i][j] == 'F')
				ff += check_floor_ceilling(data->map1[i], j, d, C_F);
			j++;
		}
		i++;
	}
	if (ff != 5)
	{
		printf("\033[1;31mERROR : `F' NOT EXIST\n");
		exit(EXIT_FAILURE);
	}
}

void	check_c(t_list *data, t_map *d)
{
	int		i;
	int		j;
	int		cc;

	i = 0;
	cc = 0;
	while (data->map1[i])
	{
		j = 0;
		while (data->map1[i][j] && data->map1[i][j] != '\n')
		{
			while (data->map1[i][j] == ' ' || data->map1[i][j] == '\t')
				j++;
			if (data->map1[i][j] == 'C')
				cc += check_floor_ceilling(data->map1[i], j, d, C_C);
			j++;
		}
		i++;
	}
	if (cc != 5)
	{
		printf("\033[1;31mERROR : `C' NOT EXIST\n");
		exit(EXIT_FAILURE);
	}
}
