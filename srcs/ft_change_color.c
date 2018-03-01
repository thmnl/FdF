/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_change_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanuel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 09:13:49 by tmanuel           #+#    #+#             */
/*   Updated: 2018/02/03 10:48:46 by tmanuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		ft_change_color1(t_libx *p, int j)
{
	if (j == 3)
	{
		p->r = 59;
		p->g = 215;
		p->bl = 54;
	}
	if (j == 4)
	{
		p->r = 215;
		p->g = 204;
		p->bl = 54;
	}
	if (j == 5)
	{
		p->r = 56;
		p->g = 119;
		p->bl = 119;
	}
	mlx_clear_window(p->mlx_ptr, p->win_ptr);
	ft_init(p, 0);
}

static void		ft_change_color2(t_libx *p, int j)
{
	if (j == 0)
	{
		p->r = 151;
		p->g = 4;
		p->bl = 172;
	}
	if (j == 1)
	{
		p->r = 215;
		p->g = 54;
		p->bl = 54;
	}
	if (j == 2)
	{
		p->r = 59;
		p->g = 54;
		p->bl = 215;
	}
	mlx_clear_window(p->mlx_ptr, p->win_ptr);
	ft_init(p, 0);
}

static t_libx	*ft_change_rgb1(t_libx *p, int i)
{
	if (i == -3)
	{
		if ((p->g - 10) < 0)
			p->g = 0;
		else
			p->g = p->g - 10;
	}
	if (i == -4)
	{
		if ((p->bl - 10) < 0)
			p->bl = 0;
		else
			p->bl = p->bl - 10;
	}
	if (i == 4)
	{
		if ((p->bl + 10) > 255)
			p->bl = 255;
		else
			p->bl = p->bl + 10;
	}
	return (p);
}

static void		ft_change_rgb(t_libx *p, int i)
{
	if (i == 2)
	{
		if ((p->r + 10) > 255)
			p->r = 255;
		else
			p->r = p->r + 10;
	}
	if (i == -2)
	{
		if ((p->r - 10) < 0)
			p->r = 0;
		else
			p->r = p->r - 10;
	}
	if (i == 3)
	{
		if ((p->g + 10) > 255)
			p->g = 255;
		else
			p->g = p->g + 10;
	}
	else
		p = ft_change_rgb1(p, i);
	mlx_clear_window(p->mlx_ptr, p->win_ptr);
	ft_init(p, 0);
}

void			ft_change_color(t_libx *p, int i)
{
	static int j;

	if (i == 1)
		j++;
	else if (i == 0)
		j--;
	else
	{
		ft_change_rgb(p, i);
		return ;
	}
	if (j > 5)
		j = 0;
	if (j < 0)
		j = 4;
	if (j == 0 || j == 1 || j == 2)
		ft_change_color2(p, j);
	else
		ft_change_color1(p, j);
}
