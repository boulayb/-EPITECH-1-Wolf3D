/*
** texture.c for wolf3d in /home/boulay_b/Rendu/MUL_2014_wolf3d
**
** Made by arnaud boulay
** Login   <boulay_b@epitech.net>
**
** Started on  Mon Dec 22 15:48:51 2014 arnaud boulay
** Last update Tue Dec 30 11:57:29 2014 arnaud boulay
*/

#include <stdlib.h>
#include "mlx.h"
#include "my.h"

int		strlcpy(char *dest, char *src, int n)
{
  int		i;

  i = -1;
  while (src[++i] != '\0')
    if (i > n)
      dest[i] = src[i];
    else
      dest[i] = '\0';
  return (0);
}

unsigned int	get_top_pixel_color(t_struct *stru, int x, int y)
{
  t_color	coltab;
  int		i;
  int		o;
  int		c;

  o = (((y * stru->top->t_sizeline) - stru->top->t_sizeline) +
       (x * (stru->top->t_bpp / 8)));
  i = (o - (stru->top->t_bpp / 8)) - 1;
  c = -1;
  coltab.bgra[3] = 0;
  while (++i != o - 1)
    coltab.bgra[++c] = stru->top->t_data[i];
  return (coltab.color);
}

unsigned int	get_wall_pixel_color(t_struct *stru, int x, int y)
{
  t_color	coltab;
  int		i;
  int		o;
  int		c;

  o = (((y * stru->wall->w_sizeline) - stru->wall->w_sizeline) +
       (x * (stru->wall->w_bpp / 8)));
  i = (o - (stru->wall->w_bpp / 8)) - 1;
  c = -1;
  coltab.bgra[3] = 0;
  while (++i != o - 1)
    coltab.bgra[++c] = stru->wall->w_data[i];
  return (coltab.color);
}

unsigned int	get_floor_pixel_color(t_struct *stru, int x, int y)
{
  t_color	coltab;
  int		i;
  int		o;
  int		c;

  o = (((y * stru->floor->f_sizeline) - stru->floor->f_sizeline) +
       (x * (stru->floor->f_bpp / 8)));
  i = (o - (stru->floor->f_bpp / 8)) - 1;
  c = -1;
  coltab.bgra[3] = 0;
  while (++i != o - 1)
    coltab.bgra[++c] = stru->floor->f_data[i];
  return (coltab.color);
}

int		load_textures(t_struct *stru)
{
  if ((stru->top->t_img = mlx_xpm_file_to_image(stru->mlx->ptr, TEXTURE_TOP,
						&stru->top->t_x,
						&stru->top->t_y)) == NULL ||
      (stru->top->t_data = mlx_get_data_addr(stru->top->t_img,
					     &stru->top->t_bpp,
					     &stru->top->t_sizeline,
					     &stru->top->t_endian)) == NULL ||
      (stru->wall->w_img = mlx_xpm_file_to_image(stru->mlx->ptr, TEXTURE_WALL,
						 &stru->wall->w_x,
						 &stru->wall->w_y)) == NULL ||
      (stru->wall->w_data = mlx_get_data_addr(stru->wall->w_img,
					      &stru->wall->w_bpp,
					      &stru->wall->w_sizeline,
					      &stru->wall->w_endian)) == NULL ||
      (stru->floor->f_img = mlx_xpm_file_to_image(stru->mlx->ptr, TEXTURE_FLOOR,
						  &stru->floor->f_x,
						  &stru->floor->f_y)) == NULL ||
      (stru->floor->f_data = mlx_get_data_addr(stru->floor->f_img,
					       &stru->floor->f_bpp,
					       &stru->floor->f_sizeline,
					       &stru->floor->f_endian)) == NULL
      || (load_menu(stru) == -1))
    return (-1);
  return (0);
}
