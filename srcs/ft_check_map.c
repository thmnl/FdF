/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanuel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 03:57:15 by tmanuel           #+#    #+#             */
/*   Updated: 2018/02/01 04:04:20 by tmanuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_check_map(char ***map, int i)
{
	int tmp;
	int y;

	tmp = 0;
	y = 0;
	while (map[y])
	{
		tmp = ft_len_tab(map[y]);
		if (tmp != i)
		{
			ft_putendl("Found wrong line length. Exiting.");
			exit(-1);
		}
		y++;
	}
}
