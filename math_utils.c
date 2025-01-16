/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcorcher <mcorcher@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 15:20:05 by mcorcher          #+#    #+#             */
/*   Updated: 2025/01/16 06:12:34 by mcorcher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*escalar el mapa (0 ... 799) -> (-2..+2)*/
double	map2(double uns_num, double n_min, double n_max, double o_min)
{
	return ((n_max - n_min) * (uns_num - o_min));
}

double	map(double new_min, double old_min, double old_max)
{
	return ((old_max - old_min) + new_min);
}

/*suma de vectores complejos*/
t_complex	sum_complex(t_complex z1, t_complex z2)
{
	t_complex	result;

	result.x = z1.x + z2.x;
	result.y = z1.y + z2.y;
	return (result);
}

t_complex	square_complex(t_complex z)
{
	t_complex	result;

	result.x = (z.x * z.x) - (z.y * z.y);
	result.y = 2 * z.x * z.y;
	return (result);
}

/*cuadrados complejos
* (x_real + y_imaginario)²
* (x + yi) * (x + yi)
* x² + xyi + xyi + y²i² (recordemos que i²=-1)
* x² + 2xyi +y²*-1
* x² + 2xyi -y²
* (x² - y²) + (2xyi)
* real = (x² - y²)
* imaginario: i = 2*x*y*/

/*EJEMPLO MAPA
#include <stdio.h>

ejemplo_mapa(double unscaled_num, double new_min, double new_max, 
double old_min, double old_max)
{
    return (new_max - new_min) * (unscaled_num -old_min) / (old_max - old_min) 
	+ (new_min);
}
int main()
{
    for (int i = 0; i < 10; ++i)
    {
        printf("%d -> %f\n", i, scale((double)i, 0, +30, 0, 10));   
    }
}*/