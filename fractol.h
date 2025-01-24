/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcorcher <mcorcher@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 05:47:55 by mcorcher          #+#    #+#             */
/*   Updated: 2025/01/16 05:55:49 by mcorcher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <math.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "minilibx-linux/mlx.h"

# define ERROR_MESSAGE "Introduce Mandelbrot or Julia with 2 values"

//Renderizamos cuadrado para mantener la matemática sencilla
# define WIDTH	800
# define HEIGHT	800
// Colores
// Colores básicos
# define BLACK         0x000000  // Negro
# define WHITE         0xFFFFFF  // Blanco
# define RED           0xFF0000  // Rojo
# define GREEN         0x00FF00  // Verde
# define BLUE          0x0000FF  // Azul
# define YELLOW        0xFFFF00  // Amarillo
# define CYAN          0x00FFFF  // Cian
# define MAGENTA       0xFF00FF  // Magenta
# define GRAY          0x808080  // Gris
# define ORANGE        0xFFA500  // Naranja

// Colores psicodélicos
# define NEON_PINK      0xFF10F0  // Rosa neón
# define ELECTRIC_LIME  0xCCFF00  // Lima eléctrica
# define CYBER_PURPLE   0x8000FF  // Púrpura cibernético
# define HOT_MAGENTA    0xFF00CC  // Magenta intenso
# define VIVID_ORANGE   0xFF4500  // Naranja vívido
# define ACID_GREEN     0x7FFF00  // Verde ácido
# define ULTRA_BLUE     0x0011FF  // Azul ultra
# define PSYCHEDELIC_RED 0xFF0066 // Rojo psicodélico
# define GLOW_YELLOW    0xFFFF33  // Amarillo brillante
# define TROPICAL_AQUA  0x33FFF3  // Agua tropical

// Valores complejos, x=REAL , y=IMAGINARIO
typedef struct s_complex
{
	double	x;
	double	y;
}				t_complex;

//Imagen, buffer de pixeles
typedef struct s_img
{
	void	*img_ptr;
	char	*pixels_ptr;
	int		bpp;
	int		endian;
	int		line_len;
}				t_img;

//Fractal ID, gestionar mlx, imagen y hooks
typedef struct s_fractal
{
	char	*name;
	void	*mlx_connection;
	void	*mlx_window;
	t_img	img;
	double	escape_value;
	int		iterations_defintion;
	double	shift_x;
	double	shift_y;
	double	zoom;
	double	julia_x;
	double	julia_y;
}				t_fractal;

//utils, math utils (usan interpolación linear) y eventos 
int			ft_strncmp(char *s1, char *s2, int n);
void		putstr_fd(char *s, int fd);
double		atodbl(char *s);
void		fractal_init(t_fractal *fractal);
void		fractal_render(t_fractal *fractal);
double		map(double new_min, double old_min, double old_max);
double		map2(double uns_num, double n_min, double n_max, double o_min);
t_complex	sum_complex(t_complex z1, t_complex z2);
t_complex	square_complex(t_complex z);
int			key_handler(int keysym, t_fractal *fractal);
int			close_handler(t_fractal *fractal);
int			mouse_handler(int button, int x, int y, t_fractal *fractal);
int			julia_track(int x, int y, t_fractal *fractal);

#endif
