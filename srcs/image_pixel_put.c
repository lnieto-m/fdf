/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_pixel_put.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnieto-m <lnieto-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/30 17:13:57 by lnieto-m          #+#    #+#             */
/*   Updated: 2016/01/18 15:26:26 by lnieto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		color(double z)
{
	int		ret;

	ret = RGB(127.5 * (cos(z) + 1), 127.5 * (sin(z) + 1), 127.5 * (1 - cos(z)));
	return (ret);
}

void			image_pixel_put(t_env *e, t_point a, double z)
{
	int		i;

	i = 0;
	if ((a.x < 0 || a.x >= (e->width / 4) - 1) || (a.y < 0 || a.y > e->height))
		return ;
	e->img_str[a.x + e->width / 4 * a.y] = color(z);
}
