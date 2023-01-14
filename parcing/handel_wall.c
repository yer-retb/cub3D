/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handel_wall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yer-retb <yer-retb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 00:28:37 by yer-retb          #+#    #+#             */
/*   Updated: 2023/01/10 01:59:36 by yer-retb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	ziro_player(char c)
{
	if (c == '0' || c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (1);
	return (0);
}

char	*ft_strlcpy(void *dst, void *src, int dstsize)
{
	int		i;
	char	*str;
	char	*d;

	i = 0;
	if (!dst && !src)
		return (0);
	str = (char *)src;
	d = (char *)dst;
	while (i < dstsize)
	{
		if (str[i] == '\0')
			break ;
		if (ziro_player(str[i]) || str[i] == '1')
		{
			d[i] = str[i];
			i++;
		}
		else
			i++;
	}
	return (d);
}

char	*ft_tow(char *str, int size)
{
	int	i;

	i = -1;
	while (++i < size)
		str[i] = '2';
	str[i] = '\0';
	return (str);
}

void	the_wall_two(char **new, int size)
{
	int	i;
	int	j;

	i = 1;
	while (i < size)
	{
		j = 1;
		while (new[i][j])
		{
			if (ziro_player(new[i][j]))
				if (new[i][j - 1] == '2' || new[i][j + 1] == '2' ||
					new[i][j + 1] == '\0' || new[i + 1][j] == '2' ||
						new[i - 1][j] == '2')
					print_error(7);
			j++;
		}
		i++;
	}
}

void	the_wall(char **new, int size)
{
	int	j;

	j = -1;
	while (new[0][++j])
		if (new[0][j] == '0' || new[0][j] == 'N' || new[0][j] == 'E'
			|| new[0][j] == 'W' || new[0][j] == 'S')
			print_error(7);
	j = -1;
	while (new[size - 1][++j])
		if (new[size - 1][j] == '0' || new[size - 1][j] == 'N'
			|| new[size - 1][j] == 'E'
			|| new[size - 1][j] == 'W' || new[size - 1][j] == 'S')
			print_error(7);
	j = -1;
	while (j < size - 1 && new[++j][0])
		if (new[j][0] == '0' || new[j][0] == 'N' || new[j][0] == 'E'
			|| new[j][0] == 'W' || new[j][0] == 'S')
			print_error(7);
	the_wall_two(new, size);
}
