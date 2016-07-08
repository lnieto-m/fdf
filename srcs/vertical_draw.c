/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertical_draw.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnieto-m <lnieto-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 17:09:59 by lnieto-m          #+#    #+#             */
/*   Updated: 2016/01/06 17:10:01 by lnieto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		vert(t_point *a, t_point *b, t_env *e, t_lst *list)
{
	int		i;

	i = 0;
	while (list->str[i + 1] != NULL)
	{
		a->y -= e->hauteur * ft_atoi(list->str[i]);
		a->z = (double)ft_atoi(list->str[i]) / 10;
		b->y -= e->hauteur * ft_atoi(list->str[i + 1]);
		b->z = (double)ft_atoi(list->str[i + 1]) / 10;
		draw_segment(e, *a, *b);
		a->y += e->hauteur * ft_atoi(list->str[i]);
		b->y += e->hauteur * ft_atoi(list->str[i + 1]);
		a->x = b->x;
		a->y = b->y;
		b->x = a->x + e->hor;
		b->y = a->y + e->ver;
		i++;
	}
}

void			vertical_draw(t_env *e)
{
	t_point		actual_point;
	t_point		forward_point;
	t_lst		*tmp;

	tmp = e->list;
	actual_point.x = e->x;
	actual_point.y = e->y;
	forward_point.x = actual_point.x + e->hor;
	forward_point.y = actual_point.y + e->ver;
	while (tmp != NULL)
	{
		vert(&actual_point, &forward_point, e, tmp);
		e->x -= e->hor;
		e->y += e->ver;
		actual_point.x = e->x;
		actual_point.y = e->y;
		forward_point.x = actual_point.x + e->hor;
		forward_point.y = actual_point.y + e->ver;
		tmp = tmp->next;
	}
}
