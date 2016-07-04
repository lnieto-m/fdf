/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_p.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnieto-m <lnieto-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 17:40:39 by lnieto-m          #+#    #+#             */
/*   Updated: 2016/01/06 19:26:48 by lnieto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		key_p_second(t_env *e, int keycode)
{
	if (keycode == 69)
	{
		e->hor *= 2;
		e->ver *= 2;
		e->hauteur *= 2;
	}
	if (keycode == 78 && e->hor > 1 && e->ver > 1)
	{
		e->hor /= 2;
		e->ver /= 2;
		e->hauteur /= 2;
	}
}

int				key_p(int keycode, t_env *e)
{
	if (keycode == 126 || keycode == 123 || keycode == 125 || keycode == 124
		|| keycode == 69 || keycode == 78)
	{
		ft_bzero(e->img_str, e->height * e->width);
		if (keycode == 126)
			e->y += 7;
		if (keycode == 123)
			e->x += 7;
		if (keycode == 125)
			e->y -= 7;
		if (keycode == 124)
			e->x -= 7;
		key_p_second(e, keycode);
	}
	expose_hook(e);
	return (0);
}
