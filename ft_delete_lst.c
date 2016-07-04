/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delete_lst.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnieto-m <lnieto-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/30 21:00:20 by lnieto-m          #+#    #+#             */
/*   Updated: 2016/01/01 16:54:44 by lnieto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_lst	*ft_delete_lst(t_lst *list)
{
	t_lst	*tmp;
	t_lst	*tmp_next;
	int		len;

	len = 0;
	tmp_next = NULL;
	tmp = list;
	while (tmp != NULL)
	{
		tmp_next = tmp->next;
		while (tmp->str[len] != NULL)
		{
			free(tmp->str[len]);
			len++;
		}
		free(tmp->str);
		free(tmp);
		len = 0;
		tmp = tmp_next;
	}
	return (NULL);
}
