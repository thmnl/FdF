/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanuel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 07:15:00 by tmanuel           #+#    #+#             */
/*   Updated: 2018/02/08 21:08:30 by tmanuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_libx	*ft_iso1(t_libx *p)
{
	p->u = p->x * cos(p->a) + p->y * cos(p->a + p->b) + p->z * cos(p->a - p->b);
	p->v = p->x * sin(p->a) + p->y * sin(p->a + p->b) + p->z * sin(p->a - p->b);
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
	p->u = p->x * cos(p->a) + p->y * cos(p->a + p->b) + p->z * cos(p->a - p->b);
	p->v = p->x * sin(p->a) + p->y * sin(p->a + p->b) + p->z * sin(p->a - p->b);
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
	p->z = ft_z(p, z);
	p = ft_iso1(p);
	if (p->map[y + 1])
	{
		p->x = x * p->view + p->xview;
		p->y = (y + 1) * p->view + p->yview;
		p->z = ft_z(p, ft_atoi(p->map[y + 1][x]));
		p = ft_iso2(p);
		p->xx1 = 0;
		ft_draw_seg1(p, ft_z(p, z), p->z);
	}
}

static void		lets_draw1(int x, int y, int z, t_libx *p)
{
	p->x = x * p->view + p->xview;
	p->y = y * p->view + p->yview;
	p->z = ft_z(p, z);
	p = ft_iso1(p);
	if (p->map[y][x + 1])
	{
		p->x = (x + 1) * p->view + p->xview;
		p->y = y * p->view + p->yview;
		p->z = ft_z(p, ft_atoi(p->map[y][x + 1]));
		p = ft_iso2(p);
		p->xx1 = 1;
		ft_draw_seg1(p, ft_z(p, z), p->z);
	}
}

void			ft_print(t_libx *p, int reset)
{
	int x;
	int y;

	y = 0;
	p->reset = reset;
	while (p->map[y])
	{
		x = 0;
		while (p->map[y][x])
		{
			lets_draw1(x, y, ft_atoi(p->map[y][x]), p);
			lets_draw2(x, y, ft_atoi(p->map[y][x]), p);
			x++;
		}
		y++;
	}
}
