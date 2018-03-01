/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_fdf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanuel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 04:18:18 by tmanuel           #+#    #+#             */
/*   Updated: 2018/02/08 23:34:08 by tmanuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		ft_init4(t_libx *p, int color)
{
	mlx_string_put(p->mlx_ptr, p->win_ptr, 5, 400, color, "1/!: Music 1");
	mlx_string_put(p->mlx_ptr, p->win_ptr, 5, 420, color, "2/@: Music 2");
	mlx_string_put(p->mlx_ptr, p->win_ptr, 5, 440, color, "3/#: Music 3");
	mlx_string_put(p->mlx_ptr, p->win_ptr, 5, 460, color, "4/$: Music Stop");
}

static void		ft_init3(t_libx *p, int color)
{
	char *tmp1;
	char *tmp2;
	char *tmp3;

	tmp1 = ft_itoa(p->r);
	tmp2 = ft_itoa(p->g);
	tmp3 = ft_itoa(p->bl);
	mlx_string_put(p->mlx_ptr, p->win_ptr, 5, 240, color, "x: color +");
	mlx_string_put(p->mlx_ptr, p->win_ptr, 5, 260, color, "c: color -");
	mlx_string_put(p->mlx_ptr, p->win_ptr, SCX - 100, 0, 0xff0000, "Red:");
	mlx_string_put(p->mlx_ptr, p->win_ptr, SCX - 120, 20, 0x00ff00, "Green:");
	mlx_string_put(p->mlx_ptr, p->win_ptr, SCX - 110, 40, 0x0000ff, "Blue:");
	mlx_string_put(p->mlx_ptr, p->win_ptr, SCX - 50, 0, 0xff0000, tmp1);
	mlx_string_put(p->mlx_ptr, p->win_ptr, SCX - 50, 20, 0x00ff00, tmp2);
	mlx_string_put(p->mlx_ptr, p->win_ptr, SCX - 50, 40, 0x0000ff, tmp3);
	mlx_string_put(p->mlx_ptr, p->win_ptr, 5, 280, color, "y: red + 10");
	mlx_string_put(p->mlx_ptr, p->win_ptr, 5, 300, color, "u: red - 10");
	mlx_string_put(p->mlx_ptr, p->win_ptr, 5, 320, color, "h: green + 10");
	mlx_string_put(p->mlx_ptr, p->win_ptr, 5, 340, color, "j: green - 10");
	mlx_string_put(p->mlx_ptr, p->win_ptr, 5, 360, color, "n: blue + 10");
	mlx_string_put(p->mlx_ptr, p->win_ptr, 5, 380, color, "m: blue - 10");
	free(tmp1);
	free(tmp2);
	free(tmp3);
	ft_init4(p, color);
}

static void		ft_init2(t_libx *p, int reset)
{
	int color;

	color = creatergb(p->r, p->g, p->bl);
	if (reset)
		color = 0x000000;
	mlx_string_put(p->mlx_ptr, p->win_ptr, SCX / 2 + 5, 35, color, "FdF");
	mlx_string_put(p->mlx_ptr, p->win_ptr, 5, 0, color, "ESC: exit");
	mlx_string_put(p->mlx_ptr, p->win_ptr, 5, 20, color, "r: reset view");
	mlx_string_put(p->mlx_ptr, p->win_ptr, 5, 40, color, "Arrow ^: up");
	mlx_string_put(p->mlx_ptr, p->win_ptr, 5, 60, color, "Arrow v: down");
	mlx_string_put(p->mlx_ptr, p->win_ptr, 5, 80, color, "Arrow <: left");
	mlx_string_put(p->mlx_ptr, p->win_ptr, 5, 100, color, "Arrow >: right");
	mlx_string_put(p->mlx_ptr, p->win_ptr, 5, 120, color, "a: rotate -");
	mlx_string_put(p->mlx_ptr, p->win_ptr, 5, 140, color, "d: rotate +");
	mlx_string_put(p->mlx_ptr, p->win_ptr, 5, 160, color, "Page up: \
			increase height");
	mlx_string_put(p->mlx_ptr, p->win_ptr, 5, 180, color, "Page down: \
			decrease height");
	mlx_string_put(p->mlx_ptr, p->win_ptr, 5, 200, color, "Num pad +: zoom");
	mlx_string_put(p->mlx_ptr, p->win_ptr, 5, 220, color, "Num pad -: dezoom");
	ft_init3(p, color);
}

void			ft_init(t_libx *p, int reset)
{
	p->image = mlx_new_image(p->mlx_ptr, SCX, SCY);
	p->pix = mlx_get_data_addr(p->image, &p->bbp, &p->s_l, &p->endian);
	ft_print(p, reset);
	mlx_put_image_to_window(p->mlx_ptr, p->win_ptr, p->image, 0, 0);
	ft_init2(p, reset);
}
