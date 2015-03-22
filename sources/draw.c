/*
** draw.c for wolf3d in /home/boulay_b/Rendu/MUL_2014_wolf3d
**
** Made by arnaud boulay
** Login   <boulay_b@epitech.net>
**
 ** Started on  Thu Dec 18 16:17:30 2014 arnaud boulay
** Last update Sun Dec 28 02:52:02 2014 arnaud boulay
*/

#include "my.h"

void	draw_top(t_struct *stru, int x, int y)
{
  int	color;

  if (stru->menu->texture_mod == 1)
    {
      stru->top->t_v += 1;
      if (stru->top->t_v > stru->top->t_y)
	stru->top->t_v = 1;
      color = get_top_pixel_color(stru, stru->top->t_u, stru->top->t_v);
      my_pixel_put_to_image(stru->mlx, x, y, color);
    }
  else
    my_pixel_put_to_image(stru->mlx, x, y, TOP_COLOR);
}

void	draw_wall(t_struct *stru, int x, int y)
{
  int	color;

  if (stru->menu->texture_mod == 1)
    {
      stru->wall->w_v += 1;
      if (stru->wall->w_v > stru->wall->w_y)
	stru->wall->w_v = 1;
      color = get_wall_pixel_color(stru, stru->wall->w_u, stru->wall->w_v);
      my_pixel_put_to_image(stru->mlx, x, y, color);
    }
  else
    my_pixel_put_to_image(stru->mlx, x, y, WALL_COLOR);
}

void	draw_floor(t_struct *stru, int x, int y)
{
  int	color;

  if (stru->menu->texture_mod == 1)
    {
      stru->floor->f_v += 1;
      if (stru->floor->f_v > stru->floor->f_y)
	stru->floor->f_v = 1;
      color = get_floor_pixel_color(stru, stru->floor->f_u, stru->floor->f_v);
      my_pixel_put_to_image(stru->mlx, x, y, color);
    }
  else
    my_pixel_put_to_image(stru->mlx, x, y, FLOOR_COLOR);
}

void	draw_image(t_struct *stru, int x)
{
  int	y;

  y = 0;
  while (++y <= I_SIZE_Y)
    if (y <= (I_SIZE_Y - (stru->inter->dist)) / stru->player->angle_y)
      draw_top(stru, x, y);
    else if ((y > (I_SIZE_Y - (stru->inter->dist)) / stru->player->angle_y) &&
	     (y <= ((I_SIZE_Y - (stru->inter->dist)) / stru->player->angle_y) +
	      stru->inter->dist))
      draw_wall(stru, x, y);
    else
      draw_floor(stru, x, y);
}
