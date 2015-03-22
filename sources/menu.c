/*
** menu.c for wolf3d in /home/boulay_b/Rendu/MUL_2014_wolf3d
**
** Made by arnaud boulay
** Login   <boulay_b@epitech.net>
**
** Started on  Sat Dec 27 13:51:35 2014 arnaud boulay
** Last update Sun Dec 28 23:01:22 2014 arnaud boulay
*/

#include "mlx.h"
#include "my.h"

void	button_in_graphic(t_struct *stru, int x, int y)
{
  if (x > 135 && x < 650 && y > 155 && y < 215)
    {
      if (stru->menu->texture_mod == 0)
	stru->menu->texture_mod = 1;
      else
	stru->menu->texture_mod = 0;
    }
  else if (x > 140 && x < 650 && y > 390 && y < 450)
    stru->menu->in_graphic = 0;
  option_in_graphic(stru, x, y);
}

void	button_in_player(t_struct *stru, int x, int y)
{
  if (x > 140 && x < 650 && y > 390 && y < 450)
    stru->menu->in_player = 0;
  option_in_player(stru, x, y);
}

void	button_in_option(t_struct *stru, int x, int y)
{
  if (x > 135 && x < 650 && y > 155 && y < 215)
    stru->menu->in_graphic = 1;
  else if (x > 140 && x < 650 && y > 265 && y < 330)
    stru->menu->in_player = 1;
  else if (x > 140 && x < 650 && y > 390 && y < 450)
    stru->menu->in_option = 0;
}

void	button_in_menu(t_struct *stru, int x, int y)
{
  if (x > 135 && x < 650 && y > 155 && y < 215)
    stru->menu->in_menu = 0;
  else if (x > 140 && x < 650 && y > 265 && y < 330)
    stru->menu->in_option = 1;
  else if (x > 140 && x < 650 && y > 390 && y < 450)
    quit(stru);
}

void	menu(t_struct *stru)
{
  if (stru->menu->in_graphic == 1)
    mlx_put_image_to_window(stru->mlx->ptr, stru->mlx->window, stru->menu->graphic_img, 100, 100);
  else if (stru->menu->in_player == 1)
    mlx_put_image_to_window(stru->mlx->ptr, stru->mlx->window, stru->menu->player_img, 100, 100);
  else if (stru->menu->in_option == 1)
    mlx_put_image_to_window(stru->mlx->ptr, stru->mlx->window, stru->menu->option_img, 100, 100);
  else if (stru->menu->in_menu == 1)
    mlx_put_image_to_window(stru->mlx->ptr, stru->mlx->window, stru->menu->base_img, 100, 100);
}
