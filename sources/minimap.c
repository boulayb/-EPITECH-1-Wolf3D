/*
** minimap.c for wolf3d in /home/boulay_b/Rendu/MUL_2014_wolf3d
**
** Made by arnaud boulay
** Login   <boulay_b@epitech.net>
**
** Started on  Fri Dec 26 19:04:24 2014 arnaud boulay
** Last update Sun Jan  4 15:20:19 2015 arnaud boulay
*/

#include "my.h"

void		disp_minimap(t_struct *stru)
{
  if (stru->minimap->disp_map == 1)
    stru->minimap->disp_map = 0;
  else
    stru->minimap->disp_map = 1;
}

void		draw_minimap_square(t_struct *stru, int x, int y, int color)
{
  int		xtmp;
  int		ytmp;

  xtmp = x - 1;
  ytmp = y - 1;
  while (++ytmp < y + stru->minimap->map_size)
    {
      while (++xtmp < x + stru->minimap->map_size)
	my_pixel_put_to_image(stru->mlx, xtmp, ytmp, color);
      xtmp = x - 1;
    }
}

void		minimap_color(t_struct *stru, int x, int y)
{
  if (g_map[stru->minimap->map_y][stru->minimap->map_x] == 1)
    draw_minimap_square(stru, x, y, MINIMAP_WALL_COLOR);
  else if (g_map[stru->minimap->map_y][stru->minimap->map_x] == 2)
    draw_minimap_square(stru, x, y, MINIMAP_TELEPORT_COLOR);
  else if (stru->minimap->map_x == (int)stru->player->x0 &&
	   stru->minimap->map_y == (int)stru->player->y0)
    draw_minimap_square(stru, x, y, MINIMAP_PLAYER_COLOR);
  else
    draw_minimap_square(stru, x, y, MINIMAP_VOID_COLOR);
}

void		draw_minimap(t_struct *stru)
{
  int		x;
  int		y;

  stru->minimap->map_x = -1;
  stru->minimap->map_y = -1;
  x = 10;
  y = 10;
  while (++stru->minimap->map_y < M_SIZE_Y)
    {
      while (++stru->minimap->map_x < M_SIZE_X)
	{
	  minimap_color(stru, x, y);
	  x = x + stru->minimap->map_size;
	}
      stru->minimap->map_x = -1;
      x = 10;
      y = y + stru->minimap->map_size;
    }
}
