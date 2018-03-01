/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanuel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 09:33:52 by tmanuel           #+#    #+#             */
/*   Updated: 2018/02/09 00:02:03 by tmanuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			creatergb(int r, int g, int b)
{
	return ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);
}

void		ft_put_color(t_libx *p, int r, int g, int b)
{
	int color;
	int i;

	i = ft_abs(p->z1);
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
	color = creatergb(r, g, b);
	ft_putpixel(p, p->x1, p->y1, color);
}

void		ft_put_color2(t_libx *p)
{
	int color;

	if (p->red > p->r)
		p->red--;
	if (p->green > p->g)
		p->green--;
	if (p->blue > p->bl)
		p->blue--;
	color = creatergb(p->red, p->green, p->blue);
	ft_putpixel(p, p->x1, p->y1, color);
}

void		ft_put_color1(t_libx *p)
{
	int color;

	if (p->red < 180)
		p->red++;
	if (p->green < 180)
		p->green++;
	if (p->blue < 180)
		p->blue++;
	color = creatergb(p->red, p->green, p->blue);
	ft_putpixel(p, p->x1, p->y1, color);
}
