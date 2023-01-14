/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_one_utile_ll.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yer-retb <yer-retb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 20:33:59 by yer-retb          #+#    #+#             */
/*   Updated: 2023/01/11 19:42:26 by yer-retb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	give_texter(t_map *data, char *tmp, int flag)
{
	if (flag == C_N)
		data->txt.no = tmp;
	else if (flag == C_S)
		data->txt.so = tmp;
	else if (flag == C_E)
		data->txt.ea = tmp;
	else if (flag == C_W)
		data->txt.we = tmp;
}

int	norm_check_pos(t_map *data, char *str, int j, int flag)
{
	char	*tmp;

	j += 2;
	if (str[j] != ' ')
		print_error(3);
	while (str[j] == ' ' || str[j] == '\t')
		j++;
	tmp = ft_substr(str, j, ft_strlen(str) - j - 1);
	if (access(tmp, F_OK) == -1)
		print_error(3);
	give_texter(data, tmp, flag);
	return (5);
}

void	f_rgb(t_map *d, int num)
{
	static int	i;

	if (i == 0)
	{
		d->coler.f_r = num;
		i++;
	}
	else if (i == 1)
	{
		d->coler.f_g = num;
		i++;
	}
	else if (i == 2)
	{
		d->coler.f_b = num;
		i = 0;
	}
}

void	c_rgb(t_map *d, int num)
{
	static int	j;

	if (j == 0)
	{
		d->coler.c_r = num;
		j++;
	}
	else if (j == 1)
	{
		d->coler.c_g = num;
		j++;
	}
	else if (j == 2)
	{
		d->coler.c_b = num;
		j = 0;
	}
}

void	ft_is_valid_num(char *str, t_map *d, int flag)
{
	int			num;

	num = ft_atoi(str);
	free(str);
	if (num < 0 || num > 255)
		print_error(8);
	if (flag == C_F)
		f_rgb(d, num);
	else if (flag == C_C)
		c_rgb(d, num);
	return ;
}
