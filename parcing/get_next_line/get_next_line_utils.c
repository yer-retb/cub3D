/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yer-retb <yer-retb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 21:15:13 by yer-retb          #+#    #+#             */
/*   Updated: 2023/01/08 21:25:20 by yer-retb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(char *s)
{
	int		i;
	int		j;
	char	*p;

	i = ft_strlen(s);
	p = malloc(i + 1);
	if (!p)
		return (NULL);
	j = 0;
	while (j < i)
	{
		p[j] = s[j];
		j++;
	}
	p[j] = '\0';
	return (p);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		len_s1;
	int		len_s2;
	char	*str;

	if (!s1)
		s1 = ft_strdup("");
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	str = malloc (len_s1 + len_s2 + 1);
	if (!str)
		return (NULL);
	i = -1;
	while (s1[++i] != '\0')
		str[i] = s1[i];
	i = -1;
	while (s2[++i] != '\0')
		str[len_s1 + i] = s2[i];
	str[len_s1 + i] = '\0';
	free (s1);
	return (str);
}

int	ft_strchr(char *ptr)
{
	int	i;

	if (!ptr)
		return (0);
	i = 0;
	while (ptr[i])
	{
		if (ptr[i] == '\n')
			return (1);
	i++;
	}
	return (0);
}

char	*ft_substr(char *str, int start, int len)
{
	int		i;
	int		j;
	char	*p;

	if (start >= len)
		len = 0;
	i = 0;
	while (i < len)
		i++;
	p = malloc (i + 1);
	j = 0;
	while (j < i)
		p[j++] = str[start++];
	p[j] = '\0';
	return (p);
}
