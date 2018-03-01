/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanuel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 21:08:22 by tmanuel           #+#    #+#             */
/*   Updated: 2018/02/08 20:32:46 by tmanuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char		***ft_parse_map2(int fd, int j, char ***tmp)
{
	char	*line;
	int		i;

	i = 0;
	if (!(tmp = (char***)malloc(sizeof(char**) * (j + 1))))
		exit(-1);
	line = NULL;
	while (get_next_line(fd, &line) > 0)
	{
		if (!(tmp[i] = ft_strsplit(line, ' ')))
			exit(-1);
		free(line);
		line = NULL;
		i++;
	}
	tmp[i] = 0;
	if (tmp[0])
		ft_check_map(tmp, ft_len_tab(tmp[0]));
	close(fd);
	return (tmp);
}

t_libx		*ft_parse_map(char *argv)
{
	int		fd;
	char	*line;
	int		i;
	t_libx	*ptr;

	i = 0;
	fd = open(argv, O_RDONLY);
	line = NULL;
	while (get_next_line(fd, &line) > 0)
	{
		free(line);
		line = NULL;
		i++;
	}
	if (i == 0)
		return (NULL);
	close(fd);
	fd = open(argv, O_RDONLY);
	if (!(ptr = (t_libx*)malloc(sizeof(t_libx))))
		exit(-1);
	ptr->map = ft_parse_map2(fd, i, NULL);
	ptr->limity = i;
	if (ptr->map[0])
		ptr->limitx = ft_len_tab(ptr->map[0]);
	return (ptr);
}

int			main(int argc, char **argv)
{
	t_libx	*ptr;

	if (argc > 3 || argc < 2)
	{
		ft_putstr("usage: fdf [-flag] [map]\n");
		return (-1);
	}
	if (argc == 3)
		ft_intro(argv);
	if (!(ptr = ft_parse_map(argv[1])))
	{
		ft_putendl("your map have to be like this: 0 10 10 0");
		return (-1);
	}
	else if (ptr->limity == 0 || ptr->limitx == 0)
	{
		ft_putendl("your map have to be like this: 0 10 10 0");
		return (-1);
	}
	ptr->mlx_ptr = mlx_init();
	ptr->win_ptr = mlx_new_window(ptr->mlx_ptr, SCX, SCY, "");
	ptr = ft_init_view(ptr);
	mlx_key_hook(ptr->win_ptr, ft_key_hook, (t_libx*)ptr);
	ft_init(ptr, 0);
	mlx_loop(ptr->mlx_ptr);
}
