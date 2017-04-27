/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelharim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 17:38:08 by aelharim          #+#    #+#             */
/*   Updated: 2016/11/24 15:51:25 by aelharim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(char *str)
{
	int index;
	int result;
	int sign;

	index = 0;
	result = 0;
	sign = 1;
	while (str[index] == ' ' || str[index] == '\n'
			|| str[index] == '\t' || str[index] == '\v'
			|| str[index] == '\f' || str[index] == '\r')
		index++;
	if (str[index] == '-')
		sign = -1;
	if (str[index] == '-' || str[index] == '+')
		index++;
	while (str[index] >= '0' && str[index] <= '9')
	{
		result = result * 10 + (str[index] - 48);
		index++;
	}
	return (result * sign);
}
