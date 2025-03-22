/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatmoztu <fatmoztu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 18:56:58 by fatmoztu          #+#    #+#             */
/*   Updated: 2025/03/19 18:34:50 by fatmoztu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

double	ft_atod(char *s)
{
	double	num;
	double	dec;
	int		sign;

	num = 0;
	sign = 1;
	dec = 1;
	while ((*s >= 9 && *s <= 13) || *s == 32)
		s++;
	if (*s == '+' || *s == '-')
		if (*s++ == '-')
			sign *= -1;
	while (*s != '.' && *s != '\0')
		num = (num * 10) + (*s++ - 48);
	if (*s == '.')
		s++;
	while (*s != '\0')
	{
		dec /= 10;
		num = num + (*s++ - 48) * dec;
	}
	return (num * sign);
}

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*p;

	p = (unsigned char *)b;
	while (len > 0)
	{
		p[len - 1] = c;
		len--;
	}
	return (b);
}

int	ft_isnumeric_str(char *str)
{
	int	i;
	int	dot_count;

	i = 0;
	dot_count = 0;
	if (str[0] == '-' || str[0] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] == '.')
		{
			if (dot_count > 0)
				return (0);
			dot_count++;
		}
		else if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	if (dot_count == 1 && i == 1)
		return (0);
	return (1);
}
