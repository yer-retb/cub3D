/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_pars.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yer-retb <yer-retb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 00:39:30 by yer-retb          #+#    #+#             */
/*   Updated: 2023/01/11 19:52:38 by yer-retb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	latters(char c)
{
	if (c != ' ' && c != '\n' && c != '0'
		&& c != '1' && c != 'N' && c != 'S' && c != 'E' && c != 'W')
		return (0);
	return (1);
}

char	*ft_strlcpy2(void *dst, void *src, int dstsize)
{
	int		i;
	char	*str;
	char	*d;

	i = 0;
	if (!dst && !src)
		return (0);
	str = (char *)src;
	d = (char *)dst;
	while (i < dstsize - 1)
	{
		d[i] = str[i];
		i++;
	}
	d[i] = '\0';
	free(str);
	return (d);
}

t_map	*parcing_map(int ac, char **av)
{
	t_list	*data;
	t_map	*d;

	data = malloc(sizeof(t_list));
	d = malloc(sizeof(t_map));
	data->con = 0;
	if (ac != 2)
		print_error(1);
	check_extension(av[1]);
	data->len_file = len_file(av[1]);
	data->map = malloc(sizeof (char *) * (data->len_file + 1));
	data->map = allocation_of_lines(av[1], data);
	map_one(data, d);
	ft_free_data(data);
	return (d);
}
