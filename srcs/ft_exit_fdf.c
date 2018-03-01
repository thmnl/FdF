/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_fdf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanuel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 12:14:12 by tmanuel           #+#    #+#             */
/*   Updated: 2018/02/03 12:19:37 by tmanuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_exit_fdf(void)
{
	char **tmp;

	tmp = ft_strsplit("killall afplay", ' ');
	execve("/usr/bin/killall", tmp, NULL);
}
