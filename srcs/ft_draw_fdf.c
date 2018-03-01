/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_fdf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanuel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 05:02:07 by tmanuel           #+#    #+#             */
/*   Updated: 2018/02/04 09:04:25 by tmanuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_draw_seg5(t_libx *p)
{
	p->dx = p->dx * 2;
	p->dy = p->dy * 2;
	p->e = p->dx;
	while (p->x1 != p->x2)
	{
		ft_pixel_put(p);
		if ((p->e = p->e + p->dy) < 0)
		{
			p->y1--;
			p->e = p->e + p->dx;
		}
		p->x1++;
	}
}

static void	ft_draw_seg4(t_libx *p)
{
	p->dx = p->dx * 2;
	p->dy = p->dy * 2;
	p->e = p->dy;
	while (p->y1 != p->y2)
	{
		ft_pixel_put(p);
		if ((p->e = p->e - p->dx) < 0)
		{
			p->x1++;
			p->e = p->e + p->dy;
		}
		p->y1++;
	}
}

static void	ft_draw_seg3(t_libx *p)
{
	p->dx = p->dx * 2;
	p->dy = p->dy * 2;
	p->e = p->dx;
	while (p->x1 != p->x2)
	{
		ft_pixel_put(p);
		if ((p->e = p->e - p->dy) < 0)
		{
			p->y1++;
			p->e = p->e + p->dx;
		}
		p->x1++;
	}
}

static void	ft_draw_seg2(t_libx *p)
{
	if ((p->dy = p->y2 - p->y1) != 0)
	{
		if (p->dy > 0)
		{
			if (p->dx >= p->dy)
				ft_draw_seg3(p);
			else
				ft_draw_seg4(p);
		}
		else
		{
			if (p->dx >= (p->dy * -1))
				ft_draw_seg5(p);
			else
				ft_draw_seg6(p);
		}
	}
	else
		while (p->x1 != p->x2)
		{
			ft_pixel_put(p);
			p->x1++;
		}
}

void		ft_draw_seg1(t_libx *p, int z2, int z1)
{
	p->z1 = z1;
	p->z2 = z2;
	if ((p->dx = p->x2 - p->x1) != 0)
	{
		if (p->dx > 0)
			ft_draw_seg2(p);
		else
			ft_draw_seg7(p);
	}
	else
		ft_draw_seg12(p);
	mlx_pixel_put(p->mlx_ptr, p->win_ptr, p->x2, p->y2, 0xffffff);
}
