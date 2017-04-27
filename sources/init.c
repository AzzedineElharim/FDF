/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelharim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 13:02:01 by aelharim          #+#    #+#             */
/*   Updated: 2017/02/24 15:38:05 by aelharim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/fdf.h"

t_fdf		*fdf_init(void)
{
	t_fdf	*fdf;

	fdf = ft_memalloc(sizeof(t_fdf));
	fdf->fd = 0;
	fdf->tab = NULL;
	fdf->stock = NULL;
	fdf->h = 0;
	fdf->l = 0;
	fdf->cst1 = 1.0;
	fdf->cst2 = 0.5;
	fdf->dpx = 0;
	fdf->dpy = 0;
	fdf->zoom = 20;
	fdf->hauteur = 1;
	fdf->col = FD_WHITE;
	fdf->colrel = FD_RED;
	return (fdf);
}

t_line		*init_line(t_point p1, t_point p2)
{
	t_line	*line;

	line = ft_memalloc(sizeof(t_line));
	line->x = p1.x;
	line->y = p1.y;
	line->dx = p2.x - p1.x;
	line->dy = p2.y - p1.y;
	line->xinc = (line->dx > 0) ? 1 : -1;
	line->yinc = (line->dy > 0) ? 1 : -1;
	line->dx = abs(line->dx);
	line->dy = abs(line->dy);
	return (line);
}

t_point		init_point_proj(t_point p, float cst1, float cst2, t_fdf *fdf)
{
	t_point	p1;
	int		zoom;

	zoom = fdf->hauteur;
	p1.x = (cst1 * p.x) - (cst2 * p.y);
	p1.y = (p.z * (-zoom)) + ((cst1 * p.x) / 2) + ((cst2 * p.y) / 2);
	p1.z = p.z;
	return (p1);
}

t_point		init_p(int x, int y, int z, t_fdf *fdf)
{
	t_point	p;

	p.x = (x * fdf->zoom) + 1000;
	p.y = (y * fdf->zoom) + 600;
	p.z = z;
	p = init_point_proj(p, fdf->cst1, fdf->cst2, fdf);
	p.x += fdf->dpx;
	p.y += fdf->dpy;
	return (p);
}
