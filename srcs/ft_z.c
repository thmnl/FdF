/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_z.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanuel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 21:08:02 by tmanuel           #+#    #+#             */
/*   Updated: 2018/02/08 21:08:26 by tmanuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				ft_z(t_libx *p, int z)
{
	if (z == p->point0 || p->height == 0)
		return (z);
	if (z > p->point0 && p->height > 0)
		return (z - (z * p->height));
	if (z > p->point0 && p->height < 0)
		return (z + (z * -p->height));
	if (z < p->point0 && p->height > 0)
		return (z + (z * -p->height));
	if (z < p->point0 && p->height < 0)
		return (z + (z * -p->height));
	return (0);
}
