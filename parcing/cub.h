/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yer-retb <yer-retb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 00:33:55 by yer-retb          #+#    #+#             */
/*   Updated: 2023/01/11 23:31:00 by yer-retb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

# define C_N 0
# define C_E 1
# define C_W 2
# define C_S 3
# define C_C 4
# define C_F 5

# define NO 0
# define SO 1
# define WE 2
# define EA 3

typedef struct texture_data
{
	char	*buffer;

	int		width;
	int		height;
	int		bits_per_pixel;
	int		size_line;
	int		endian;

}	t_texture_data;

typedef struct s_text
{
	char			*no;
	char			*so;
	char			*ea;
	char			*we;
	t_texture_data	data[4];
}	t_text;

typedef struct s_coler
{
	int	f_r;
	int	f_g;
	int	f_b;
	int	c_r;
	int	c_g;
	int	c_b;

}	t_coler;

typedef struct s_map
{
	int		**map;
	int		len;
	int		wid;
	int		pos_x;
	int		pos_y;
	t_text	txt;
	t_coler	coler;
	char	side;

}	t_map;

typedef struct s_list
{
	char	**map;
	char	**map1;
	char	**map2;
	int		len_file;
	int		width_map;
	int		length_map;
	int		con;
	void	*save[1000000];
	int		index;

}	t_list;

/*----------- GET NEXT LINE -------------*/

int		ft_strlen(char *str);
int		ft_strchr(char *ptr);
char	*get_next_line(int fd);
char	*ft_strdup(char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char *str, int start, int len);
char	*check_the_n(char *saved, char c);
char	*after_the_n(char *after, char d);

/*--------------- CUB3D ----------------*/

t_map	*parcing_map(int ac, char **av);
void	check_extension(char *av);
void	print_error(int flag);
int		len_file(char *av);
char	**allocation_of_lines(char *av, t_list *data);
void	*ft_malloc(int size, t_list *b);
int		ft_atoi(char *s);
int		ft_isalnum(int i);
int		ft_isalpha(int i);
int		ft_isdigit(int i);
int		ft_strcmp(char *s1, char *s2);
int		ft_strncmp(char *s1, char *s2, int n);
void	print_error(int flag);
void	map_one(t_list *data, t_map *d);
void	fill_the_map_one(t_list *data, int size, t_map *d);
void	check_map_one(t_list *data, t_map *d);
void	check_no(t_list *data, t_map *d);
void	check_so(t_list *data, t_map *d);
void	check_we(t_list *data, t_map *d);
void	check_ea(t_list *data, t_map *d);
void	check_c(t_list *data, t_map *d);
void	check_f(t_list *data, t_map *d);
int		check_floor_ceilling(char *str, int j, t_map *d, int flag);
void	collect_numbers(char *str, t_map *d, int flag);
void	valid_number(char *str, t_map *d, int flag);
void	ft_is_valid_num(char *str, t_map *d, int flag);
int		norm_check_pos(t_map *data, char *str, int j, int flag);
void	map_two(t_list *data, int i, t_map *d);
void	fill_the_map_two(t_list *data, int size, int i, t_map *d);
char	*ft_strlcpy2(void *dst, void *src, int dstsize);
void	check_map_two(t_list *data, t_map *d);
int		latters(char c);
void	handler_map(t_list *data, int size, t_map *d);
char	*ft_tow(char *str, int size);
char	*ft_strlcpy(void *dst, void *src, int dstsize);
void	the_wall(char **new, int size);
void	the_wall_two(char **new, int size);
int		ziro_player(char c);
void	char_to_int(t_list *data, char **new, t_map *d);
void	ft_free_data(t_list *data);
void	ft_free_d(t_map *d);

#endif
