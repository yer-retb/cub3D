/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parce_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yer-retb <yer-retb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 19:57:15 by yer-retb          #+#    #+#             */
/*   Updated: 2023/01/11 17:50:06 by yer-retb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	ft_atoi(char *s)
{
	unsigned long	rsl;
	int				sn;
	int				i;

	sn = 1;
	i = 0;
	rsl = 0;
	while ((s[i] == 32) || (s[i] >= 9 && s[i] <= 13))
		i++;
	if ((s[i] == '-') || (s[i] == '+'))
	{
		if (s[i] == '-')
			sn = -1;
		i++;
	}
	while (s[i] && (s[i] >= '0' && s[i] <= '9'))
	{
		rsl = rsl * 10 + s[i] - '0';
		i++;
	}
	if (rsl >= 9223372036854775807 && sn == -1)
		return (0);
	else if (rsl >= 9223372036854775807 && sn == 1)
		return (-1);
	return (sn * rsl);
}

void	*ft_malloc(int size, t_list *b)
{
	void	*tmp;

	tmp = malloc(size);
	b->save[b->index] = tmp;
	b->index++;
	return (tmp);
}

void	check_extension(char *av)
{
	int		j;
	int		i;
	char	*str;

	i = 0;
	j = 0;
	str = "buc.";
	while (av[j])
		j++;
	j--;
	while (str[i])
		if (str[i++] != av[j--])
			print_error(2);
}

int	len_file(char *av)
{
	int		i;
	char	*map;
	int		fd;

	i = 0;
	fd = open(av, O_RDWR);
	if (fd == -1)
		print_error(6);
	map = get_next_line(fd);
	if (map == NULL)
		print_error(4);
	while (map)
	{
		i++;
		free(map);
		map = get_next_line(fd);
	}
	free(map);
	return (i);
}

char	**allocation_of_lines(char *av, t_list *data)
{
	int		i;
	int		fd;
	char	*str;

	i = 0;
	fd = open(av, O_RDWR);
	while (i < data->len_file)
	{
		str = get_next_line(fd);
		data->map[i] = ft_malloc(sizeof(char) * ft_strlen(str), data);
		data->map[i] = str;
		i++;
	}
	data->map[i] = NULL;
	return (data->map);
}
