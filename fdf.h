/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnieto-m <lnieto-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 19:32:26 by lnieto-m          #+#    #+#             */
/*   Updated: 2016/01/07 17:33:40 by lnieto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <math.h>
# include <fcntl.h>
# include <unistd.h>
# include "libft.h"
# define RGB(r, g, b)(256 * 256 * (int)(r) + 256 * (int)(g) + (int)(b))

typedef struct		s_lst
{
	char			**str;
	struct s_lst	*next;
}					t_lst;

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	void			*img;
	int				*img_str;
	int				bpp;
	int				end;
	int				width;
	int				height;
	int				i;
	int				hauteur;
	int				hor;
	int				ver;
	int				x;
	int				y;
	int				x_2;
	int				y_2;
	int				color;
	int				fd;
	int				err_return;
	t_lst			*list;
}					t_env;

typedef struct		s_point
{
	int				x;
	int				y;
	double			z;
}					t_point;

typedef struct		s_calc
{
	int				e;
	int				dx;
	int				dy;
}					t_calc;

t_lst				*ft_add_end_list(t_lst *list, char **str);
t_lst				*ft_delete_lst(t_lst *list);
void				draw_segment(t_env *e, t_point a, t_point b);
void				draw_segment_2(t_env *e, t_point a, t_point b);
void				draw_segment_3(t_env *e, t_point a, t_point b);
void				draw_segment_4(t_env *e, t_point a, t_point b);
void				horizontal_draw(t_env *e);
void				vertical_draw(t_env *e);
void				image_pixel_put(t_env *e, t_point a, double z);
int					expose_hook(t_env *e);
int					key_p(int keycode, t_env *e);
int					key_r(int keycode, t_env *e);
int					ft_error_len(t_lst *list);
int					ft_error_char(t_lst *list);
int					which_sens(double z1, double z2);
int					ft_empty_map(t_lst *list);
int					ft_fd(int fd);
t_lst				*ft_splitint(int const fd);

#endif
