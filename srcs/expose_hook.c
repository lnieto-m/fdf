/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expose_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnieto-m <lnieto-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/28 16:24:51 by lnieto-m          #+#    #+#             */
/*   Updated: 2016/01/05 17:57:41 by lnieto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		expose_hook(t_env *e)
{
	t_point		a;

	a.x = e->x;
	a.y = 150;
	e->x_2 = e->x;
	e->y_2 = e->y;
	if (e->list != NULL && e->list->next == NULL && e->list->str[0] != NULL
		&& e->list->str[1] == NULL)
	{
		a.y += ft_atoi(e->list->str[0]);
		image_pixel_put(e, a, (double)ft_atoi(e->list->str[0]) / 10);
	}
	else if (e->err_return == 0)
	{
		vertical_draw(e);
		e->x = e->x_2;
		e->y = e->y_2;
		horizontal_draw(e);
	}
	e->x = e->x_2;
	e->y = e->y_2;
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	return (0);
}
