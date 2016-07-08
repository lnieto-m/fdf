/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_segment.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnieto-m <lnieto-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 19:37:14 by lnieto-m          #+#    #+#             */
/*   Updated: 2016/01/03 19:34:32 by lnieto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			draw_segment(t_env *env, t_point a, t_point b)
{
	t_calc		calcul;

	calcul.e = b.x - a.x;
	calcul.dx = calcul.e * 2;
	calcul.dy = (b.y - a.y) * 2;
	if ((a.y > b.y) && ((b.x - a.x) < (a.y - b.y)))
		draw_segment_3(env, a, b);
	else if ((a.y < b.y) && ((b.x - a.x) < (b.y - a.y)))
		draw_segment_4(env, a, b);
	else if (a.y > b.y)
		draw_segment_2(env, a, b);
	else
		while (a.x <= b.x)
		{
			image_pixel_put(env, a, a.z);
			a.x++;
			if (a.z - b.z > 0)
				a.z = b.z;
			if ((calcul.e -= calcul.dy) <= 0)
			{
				a.y++;
				calcul.e += calcul.dx;
			}
		}
	image_pixel_put(env, b, b.z);
}
