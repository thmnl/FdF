/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_view.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanuel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 09:41:07 by tmanuel           #+#    #+#             */
/*   Updated: 2018/02/09 11:25:48 by tmanuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		ft_find_point0(t_libx *p)
{
	int x;
	int y;
	int tmp;

	p->point0 = INT_MAX;
	tmp = 0;
	x = 0;
	while (p->map[x])
	{
		y = 0;
		while (p->map[x][y])
		{
			tmp = ft_atoi(p->map[x][y]);
			if (ft_abs(p->point0) > ft_abs(tmp))
				p->point0 = tmp;
			y++;
		}
		x++;
	}
	return (p->point0);
}

static int		ft_find_pointmax(t_libx *p)
{
	int x;
	int y;
	int tmp;

	p->pointmax = 0;
	tmp = 0;
	x = 0;
	while (p->map[x])
	{
		y = 0;
		while (p->map[x][y])
		{
			tmp = ft_atoi(p->map[x][y]);
			if (ft_abs(p->pointmax) < ft_abs(tmp))
				p->pointmax = tmp;
			y++;
		}
		x++;
	}
	return (p->pointmax);
}

static int		ft_view(t_libx *p)
{
	int i;
	int j;

	i = 0;
	j = (p->limitx + p->limity + 20);
	p->view = SCX / j;
	return (p->view);
}

t_libx			*ft_init_view(t_libx *p)
{
	double b;

	b = 0.35;
	p->view = ft_view(p);
	p->point0 = ft_find_point0(p);
	p->pointmax = ft_find_pointmax(p);
	p->xview = SCX * b;
	p->yview = SCY * -b;
	p->a = 0.523599;
	p->b = 2.0944;
	p->r = 151;
	p->g = 4;
	p->bl = 172;
	p->height = -1;
	return (p);
}
