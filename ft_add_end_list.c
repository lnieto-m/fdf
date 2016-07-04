/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_end_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnieto-m <lnieto-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/28 19:49:31 by lnieto-m          #+#    #+#             */
/*   Updated: 2015/12/28 20:18:03 by lnieto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_lst		*ft_add_end_list(t_lst *lst, char **str)
{
	t_lst	*new_elem;
	t_lst	*tmp;

	tmp = lst;
	if (!(new_elem = (t_lst *)malloc(sizeof(t_lst))))
		return (NULL);
	new_elem->str = str;
	new_elem->next = NULL;
	if (lst == NULL)
		return (new_elem);
	else
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new_elem;
	}
	return (lst);
}
