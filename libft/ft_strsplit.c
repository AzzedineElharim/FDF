/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strsplit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelharim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 18:15:09 by aelharim          #+#    #+#             */
/*   Updated: 2016/11/25 16:18:00 by aelharim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*del_spaces(const char *s, char c)
{
	while (*s == c)
		s++;
	return ((char*)s);
}

static int		nb_w(const char *str, char c)
{
	int i;
	int nb;

	i = 0;
	nb = 0;
	while (str && *(str + i))
	{
		while (*(str + i) && *(str + i) == c)
			i++;
		if (*(str + i))
			nb++;
		while (*(str + i) && *(str + i) != c)
			i++;
	}
	return (nb);
}

static int		ft_strlen_c(const char *s, char c)
{
	int		nb;
	int		i;

	nb = 0;
	i = 0;
	while (s[i] != c && s[i] != '\0')
	{
		i++;
		nb++;
	}
	return (nb);
}

static void		zbeub(int *i, int *mots, const char *s, char c)
{
	*i = -1;
	*mots = nb_w(s, c);
}

char			**ft_strsplit(const char *s, char c)
{
	int		i;
	int		j;
	char	**t;
	int		mots;
	int		taille;

	if (!s)
		return (NULL);
	s = del_spaces(s, c);
	if (!(t = (char**)malloc(sizeof(char*) * (nb_w(s, c) + 1))))
		return (NULL);
	zbeub(&i, &mots, s, c);
	while (++i < mots)
	{
		s = del_spaces(s, c);
		taille = ft_strlen_c(s, c);
		if (!(t[i] = (char*)malloc(sizeof(char) * (taille + 1))))
			return (NULL);
		j = -1;
		while (++j < taille)
			t[i][j] = *s++;
		t[i][j] = '\0';
	}
	t[i] = NULL;
	return (t);
}
