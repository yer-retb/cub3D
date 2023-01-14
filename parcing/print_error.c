/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yer-retb <yer-retb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 20:17:22 by yer-retb          #+#    #+#             */
/*   Updated: 2023/01/11 17:56:42 by yer-retb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ft_free_d(t_map *d)
{
	int	i;

	i = -1;
	while (i < d->len - 1)
		free(d->map[++i]);
	free(d->map);
	free(d->txt.ea);
	free(d->txt.we);
	free(d->txt.no);
	free(d->txt.so);
	free(d);
}

void	ft_free_data(t_list *data)
{
	int	i;

	i = -1;
	free(data->map);
	while (++i < data->index)
		free(data->save[i]);
	free(data);
}

void	print_error(int flag)
{
	if (flag == 1)
		printf("\033[1;31mCHECK YOUR ARG\n");
	else if (flag == 2)
		printf("\033[1;31mERROR IN EXTENSION `.cub\'\n");
	else if (flag == 3)
		printf("\033[1;31mPATH INVALIDE\n");
	else if (flag == 4)
		printf("\033[1;31mEMPTY MAP\n");
	else if (flag == 5)
		printf("\033[1;31mERROR IN POSITION OF TEXTER\n");
	else if (flag == 6)
		printf("\033[1;31mMAP NOT EXIST\n");
	else if (flag == 7)
		printf("\033[1;31mMAP NOT VALIDE\n");
	else if (flag == 8)
		printf("\033[1;31mINVALIDE RGB PATH\n");
	exit(EXIT_FAILURE);
}
