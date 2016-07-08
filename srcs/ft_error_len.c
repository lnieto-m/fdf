/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_len.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnieto-m <lnieto-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/01 17:15:10 by lnieto-m          #+#    #+#             */
/*   Updated: 2016/01/05 14:37:30 by lnieto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		print_error(void)
{
	ft_putendl_fd("ERROR : Map not formatted correctly.", 2);
	ft_putendl_fd("        Your map must be rectangular.", 2);
}

int				ft_error_len(t_lst *list)
{
	int		len;
	int		len_2;
	t_lst	*tmp;

	tmp = list;
	len = 0;
	len_2 = 0;
	while (tmp && tmp->next != NULL)
	{
		while (tmp->str[len] != NULL)
			len++;
		while (tmp->next->str[len_2] != NULL)
			len_2++;
		if (len != len_2)
		{
			print_error();
			return (-1);
		}
		len = 0;
		len_2 = 0;
		tmp = tmp->next;
	}
	return (0);
}
