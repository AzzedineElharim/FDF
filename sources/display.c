/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelharim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 12:56:35 by aelharim          #+#    #+#             */
/*   Updated: 2017/04/25 20:20:29 by aelharim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/fdf.h"

static void	guagua(t_point p1, t_point p2, t_fdf *fdf)
{
	if (p1.z != 0 || p2.z != 0)
		ligne(p1, p2, fdf, fdf->colrel);
	else
		ligne(p1, p2, fdf, fdf->col);
}

static void	guagua_c(t_fdf *fdf, int j)
{
	fdf->p1 = init_p(j, fdf->h - 1, fdf->tab[fdf->h - 1][j], fdf);
	fdf->p2 = init_p(j + 1, fdf->h - 1, fdf->tab[fdf->h - 1][j + 1], fdf);
	guagua(fdf->p1, fdf->p2, fdf);
}

static void	guagua_b(t_fdf *fdf, int i)
{
	fdf->p1 = init_p(fdf->l - 1, i, fdf->tab[i][fdf->l - 1], fdf);
	fdf->p2 = init_p(fdf->l - 1, i + 1, fdf->tab[i + 1][fdf->l - 1], fdf);
	guagua(fdf->p1, fdf->p2, fdf);
}

static void	guagua_a(t_fdf *fdf, int i, int j)
{
	fdf->p1 = init_p(j, i, fdf->tab[i][j], fdf);
	fdf->p2 = init_p(j + 1, i, fdf->tab[i][j + 1], fdf);
	guagua(fdf->p1, fdf->p2, fdf);
}

void		display(t_fdf *fdf)
{
	int		i;
	int		j;

	i = -1;
	while (++i < fdf->h - 1)
	{
		j = -1;
		while (++j < fdf->l - 1)
		{
			guagua_a(fdf, i, j);
			if (i == fdf->h - 1)
				fdf->p2 = init_p(j, i + 1, fdf->tab[i][j], fdf);
			else
				fdf->p2 = init_p(j, i + 1, fdf->tab[i + 1][j], fdf);
			guagua(fdf->p1, fdf->p2, fdf);
			if (j == fdf->l - 2)
				guagua_b(fdf, i);
			if (i == fdf->h - 2)
				guagua_c(fdf, j);
		}
	}
	my_menu(fdf);
	mlx_key_hook(fdf->win, my_key_funct, fdf);
	mlx_loop(fdf->mlx);
}
