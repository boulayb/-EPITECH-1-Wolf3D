/*
** gere.c for wolf3d in /home/boulay_b/Rendu/MUL_2014_wolf3d/sources
**
** Made by arnaud boulay
** Login   <boulay_b@epitech.net>
**
** Started on  Mon Dec 15 23:21:14 2014 arnaud boulay
** Last update Sun Jan  4 15:19:18 2015 arnaud boulay
*/

#include "mlx.h"
#include "my.h"

int	gere_expose(t_mlx *mlx)
{
  mlx_put_image_to_window(mlx->ptr, mlx->window, mlx->img, 0, 0);
  return (0);
}

int	gere_mouse(int button, int x, int y, t_struct *stru)
{
  if (button == 1)
    {
      if (stru->menu->in_graphic == 1)
	button_in_graphic(stru, x, y);
      else if (stru->menu->in_player == 1)
	button_in_player(stru, x, y);
      else if (stru->menu->in_option == 1)
	button_in_option(stru, x, y);
      else if (stru->menu->in_menu == 1)
	button_in_menu(stru, x, y);
    }
  return (0);
}

int	gere_key_pressed(int key, t_struct *stru)
{
  if (key == ESCAPE)
    stru->menu->in_menu = 1;
  else if (key == SHIFT)
    stru->movement->running = 1;
  else if (key == KEY_S)
    stru->movement->backward = 1;
  else if (key == KEY_Z)
    stru->movement->forward = 1;
  else if (key == KEY_Q)
    stru->movement->left = 1;
  else if (key == KEY_D)
    stru->movement->right = 1;
  else if (key == DOWN)
    stru->movement->angle_down = 1;
  else if (key == UP)
    stru->movement->angle_up = 1;
  else if (key == LEFT)
    stru->movement->angle_left = 1;
  else if (key == RIGHT)
    stru->movement->angle_right = 1;
  else if (key == KEY_A)
    stru->player->angle_y = 2;
  else if (key == KEY_M)
    disp_minimap(stru);
  return (0);
}

int	gere_key_released(int key, t_struct *stru)
{
  if (key == SHIFT)
    stru->movement->running = 0;
  else if (key == KEY_S)
    stru->movement->backward = 0;
  else if (key == KEY_Z)
    stru->movement->forward = 0;
  else if (key == KEY_Q)
    stru->movement->left = 0;
  else if (key == KEY_D)
    stru->movement->right = 0;
  else if (key == DOWN)
    stru->movement->angle_down = 0;
  else if (key == UP)
    stru->movement->angle_up = 0;
  else if (key == LEFT)
    stru->movement->angle_left = 0;
  else if (key == RIGHT)
    stru->movement->angle_right = 0;
  return (0);
}
