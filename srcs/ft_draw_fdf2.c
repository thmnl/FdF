/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_fdf2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanuel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 05:50:13 by tmanuel           #+#    #+#             */
/*   Updated: 2018/02/01 08:06:34 by tmanuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_draw_seg10(t_libx *p)
{
	if (p->dx <= p->dy)
	{
		p->dx = p->dx * 2;
		p->dy = p->dy * 2;
		p->e = p->dx;
		while (p->x1 != p->x2)
		{
			ft_pixel_put(p);
			if ((p->e = p->e - p->dy) >= 0)
			{
				p->y1--;
				p->e = p->e + p->dx;
			}
			p->x1--;
		}
	}
	else
		ft_draw_seg11(p);
}

static void	ft_draw_seg9(t_libx *p)
{
	p->dx = p->dx * 2;
	p->dy = p->dy * 2;
	p->e = p->dy;
	while (p->y1 != p->y2)
	{
		ft_pixel_put(p);
		if ((p->e = p->e + p->dx) <= 0)
		{
			p->x1--;
			p->e = p->e + p->dy;
		}
		p->y1++;
	}
}

static void	ft_draw_seg8(t_libx *p)
{
	if ((p->dx * -1) >= p->dy)
	{
		p->dx = p->dx * 2;
		p->dy = p->dy * 2;
		p->e = p->dx;
		while (p->x1 != p->x2)
		{
			ft_pixel_put(p);
			if ((p->e = p->e + p->dy) >= 0)
			{
				p->y1++;
				p->e = p->e + p->dx;
			}
			p->x1--;
		}
	}
	else
		ft_draw_seg9(p);
}

void		ft_draw_seg7(t_libx *p)
{
	if ((p->dy = p->y2 - p->y1) != 0)
	{
		if (p->dy > 0)
			ft_draw_seg8(p);
		else
			ft_draw_seg10(p);
	}
	else
	{
		while (p->x1 != p->x2)
		{
			ft_pixel_put(p);
			p->x1--;
		}
	}
}

void		ft_draw_seg6(t_libx *p)
{
	p->dx = p->dx * 2;
	p->dy = p->dy * 2;
	p->e = p->dy;
	while (p->y1 != p->y2)
	{
		ft_pixel_put(p);
		if ((p->e = p->e + p->dx) > 0)
		{
			p->x1++;
			p->e = p->e + p->dy;
		}
		p->y1--;
	}
}
