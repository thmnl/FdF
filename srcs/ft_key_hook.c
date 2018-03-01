/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanuel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 07:21:14 by tmanuel           #+#    #+#             */
/*   Updated: 2018/02/08 23:20:35 by tmanuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

static void	ft_3(t_libx *p, int i)
{
	if (i == 1)
		p->height -= 1.5;
	if (i == 2)
		p->height += 1.5;
	mlx_destroy_image(p->mlx_ptr, p->image);
	ft_init(p, 0);
}

static void	ft_2(t_libx *p, int i)
{
	if (i == 3)
	{
		p->xview = p->xview - 50;
		p->yview = p->yview - 50;
	}
	if (i == 4)
	{
		p->xview = p->xview + 50;
		p->yview = p->yview + 50;
	}
	if (i == 5)
	{
		p->xview = p->xview - 50;
		p->yview = p->yview + 50;
	}
	if (i == 6)
	{
		p->xview = p->xview + 50;
		p->yview = p->yview - 50;
	}
	mlx_destroy_image(p->mlx_ptr, p->image);
	ft_init(p, 0);
}

static void	ft_1(t_libx *p, int i)
{
	if (i == 0)
		p->b = p->b - 0.1;
	if (i == 1)
		p->view += 5;
	if (i == 2)
		p->view -= 5;
	if (i == 3)
		p->b = p->b + 0.1;
	if (i == 4)
		p = ft_init_view(p);
	if (i == 5)
		p->a = p->a - 0.05;
	if (i == 6)
		p->a = p->a + 0.05;
	mlx_destroy_image(p->mlx_ptr, p->image);
	ft_init(p, 0);
}

static void	ft_key_hook1(int key, void *param)
{
	if (key == 116)
		ft_3((t_libx*)param, 1);
	if (key == 121)
		ft_3((t_libx*)param, 2);
	if (key == 13)
		ft_1((t_libx*)param, 5);
	if (key == 1)
		ft_1((t_libx*)param, 6);
	if (key == 7)
		ft_change_color((t_libx*)param, 1);
	if (key == 8)
		ft_change_color((t_libx*)param, 0);
	if (key == 16)
		ft_change_color((t_libx*)param, 2);
	if (key == 32)
		ft_change_color((t_libx*)param, -2);
	if (key == 4)
		ft_change_color((t_libx*)param, 3);
	if (key == 38)
		ft_change_color((t_libx*)param, -3);
	if (key == 45)
		ft_change_color((t_libx*)param, 4);
	else
		ft_key_hook3(key, (t_libx*)param);
}

int			ft_key_hook(int key, void *param)
{
	if (key == 53)
		ft_exit_fdf();
	if (key == 0)
		ft_1((t_libx*)param, 0);
	if (key == 2)
		ft_1((t_libx*)param, 3);
	if (key == 15)
		ft_1((t_libx*)param, 4);
	if (key == 69)
		ft_1((t_libx*)param, 1);
	if (key == 78)
		ft_1((t_libx*)param, 2);
	if (key == 126)
		ft_2((t_libx*)param, 3);
	if (key == 125)
		ft_2((t_libx*)param, 4);
	if (key == 123)
		ft_2((t_libx*)param, 5);
	if (key == 124)
		ft_2((t_libx*)param, 6);
	ft_key_hook1(key, param);
	return (0);
}
