/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yer-retb <yer-retb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 09:09:46 by yer-retb          #+#    #+#             */
/*   Updated: 2023/01/08 05:29:04 by yer-retb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

char	*check_the_n(char *saved, char c)
{
	int	i;

	i = 0;
	if (!saved)
		return (NULL);
	while (saved[i] && saved[i] != c)
		i++;
	if (ft_strlen(saved) == 0)
		return (0);
	return (ft_substr(saved, 0, i + 1));
}

char	*after_the_n(char *after, char d)
{
	int		j;
	char	*str;

	if (!after)
		return (NULL);
	j = 0;
	while (after[j])
	{
		if (after[j] == d)
		{
			str = ft_substr(after, j + 1, ft_strlen(after));
			free(after);
			return (str);
		}
		j++;
	}
	free(after);
	return (NULL);
}

int	no_buf(char *s)
{
	if (s)
	{
		free(s);
		s = NULL;
	}
	return (0);
}

char	*get_next_line(int fd)
{
	int			i;
	char		*buf;
	char		*line;
	static char	*saved;

	buf = malloc(sizeof(char) * 2);
	if (!buf)
		no_buf(saved);
	i = 1;
	while (ft_strchr(saved) == 0 && i > 0)
	{
		i = read (fd, buf, 1);
		if (i >= 0)
		{
			buf[i] = '\0';
			saved = ft_strjoin(saved, buf);
		}
	}
	line = check_the_n(saved, '\n');
	saved = after_the_n(saved, '\n');
	free (buf);
	return (line);
}
