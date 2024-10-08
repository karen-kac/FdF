/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myokono <myokono@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 03:16:23 by myokono           #+#    #+#             */
/*   Updated: 2024/09/27 18:44:49 by myokono          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf_bonus.h"

double	ft_normalize(double value, double min, double max)
{
	if (min == max)
		return (0.0);
	return ((value - min) / (max - min));
}

int	ft_abs(int i)
{
	if (i < 0)
		return (-i);
	return (i);
}

static int	ft_get_value(char c, int base)
{
	(void)base;
	if (c >= '0' && c <= '9')
		return (c - '0');
	if (c >= 'A' && c <= 'F')
		return (c - 'A' + 10);
	if (c >= 'a' && c <= 'f')
		return (c - 'a' + 10);
	return (-1);
}

int	ft_atoi_base(const char *str, int base)
{
	int	result;
	int	sign;
	int	value;

	result = 0;
	sign = 1;
	if (base < 2 || base > 16)
		return (0);
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	value = ft_get_value(*str, base);
	while (value != -1 && value < base)
	{
		result = result * base + value;
		str++;
		value = ft_get_value(*str, base);
	}
	return (result * sign);
}

int	ft_free_split(char ***split)
{
	char	**str;
	int		i;

	i = 0;
	str = *split;
	while (*str)
	{
		ft_free((void **)str);
		i++;
		str = &(*split)[i];
	}
	ft_free((void **)split);
	return (0);
}
