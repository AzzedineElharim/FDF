/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelharim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 14:56:31 by aelharim          #+#    #+#             */
/*   Updated: 2017/02/24 15:12:41 by aelharim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define FD_WHITE 0xFFFFFF
# define FD_SILVER 0xC0C0C0
# define FD_YELLOW 0xFFFF00
# define FD_RED 0xFF0000
# define FD_GRAY 0x808080
# define FD_AQUA 0x00FFFF
# define FD_GREEN 0x008000
# define FD_BLUE 0x0000FF
# define FD_BUFF_SIZE 4096
# include "../mlx/mlx.h"
# include "../libft/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# define WIDTH  600
# define HEIGHT 600

typedef struct		s_point
{
	int				x;
	int				y;
	int				z;
}					t_point;

typedef struct		s_line
{
	int				dx;
	int				dy;
	int				i;
	int				xinc;
	int				yinc;
	int				cumul;
	int				x;
	int				y;
}					t_line;

typedef struct		s_fdf
{
	void			*mlx;
	void			*win;
	char			*stock;
	int				**tab;
	int				fd;
	int				h;
	int				l;
	float			cst1;
	float			cst2;
	int				dpx;
	int				dpy;
	int				zoom;
	int				hauteur;
	long			col;
	long			colrel;
	t_point			p1;
	t_point			p2;
	int				i;
	int				j;
	int				dim;
}					t_fdf;

t_point				init_p(int x, int y, int z, t_fdf *fdf);
t_line				*init_line(t_point p1, t_point p2);
t_fdf				*fdf_init(void);
void				display(t_fdf *fdf);
void				define_size(int *hauteur, int *largeur, char **str);
void				my_menu(t_fdf *fdf);
void				grid_reader(char **grid, t_fdf *fdf);
int					nb_spaces(char *str);
int					first_reader(char **stock, int fd);
void				ligne(t_point p1, t_point p2, t_fdf *fdf, long couleur);
int					my_key_funct(int keycode, t_fdf *fdf);

#endif
