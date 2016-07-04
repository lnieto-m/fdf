/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnieto-m <lnieto-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/28 16:53:59 by lnieto-m          #+#    #+#             */
/*   Updated: 2016/01/02 14:13:15 by lnieto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

t_lst		*ft_splitint(int const fd)
{
	t_lst	*list;
	char	*gnl_ret;
	int		i;

	list = NULL;
	i = 0;
	while (get_next_line(fd, &gnl_ret) > 0)
	{
		list = ft_add_end_list(list, ft_strsplit(gnl_ret, ' '));
		free(gnl_ret);
	}
	return (list);
}
