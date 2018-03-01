/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_hook3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanuel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 12:21:37 by tmanuel           #+#    #+#             */
/*   Updated: 2018/02/05 08:51:00 by tmanuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_play_sound3(void)
{
	pid_t	father;
	char	**tmp;

	father = fork();
	if (!(tmp = (char**)malloc(sizeof(char*) * 5)))
		exit(-1);
	tmp[0] = ft_strdup("afplay");
	tmp[1] = ft_strdup("-v");
	tmp[2] = ft_strdup("0.1");
	tmp[3] = ft_strdup("./srcs/sound3.mp3");
	tmp[4] = 0;
	if (father == 0)
	{
		if (execve("/usr/bin/afplay", tmp, NULL) == -1)
			exit(0);
	}
	free(tmp[0]);
	free(tmp[1]);
	free(tmp[2]);
	free(tmp[3]);
	free(tmp);
}

static void	ft_play_sound2(void)
{
	pid_t	father;
	char	**tmp;

	father = fork();
	if (!(tmp = (char**)malloc(sizeof(char*) * 5)))
		exit(-1);
	tmp[0] = ft_strdup("afplay");
	tmp[1] = ft_strdup("-v");
	tmp[2] = ft_strdup("0.1");
	tmp[3] = ft_strdup("./srcs/sound2.mp3");
	tmp[4] = 0;
	if (father == 0)
	{
		if (execve("/usr/bin/afplay", tmp, NULL) == -1)
			exit(0);
	}
	free(tmp[0]);
	free(tmp[1]);
	free(tmp[2]);
	free(tmp[3]);
	free(tmp);
}

static void	ft_play_sound1(void)
{
	pid_t	father;
	char	**tmp;

	father = fork();
	if (!(tmp = (char**)malloc(sizeof(char*) * 5)))
		exit(-1);
	tmp[0] = ft_strdup("afplay");
	tmp[1] = ft_strdup("-v");
	tmp[2] = ft_strdup("0.1");
	tmp[3] = ft_strdup("./srcs/sound1.mp3");
	tmp[4] = 0;
	if (father == 0)
	{
		if (execve("/usr/bin/afplay", tmp, NULL) == -1)
			exit(0);
	}
	free(tmp[0]);
	free(tmp[1]);
	free(tmp[2]);
	free(tmp[3]);
	free(tmp);
}

static void	ft_stop_music(void)
{
	pid_t	father;
	char	**tmp;

	tmp = ft_strsplit("killall afplay", ' ');
	father = fork();
	if (father == 0)
		execve("/usr/bin/killall", tmp, NULL);
	free(tmp[0]);
	free(tmp[1]);
	free(tmp);
}

void		ft_key_hook3(int key, t_libx *p)
{
	if (key == 46)
		ft_change_color(p, -4);
	if (key == 18)
		ft_play_sound1();
	if (key == 19)
		ft_play_sound2();
	if (key == 20)
		ft_play_sound3();
	if (key == 21)
		ft_stop_music();
	else
		ft_key_hook4(key, p);
}
