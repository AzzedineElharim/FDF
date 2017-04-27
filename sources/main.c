/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelharim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 13:20:30 by aelharim          #+#    #+#             */
/*   Updated: 2017/02/27 17:43:06 by aelharim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/fdf.h"

int			main(int argc, char **argv)
{
	t_fdf	*fdf;

	if (argc == 10)
		return (0);
	fdf = fdf_init();
	fdf->mlx = mlx_init();
	fdf->win = mlx_new_window(fdf->mlx, 1500, 1500, "fdf");
	fdf->fd = open(argv[1], O_RDONLY);
	first_reader(&fdf->stock, fdf->fd);
	grid_reader(ft_strsplit(fdf->stock, '\n'), fdf);
	fdf->win = mlx_new_window(fdf->mlx, 1500, 1500, "fdf");
	display(fdf);
	mlx_loop(fdf->mlx);
	return (0);
}
