/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pixel_put.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanuel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 02:28:19 by tmanuel           #+#    #+#             */
/*   Updated: 2018/02/08 23:28:38 by tmanuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void			ft_putpixel(t_libx *env, int x, int y, int color)
{
	int		pos;
	int8_t	mask;

	if ((x >= 0 && x <= SCX - 1) && (y >= 0 && y <= SCY - 1))
	{
		pos = (y * env->s_l + x * 4);
		mask = color;
		env->pix[pos] = mask;
		color = color >> 8;
		mask = color;
		env->pix[pos + 1] = mask;
		color = color >> 8;
		mask = color;
		env->pix[pos + 2] = mask;
		env->pix[pos + 3] = 0x00;
	}
}

static t_libx	*ft_define_rgb(t_libx *p, int r, int g, int b)
{
	int i;

	i = ft_abs(p->z2);
	while (i != ft_abs(p->point0))
	{
		if (r > p->r)
			r--;
		if (b > p->bl)
			b--;
		if (g > p->g)
			g--;
		i--;
	}
	p->red = r;
	p->green = g;
	p->blue = b;
	return (p);
}

static void		ft_pixel_put2(t_libx *p)
{
	static int i;

	if ((p->z1 < p->z2 && p->xx1 && p->z2 > p->point0)
			|| (p->z1 > p->z2 && p->xx1 && p->z2 < p->point0))
	{
		if (i != p->x2)
		{
			i = p->x2;
			p = ft_define_rgb(p, 180, 180, 180);
		}
		ft_put_color1(p);
	}
	else if (p->xx1)
	{
		if (i != p->x2)
		{
			i = p->x2;
			p = ft_define_rgb(p, 180, 180, 180);
		}
		ft_put_color2(p);
	}
}

void			ft_pixel_put1(t_libx *p)
{
	static int i;

	if ((p->z1 < p->z2 && p->xx1 == 0 && p->z2 > p->point0)
			|| (p->z1 > p->z2 && p->xx1 == 0 && p->z2 < p->point0))
	{
		if (i != p->x2)
		{
			i = p->x2;
			p = ft_define_rgb(p, 180, 180, 180);
		}
		ft_put_color1(p);
	}
	else if (p->xx1 == 0)
	{
		if (i != p->x2)
		{
			i = p->x2;
			p = ft_define_rgb(p, 180, 180, 180);
		}
		ft_put_color2(p);
	}
	else
		ft_pixel_put2(p);
}

void			ft_pixel_put(t_libx *p)
{
	if (p->z1 == p->z2)
	{
		if (p->z1 != p->point0)
			ft_put_color(p, 200, 200, 200);
		else
			ft_putpixel(p, p->x1, p->y1, 0xffffff);
	}
	else
		ft_pixel_put1(p);
}
