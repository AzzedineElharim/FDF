/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelharim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 19:05:43 by aelharim          #+#    #+#             */
/*   Updated: 2017/02/24 15:48:25 by aelharim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/fdf.h"

void			my_menu(t_fdf *fdf)
{
	mlx_string_put(fdf->mlx, fdf->win, 1, 0, FD_WHITE,
			"Press esc to quit");
	mlx_string_put(fdf->mlx, fdf->win, 1, 40, FD_WHITE,
			"ZOOM+ = '+' | ZOOM- = '-'");
	mlx_string_put(fdf->mlx, fdf->win, 1, 60, FD_WHITE,
			"Move left = LeftArrow | Move right = RightArrow");
	mlx_string_put(fdf->mlx, fdf->win, 1, 80, FD_WHITE,
			"Move up = UpArrow | Move down = DownArrow");
	mlx_string_put(fdf->mlx, fdf->win, 1, 100, FD_WHITE,
			"BaseColor : White = 0 | Red = 1 | Blue = 2 | Green = 3");
	mlx_string_put(fdf->mlx, fdf->win, 1, 120, FD_WHITE,
			"ReliefColor : Silver = S | Green = G | Red = R | Blue = B");
	mlx_string_put(fdf->mlx, fdf->win, 1, 140, FD_WHITE,
			"Relief+ = P | Relief- = M");
}

static void		key_color(int keycode, t_fdf *fdf)
{
	if (keycode == 5)
		fdf->colrel = FD_GREEN;
	if (keycode == 29)
		fdf->col = FD_WHITE;
	if (keycode == 18)
		fdf->col = FD_RED;
	if (keycode == 19)
		fdf->col = FD_BLUE;
	if (keycode == 20)
		fdf->col = FD_GREEN;
	if (keycode == 11)
		fdf->colrel = FD_BLUE;
	if (keycode == 15)
		fdf->colrel = FD_RED;
	if (keycode == 1)
		fdf->colrel = FD_SILVER;
}

int				my_key_funct(int keycode, t_fdf *fdf)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 124)
		fdf->dpx += 50;
	if (keycode == 123)
		fdf->dpx -= 50;
	if (keycode == 126)
		fdf->dpy -= 50;
	if (keycode == 125)
		fdf->dpy += 50;
	if (keycode == 69)
		fdf->zoom += 5;
	if (keycode == 78)
		fdf->zoom -= 5;
	if (keycode == 35)
		fdf->hauteur += 1;
	if (keycode == 46)
		fdf->hauteur -= 1;
	key_color(keycode, fdf);
	mlx_clear_window(fdf->mlx, fdf->win);
	my_menu(fdf);
	display(fdf);
	return (0);
}
