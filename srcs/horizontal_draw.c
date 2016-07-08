/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   horizontal_draw.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnieto-m <lnieto-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 17:13:01 by lnieto-m          #+#    #+#             */
/*   Updated: 2016/01/06 17:13:03 by lnieto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		hor(t_point *now, t_point *then, t_env *e, t_lst *list)
{
	while (list->next != NULL)
	{
		now->y -= e->hauteur * ft_atoi(list->str[e->i]);
		now->z = (double)ft_atoi(list->str[e->i]) / 10;
		then->y -= e->hauteur * ft_atoi(list->next->str[e->i]);
		then->z = (double)ft_atoi(list->next->str[e->i]) / 10;
		draw_segment(e, *then, *now);
		now->y += e->hauteur * ft_atoi(list->str[e->i]);
		then->y += e->hauteur * ft_atoi(list->next->str[e->i]);
		now->x = then->x;
		now->y = then->y;
		then->x = now->x - e->hor;
		then->y = now->y + e->ver;
		list = list->next;
	}
}

void			horizontal_draw(t_env *e)
{
	t_point		now;
	t_point		then;
	t_lst		*tmp;

	e->i = 0;
	tmp = e->list;
	now.x = e->x;
	now.y = e->y;
	then.x = now.x - e->hor;
	then.y = now.y + e->ver;
	while (tmp->str[e->i] != NULL)
	{
		hor(&now, &then, e, tmp);
		e->x += e->hor;
		e->y += e->ver;
		now.x = e->x;
		now.y = e->y;
		then.x = now.x - e->hor;
		then.y = now.y + e->ver;
		tmp = e->list;
		e->i++;
	}
}
