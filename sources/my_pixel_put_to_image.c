/*
** my_pixel_put_to_image.c for my_pixel_put_to_image in /home/boulay_b/Work/minilibx/image
**
** Made by arnaud boulay
** Login   <boulay_b@epitech.net>
**
** Started on  Sun Nov 23 16:31:11 2014 arnaud boulay
** Last update Thu Dec 18 14:44:46 2014 arnaud boulay
*/

#include "my.h"

void		my_pixel_put_to_image(t_mlx *mlx, int x, int y, unsigned int color)
{
  t_color	coltab;
  int		i;
  int		o;

  coltab.color = color;
  o = (((y * mlx->sizeline) - mlx->sizeline) + (x * (mlx->bpp / 8)));
  i = (o - (mlx->bpp / 8)) - 1;
  while (++i != o)
    if (mlx->endian == 0)
      mlx->data[i] = coltab.bgra[(mlx->bpp / 8) - (o - i)];
    else if (mlx->endian == 1)
      mlx->data[i] = coltab.bgra[(o - i) - 1];
}
