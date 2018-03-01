/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanuel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 21:10:28 by tmanuel           #+#    #+#             */
/*   Updated: 2018/02/09 11:10:23 by tmanuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "mlx.h"
# include "libft.h"
# include "get_next_line.h"
# include <math.h>

# define INT_MAX 2147483647
# define SCY 1440
# define SCX 2560

typedef struct	s_libx
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	char	***mapintro;
	char	***map;
	int		x1;
	int		x2;
	int		y1;
	int		y2;
	int		dx;
	int		dy;
	int		ex;
	int		ey;
	int		e;
	int		limitx;
	int		limity;
	int		x;
	int		y;
	int		z;
	double	u;
	double	v;
	int		view;
	int		xview;
	int		yview;
	int		reset;
	int		z1;
	int		z2;
	int		point0;
	int		pointmax;
	int		red;
	int		blue;
	int		green;
	int		r;
	int		g;
	int		bl;
	int		xx1;
	double	a;
	double	b;
	double	height;
	void	*image;
	char	*pix;
	int		bbp;
	int		s_l;
	int		endian;
}				t_libx;

void			ft_putpixel(t_libx *env, int x, int y, int color);
int				ft_z(t_libx *p, int z);
void			ft_key_hook3(int key, t_libx *p);
void			ft_key_hook4(int key, t_libx *p);
void			ft_exit_fdf(void);
void			ft_change_color(t_libx *p, int i);
int				creatergb(int r, int g, int b);
t_libx			*ft_init_view(t_libx *p);
void			ft_put_color(t_libx *p, int r, int g, int b);
void			ft_put_color1(t_libx *p);
void			ft_put_color2(t_libx *p);
void			ft_intro_sound(void);
void			ft_pixel_put(t_libx *p);
void			ft_check_map(char ***map, int i);
char			***ft_parse_map2(int fd, int j, char ***tmp);
t_libx			*ft_parse_map(char *argv);
int				ft_mouse_hook(int key, void *param);
int				ft_key_hook(int key, void *param);
void			ft_intro(char **argv);
void			ft_print(t_libx *p, int reset);
void			ft_print_intro(t_libx *p, int reset);
void			ft_draw_seg12(t_libx *p);
void			ft_draw_seg11(t_libx *p);
void			ft_draw_seg7(t_libx *p);
void			ft_draw_seg6(t_libx *p);
void			ft_draw_seg1(t_libx *p, int z1, int z2);
void			ft_init(t_libx *p, int reset);

#endif
