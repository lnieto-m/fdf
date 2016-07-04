/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_segment_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnieto-m <lnieto-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/03 18:32:06 by lnieto-m          #+#    #+#             */
/*   Updated: 2016/01/03 19:24:55 by lnieto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		draw_segment_3(t_env *env, t_point a, t_point b)
{
	int		dx;
	int		dy;
	int		e;

	e = a.y - b.y;
	dx = e * 2;
	dy = (b.x - a.x) * 2;
	while (a.y >= b.y)
	{
		image_pixel_put(env, a, a.z);
		a.y--;
		if (a.z - b.z > 0)
			a.z = b.z;
		if ((e -= dy) <= 0)
		{
			a.x++;
			e += dx;
		}
	}
	image_pixel_put(env, b, b.z);
}
