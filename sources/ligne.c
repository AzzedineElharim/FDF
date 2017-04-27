/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ligne.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelharim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 18:58:45 by aelharim          #+#    #+#             */
/*   Updated: 2017/02/24 15:44:30 by aelharim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/fdf.h"

static void			guagua(t_line *line)
{
	line->cumul -= line->dx;
	line->y += line->yinc;
}

static void			guaguab(t_line *line)
{
	line->cumul -= line->dy;
	line->x += line->xinc;
}

static void			guaguac(t_line *line, t_fdf *fdf, long couleur)
{
	line->y += line->yinc;
	line->cumul += line->dx;
	if (line->cumul >= line->dy)
		guaguab(line);
	mlx_pixel_put(fdf->mlx, fdf->win, line->x, line->y, couleur);
}

void				ligne(t_point p1, t_point p2, t_fdf *fdf, long couleur)
{
	t_line			*line;

	line = init_line(p1, p2);
	mlx_pixel_put(fdf->mlx, fdf->win, line->x, line->y, couleur);
	if (line->dx > line->dy)
	{
		line->cumul = line->dx / 2;
		line->i = 0;
		while (++line->i <= line->dx)
		{
			line->x += line->xinc;
			line->cumul += line->dy;
			if (line->cumul >= line->dx)
				guagua(line);
			mlx_pixel_put(fdf->mlx, fdf->win, line->x, line->y, couleur);
		}
	}
	else
	{
		line->cumul = line->dy / 2;
		line->i = 0;
		while (++line->i <= line->dy)
			guaguac(line, fdf, couleur);
	}
}
