/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnieto-m <lnieto-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/28 16:36:12 by lnieto-m          #+#    #+#             */
/*   Updated: 2016/01/07 17:33:33 by lnieto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		err(int ac)
{
	if (ac == 1)
	{
		ft_putendl_fd("ERROR : Fdf can not read the standard input.", 2);
		return (-1);
	}
	if (ac > 2)
	{
		ft_putendl_fd("ERROR : Fdf can take only 1 argument.", 2);
		return (-1);
	}
	return (0);
}

static void		def(t_env *e)
{
	e->hauteur = 10;
	e->hor = 20;
	e->ver = 10;
	e->end = 1;
	e->bpp = 8;
	e->height = 1200;
	e->width = 1800;
	e->x = e->width / 2;
	e->y = 150;
	e->list = ft_splitint(e->fd);
	e->err_return = ft_empty_map(e->list);
}

static void		del(t_env *e)
{
	close(e->fd);
	ft_delete_lst(e->list);
	exit(EXIT_FAILURE);
}

static void		fail_init(t_env *e)
{
	close(e->fd);
	ft_delete_lst(e->list);
	ft_putendl_fd("ERROR : initialisation failed.", 2);
	ft_putendl_fd("Check mlx_init(), mlx_new_window() and mlx_new_image().", 2);
	exit(EXIT_FAILURE);
}

int				main(int ac, char **av)
{
	t_env	e;

	if (err(ac) == -1)
		exit(EXIT_FAILURE);
	e.fd = open(av[1], O_RDONLY);
	if (e.fd < 0)
	{
		ft_putendl_fd("Bad file descriptor.", 2);
		exit(EXIT_FAILURE);
	}
	def(&e);
	if (ft_error_len(e.list) == -1)
		del(&e);
	if ((e.mlx = mlx_init()) == NULL
		|| (e.win = mlx_new_window(e.mlx, e.width, e.height, "Fdf")) == NULL
		|| (e.img = mlx_new_image(e.mlx, e.width, e.height)) == NULL)
		fail_init(&e);
	e.img_str = (int *)mlx_get_data_addr(e.img, &e.bpp, &e.width, &e.end);
	mlx_hook(e.win, 2, (1L << 0), key_p, &e);
	mlx_hook(e.win, 3, (1L << 1), key_r, &e);
	mlx_expose_hook(e.win, expose_hook, &e);
	mlx_loop(e.mlx);
	return (0);
}
