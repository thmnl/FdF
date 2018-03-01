/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intro.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanuel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 23:45:34 by tmanuel           #+#    #+#             */
/*   Updated: 2018/02/09 10:59:04 by tmanuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char		***ft_intro4(void)
{
	char ***t;

	if (!(t = (char***)malloc(sizeof(char**) * (11 + 1))))
		exit(-1);
	t[0] = ft_strsplit("0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0", ' ');
	t[1] = ft_strsplit("0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0", ' ');
	t[2] = ft_strsplit("0 0 10 10 0 0 10 10 0 0 0 10 10 10 10 10 0 0 0", ' ');
	t[3] = ft_strsplit("0 0 10 10 0 0 10 10 0 0 0 0 0 0 0 10 10 0 0", ' ');
	t[4] = ft_strsplit("0 0 10 10 0 0 10 10 0 0 0 0 0 0 0 10 10 0 0", ' ');
	t[5] = ft_strsplit("0 0 10 10 10 10 10 10 0 0 0 0 10 10 10 10 0 0 0", ' ');
	t[6] = ft_strsplit("0 0 0 10 10 10 10 10 0 0 0 10 10 0 0 0 0 0 0", ' ');
	t[7] = ft_strsplit("0 0 0 0 0 0 10 10 0 0 0 10 10 0 0 0 0 0 0", ' ');
	t[8] = ft_strsplit("0 0 0 0 0 0 10 10 0 0 0 10 10 10 10 10 10 0 0", ' ');
	t[9] = ft_strsplit("0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0", ' ');
	t[10] = ft_strsplit("0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0", ' ');
	t[11] = 0;
	return (t);
}

void		ft_intro3(t_libx *p)
{
	mlx_string_put(p->mlx_ptr, p->win_ptr, 750, 300, 0xffffff, "Map:");
	mlx_string_put(p->mlx_ptr, p->win_ptr, 1550, 300, 0xffffff, "3D \
			representation:");
	mlx_string_put(p->mlx_ptr, p->win_ptr, 500, 320, 0xffffff, "0  0  0  \
			0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0");
	mlx_string_put(p->mlx_ptr, p->win_ptr, 500, 340, 0xffffff, "0  0  0  0  \
			0  0  0  0  0  0  0  0  0  0  0  0  0  0  0");
	mlx_string_put(p->mlx_ptr, p->win_ptr, 500, 360, 0xffffff, "0  0 10 10  \
			0  0 10 10  0  0  0 10 10 10 10 10  0  0  0");
	mlx_string_put(p->mlx_ptr, p->win_ptr, 500, 380, 0xffffff, "0  0 10 10  \
			0  0 10 10  0  0  0  0  0  0  0 10 10  0  0");
	mlx_string_put(p->mlx_ptr, p->win_ptr, 500, 400, 0xffffff, "0  0 10 10  \
			0  0 10 10  0  0  0  0  0  0  0 10 10  0  0");
	mlx_string_put(p->mlx_ptr, p->win_ptr, 500, 420, 0xffffff, "0  0 10 10 \
			10 10 10 10  0  0  0  0 10 10 10 10  0  0  0");
	mlx_string_put(p->mlx_ptr, p->win_ptr, 500, 440, 0xffffff, "0  0  0 10 \
			10 10 10 10  0  0  0 10 10  0  0  0  0  0  0");
	mlx_string_put(p->mlx_ptr, p->win_ptr, 500, 460, 0xffffff, "0  0  0  0  \
			0  0 10 10  0  0  0 10 10  0  0  0  0  0  0");
	mlx_string_put(p->mlx_ptr, p->win_ptr, 500, 480, 0xffffff, "0  0  0  0  \
			0  0 10 10  0  0  0 10 10 10 10 10 10  0  0");
	mlx_string_put(p->mlx_ptr, p->win_ptr, 500, 500, 0xffffff, "0  0  0  0  \
			0  0  0  0  0  0  0  0  0  0  0  0  0  0  0");
	mlx_string_put(p->mlx_ptr, p->win_ptr, 500, 520, 0xffffff, "0  0  0  0  \
			0  0  0  0  0  0  0  0  0  0  0  0  0  0  0");
}

void		ft_intro2(t_libx *p)
{
	p->image = mlx_new_image(p->mlx_ptr, SCX, SCY);
	p->pix = mlx_get_data_addr(p->image, &p->bbp, &p->s_l, &p->endian);
	p->x1 = 1260;
	p->x2 = 1260;
	p->y1 = 250;
	p->y2 = 620;
	ft_draw_seg1(p, 0, 0);
	p->mapintro = ft_intro4();
	p->view = 20;
	p->yview = -570;
	p->xview = 1250;
	ft_print_intro(p, 0);
	mlx_put_image_to_window(p->mlx_ptr, p->win_ptr, p->image, 0, 0);
	mlx_string_put(p->mlx_ptr, p->win_ptr, 1109, 100, 0xffffff, "Welcome to \
			the Fdf prodject");
	mlx_string_put(p->mlx_ptr, p->win_ptr, 900, 200, 0xffffff, "This project \
			consists in modeling a 3D representation of a text-based map.");
	mlx_string_put(p->mlx_ptr, p->win_ptr, 1174, 700, 0xffffff, "Press r to \
			start.");
	ft_intro3(p);
}

void		ft_intro(char **argv)
{
	t_libx	*ptr;

	if (strcmp(argv[1], "--intro"))
	{
		ft_putstr("usage: fdf [-flag] [map]\n");
		exit(-1);
	}
	if (!(ptr = ft_parse_map(argv[2])))
	{
		ft_putendl("your map have to be like this: 0 10 10 0");
		exit(-1);
	}
	else if (ptr->limity == 0 || ptr->limitx == 0)
	{
		ft_putendl("your map have to be like this: 0 10 10 0");
		exit(-1);
	}
	ptr->mlx_ptr = mlx_init();
	ptr->win_ptr = mlx_new_window(ptr->mlx_ptr, SCX, SCY, "");
	ptr = ft_init_view(ptr);
	ptr->point0 = 0;
	mlx_key_hook(ptr->win_ptr, ft_key_hook, (t_libx*)ptr);
	ft_intro2(ptr);
	ft_intro_sound();
	mlx_loop(ptr->mlx_ptr);
}
