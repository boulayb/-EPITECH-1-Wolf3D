/*
** main.c for wolf3d in /home/boulay_b/Rendu/MUL_2014_wolf3d/sources
**
** Made by arnaud boulay
** Login   <boulay_b@epitech.net>
**
** Started on  Mon Dec 15 22:59:29 2014 arnaud boulay
** Last update Sun Jan  4 15:24:18 2015 arnaud boulay
*/

#include <X11/X.h>
#include <stdlib.h>
#include "mlx.h"
#include "my.h"

int		g_map[M_SIZE_Y][M_SIZE_X] =
  {{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
   {1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
   {1, 0, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 0, 1},
   {1, 0, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 0, 1},
   {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
   {1, 0, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 0, 1},
   {1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1},
   {1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1},
   {1, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1, 1},
   {1, 1, 1, 1, 0, 1, 0, 1, 1, 0, 1, 1, 0, 1, 0, 1, 1, 1, 1},
   {2, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 2},
   {1, 1, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 1, 1, 1},
   {1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1},
   {1, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1, 1},
   {1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1},
   {1, 0, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 0, 1},
   {1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1},
   {1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1},
   {1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1},
   {1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1},
   {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};

void		quit(t_struct *stru)
{
  mlx_destroy_window(stru->mlx->ptr, stru->mlx->window);
  free(stru);
  exit(0);
}

int		initialize(t_struct *stru)
{
  if (((stru->fov = malloc(sizeof(t_fov))) == NULL) ||
      ((stru->player = malloc(sizeof(t_player))) == NULL) ||
      ((stru->movement = malloc(sizeof(t_movement))) == NULL) ||
      ((stru->minimap = malloc(sizeof(t_minimap))) == NULL) ||
      ((stru->menu = malloc(sizeof(t_menu))) == NULL) ||
      ((stru->top = malloc(sizeof(t_top))) == NULL) ||
      ((stru->wall = malloc(sizeof(t_wall))) == NULL) ||
      ((stru->floor = malloc(sizeof(t_floor))) == NULL) ||
      ((stru->inter = malloc(sizeof(t_inter))) == NULL) ||
      ((stru->mlx = malloc(sizeof(t_mlx))) == NULL) ||
      ((stru->mlx->ptr = mlx_init()) == NULL) ||
      ((stru->mlx->img = mlx_new_image(stru->mlx->ptr,
				       I_SIZE_X, I_SIZE_Y)) == NULL) ||
      ((stru->mlx->data = mlx_get_data_addr(stru->mlx->img, &stru->mlx->bpp,
					    &stru->mlx->sizeline,
					    &stru->mlx->endian)) == NULL) ||
      ((stru->mlx->window = mlx_new_window(stru->mlx->ptr, W_SIZE_X, W_SIZE_Y,
					   "Wolf3d")) == NULL))
    return (-1);
  return (0);
}

int		wolf3d_core(t_struct *stru)
{
  if (stru->menu->in_menu == 0)
    {
      stru->player->speed = stru->player->base_speed;
      init_texture(stru);
      translation(stru);
      rotation(stru);
      straf(stru);
      calc_fov(stru);
      if (stru->minimap->disp_map == 1)
	draw_minimap(stru);
      mlx_put_image_to_window(stru->mlx->ptr, stru->mlx->window, stru->mlx->img,
			      0, 0);
    }
  else
    menu(stru);
  return (0);
}

void		wolf3d(t_struct *stru)
{
  init_option(stru);
  init_menu(stru);
  init_player(stru);
  mlx_expose_hook(stru->mlx->window, gere_expose, stru->mlx);
  mlx_hook(stru->mlx->window, KeyPress, KeyPressMask, gere_key_pressed, stru);
  mlx_hook(stru->mlx->window, KeyRelease, KeyReleaseMask, gere_key_released,
	   stru);
  mlx_mouse_hook(stru->mlx->window, gere_mouse, stru);
  mlx_loop_hook(stru->mlx->ptr, wolf3d_core, stru);
  mlx_loop(stru->mlx->ptr);
}

int		main(void)
{
  t_struct	*stru;

  if (((stru = malloc(sizeof(t_struct))) == NULL) || (initialize(stru) == -1) ||
      (load_textures(stru) == -1))
    {
      my_putstr("Error: Malloc or mlx failed.\n");
      return (-1);
    }
  wolf3d(stru);
  return (0);
}
