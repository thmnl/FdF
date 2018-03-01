/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intro2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanuel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 05:31:39 by tmanuel           #+#    #+#             */
/*   Updated: 2018/02/01 05:32:25 by tmanuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

static t_libx	*ft_iso1(t_libx *p)
{
	double a;
	double b;

	a = 0.523599;
	b = 2.0944;
	p->u = p->x * cos(a) + p->y * cos(a + b) + p->z * cos(a - b);
	p->v = p->x * sin(a) + p->y * sin(a + b) + p->z * sin(a - b);
	if (p->u > 0)
		p->x1 = (int)p->u + 1;
	else if (p->u == 0)
		p->x1 = 0;
	else
		p->x1 = (int)p->u - 1;
	if (p->v > 0)
		p->y1 = (int)p->v + 1;
	else if (p->v == 0)
		p->y1 = 0;
	else
		p->y1 = (int)p->v - 1;
	return (p);
}

static t_libx	*ft_iso2(t_libx *p)
{
	double a;
	double b;

	a = 0.523599;
	b = 2.0944;
	p->u = p->x * cos(a) + p->y * cos(a + b) + p->z * cos(a - b);
	p->v = p->x * sin(a) + p->y * sin(a + b) + p->z * sin(a - b);
	if (p->u > 0)
		p->x2 = (int)p->u + 1;
	else if (p->u == 0)
		p->x2 = 0;
	else
		p->x2 = (int)p->u - 1;
	if (p->v > 0)
		p->y2 = (int)p->v + 1;
	else if (p->v == 0)
		p->y2 = 0;
	else
		p->y2 = (int)p->v - 1;
	return (p);
}

static void		lets_draw2(int x, int y, int z, t_libx *p)
{
	p->x = x * p->view + p->xview;
	p->y = y * p->view + p->yview;
	p->z = z;
	p = ft_iso1(p);
	if (p->mapintro[y + 1])
	{
		p->x = x * p->view + p->xview;
		p->y = (y + 1) * p->view + p->yview;
		p->z = ft_atoi(p->mapintro[y + 1][x]);
		p = ft_iso2(p);
		ft_draw_seg1(p, z, p->z);
	}
}

static void		lets_draw1(int x, int y, int z, t_libx *p)
{
	p->x = x * p->view + p->xview;
	p->y = y * p->view + p->yview;
	p->z = z;
	p = ft_iso1(p);
	if (p->mapintro[y][x + 1])
	{
		p->x = (x + 1) * p->view + p->xview;
		p->y = y * p->view + p->yview;
		p->z = ft_atoi(p->mapintro[y][x + 1]);
		p = ft_iso2(p);
		ft_draw_seg1(p, z, p->z);
	}
}

void			ft_print_intro(t_libx *p, int reset)
{
	int x;
	int y;

	y = 0;
	p->reset = reset;
	while (p->mapintro[y])
	{
		x = 0;
		while (p->mapintro[y][x])
		{
			lets_draw1(x, y, ft_atoi(p->mapintro[y][x]), p);
			lets_draw2(x, y, ft_atoi(p->mapintro[y][x]), p);
			x++;
		}
		y++;
	}
}
