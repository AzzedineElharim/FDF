/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelharim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 12:50:55 by aelharim          #+#    #+#             */
/*   Updated: 2017/02/24 16:12:56 by aelharim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/fdf.h"

int			first_reader(char **stock, int fd)
{
	char	*tmp;
	char	*cpy;
	int		rd;

	rd = 1;
	tmp = ft_strnew(100);
	*stock = ft_strnew(100);
	while (rd != 0)
	{
		rd = read(fd, tmp, 99);
		if (rd == -1)
			return (-1);
		cpy = ft_strdup(*stock);
		*stock = ft_strnew(ft_strlen(*stock) + 100);
		*stock = ft_strcat(*stock, cpy);
		*stock = ft_strcat(*stock, tmp);
		tmp = ft_strnew(100);
	}
	return (1);
}

int			nb_spaces(char *str)
{
	int		i;
	int		c;

	i = 0;
	c = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ' ')
			c++;
		i++;
	}
	c++;
	return (c);
}

void		grid_reader(char **grid, t_fdf *fdf)
{
	int		i;
	int		y;
	char	**str;

	i = -1;
	while (grid[++i])
	
	if (!(fdf->tab = (int**)malloc(sizeof(int*) * (i + 1))))
			return ;
	i = -1;
	while (grid[++i])
	{
		if (!(fdf->tab[i] = (int*)malloc(sizeof(int) * (nb_spaces(grid[i])))))
			return ;
		str = ft_strsplit(grid[i], ' ');
		y = -1;
		while (str[++y])
			fdf->tab[i][y] = ft_atoi(str[y]);
	}
	fdf->h = i;
	fdf->l = y;
}

void		define_sizes(int *hauteur, int *largeur, char **str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	*hauteur = i;
	i = 0;
	while (str[0][i])
		i++;
	*largeur = i;
}
