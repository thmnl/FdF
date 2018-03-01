/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intro_sound.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanuel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 06:53:23 by tmanuel           #+#    #+#             */
/*   Updated: 2018/02/05 14:18:14 by tmanuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_free_tmp(char **tmp)
{
	free(tmp[0]);
	free(tmp[1]);
	free(tmp[2]);
	free(tmp[3]);
	free(tmp);
}

void		ft_intro_sound(void)
{
	pid_t	father;
	char	**tmp;

	father = fork();
	if (!(tmp = (char**)malloc(sizeof(char*) * 5)))
		exit(-1);
	tmp[0] = ft_strdup("afplay");
	tmp[1] = ft_strdup("-v");
	tmp[2] = ft_strdup("0.2");
	tmp[3] = ft_strdup("./srcs/sound.mp3");
	tmp[4] = 0;
	if (father == 0)
	{
		if (execve("/usr/bin/afplay", tmp, NULL) == -1)
		{
			ft_free_tmp(tmp);
			exit(0);
		}
	}
	ft_free_tmp(tmp);
}
