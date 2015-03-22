/*
** calc.c for wolf3d in /home/boulay_b/Rendu/MUL_2014_wolf3d
**
** Made by arnaud boulay
** Login   <boulay_b@epitech.net>
**
** Started on  Thu Dec 18 16:17:18 2014 arnaud boulay
** Last update Thu Jan  1 04:31:52 2015 arnaud boulay
*/

#include <math.h>
#include "my.h"

void		calc_intersection(t_struct *stru)
{
  double	k;
  int		x;
  int		y;

  k = 0.5;
  stru->inter->vdx = stru->fov->xf - stru->player->x0;
  stru->inter->vdy = stru->fov->yf - stru->player->y0;
  y = stru->player->y0 + (k * stru->inter->vdy);
  x = stru->player->x0 + (k * stru->inter->vdx);
  while (g_map[y][x] == 0)
    {
      y = stru->player->y0 + (k * stru->inter->vdy);
      x = stru->player->x0 + (k * stru->inter->vdx);
      k = k + stru->inter->anti_aliasing;
    }
  stru->inter->dist = I_SIZE_Y / (stru->inter->wall_thick * k);
}

void		calc_fov(t_struct *stru)
{
  double	x;

  x = 0;
  while (++x <= I_SIZE_X)
    {
      stru->top->t_u += 1;
      if (stru->top->t_u > stru->top->t_x)
	stru->top->t_u = 1;
      stru->wall->w_u += 1;
      if (stru->wall->w_u > stru->wall->w_x)
	stru->wall->w_u = 1;
      stru->floor->f_u += 1;
      if (stru->floor->f_u > stru->floor->f_x)
	stru->floor->f_u = 1;
      stru->fov->x1 = stru->player->zoom;
      stru->fov->y1 = (1 * ((I_SIZE_X / 2) - x)) / I_SIZE_X;
      stru->fov->xr = (stru->fov->x1 * cos(stru->player->angle_x)) -
	(stru->fov->y1 * sin(stru->player->angle_x));
      stru->fov->yr = (stru->fov->x1 * sin(stru->player->angle_x)) +
	(stru->fov->y1 * cos(stru->player->angle_x));
      stru->fov->xf = stru->fov->xr + stru->player->x0;
      stru->fov->yf = stru->fov->yr + stru->player->y0;
      calc_intersection(stru);
      draw_image(stru, x);
    }
}
