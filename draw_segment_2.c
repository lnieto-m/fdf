/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_segment_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnieto-m <lnieto-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/03 18:26:39 by lnieto-m          #+#    #+#             */
/*   Updated: 2016/01/03 19:24:56 by lnieto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		draw_segment_2(t_env *env, t_point a, t_point b)
{
	int		dx;
	int		dy;
	int		e;

	e = b.x - a.x;
	dx = e * 2;
	dy = (b.y - a.y) * 2;
	while (a.x <= b.x)
	{
		image_pixel_put(env, a, a.z);
		a.x++;
		if (a.z - b.z > 0)
			a.z = b.z;
		if ((e += dy) <= 0)
		{
			a.y--;
			e += dx;
		}
	}
	image_pixel_put(env, b, b.z);
}
