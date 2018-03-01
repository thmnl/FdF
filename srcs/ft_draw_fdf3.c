/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_fdf3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanuel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 05:51:30 by tmanuel           #+#    #+#             */
/*   Updated: 2018/02/01 08:05:27 by tmanuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_draw_seg12(t_libx *p)
{
	if ((p->dy = p->y2 - p->y1) != 0)
	{
		if (p->dy > 0)
		{
			while (p->y1 != p->y2)
			{
				ft_pixel_put(p);
				p->y1++;
			}
		}
		else
			while (p->y1 != p->y2)
			{
				ft_pixel_put(p);
				p->y1--;
			}
	}
}

void		ft_draw_seg11(t_libx *p)
{
	p->dx = p->dx * 2;
	p->dy = p->dy * 2;
	p->e = p->dy;
	while (p->y1 != p->y2)
	{
		ft_pixel_put(p);
		if ((p->e = p->e - p->dx) >= 0)
		{
			p->x1--;
			p->e = p->e + p->dy;
		}
		p->y1--;
	}
}
