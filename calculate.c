/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatmoztu <fatmoztu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 18:57:35 by fatmoztu          #+#    #+#             */
/*   Updated: 2025/03/17 18:59:53 by fatmoztu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	calculate(t_fractol *ptr)
{
	int		i;
	double	temp;

	i = 0;
	while (i < MAX_ITER)
	{
		if ((ptr->z_r * ptr->z_r) + (ptr->z_i * ptr->z_i) > 4)
			break ;
		temp = (ptr->z_r * ptr->z_r) - (ptr->z_i * ptr->z_i) + ptr->c_r;
		ptr->z_i = (2.0 * ptr->z_r * ptr->z_i) + ptr->c_i;
		ptr->z_r = temp;
		i++;
	}
	if (i == MAX_ITER)
		color(ptr, 0x000000);
	else
		color(ptr, 0xFF76c56e * i);
}
