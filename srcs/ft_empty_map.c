/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_empty_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnieto-m <lnieto-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 10:59:13 by lnieto-m          #+#    #+#             */
/*   Updated: 2016/01/05 11:49:39 by lnieto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				ft_empty_map(t_lst *list)
{
	int		i;
	int		j;
	t_lst	*tmp;

	i = 0;
	j = 0;
	tmp = list;
	if (tmp != NULL)
	{
		while (tmp->str[i] != NULL)
		{
			while (tmp->str[i][j] != 0)
			{
				if (tmp->str[i][j] != ' ' && tmp->str[i][j] != '\t'
					&& tmp->str[i][j] != '\n')
					return (0);
				j++;
			}
			j = 0;
			i++;
		}
		tmp = tmp->next;
	}
	ft_putendl("Warning : Your map is empty.");
	return (1);
}
