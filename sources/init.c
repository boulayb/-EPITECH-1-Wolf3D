/*
** init.c for wolf3d in /home/boulay_b/Rendu/MUL_2014_wolf3d
**
** Made by arnaud boulay
** Login   <boulay_b@epitech.net>
**
** Started on  Fri Dec 26 18:49:48 2014 arnaud boulay
** Last update Sun Jan  4 15:24:38 2015 arnaud boulay
*/

#include <stdlib.h>
#include "mlx.h"
#include "my.h"

int	load_menu(t_struct *stru)
{
  int	x;
  int	y;

  if ((stru->menu->base_img =
       mlx_xpm_file_to_image(stru->mlx->ptr, TEXTURE_MENU, &x, &y)) == NULL ||
      (stru->menu->option_img =
       mlx_xpm_file_to_image(stru->mlx->ptr, TEXTURE_OPTION, &x, &y)) == NULL ||
      (stru->menu->graphic_img =
       mlx_xpm_file_to_image(stru->mlx->ptr, TEXTURE_GRAPHIC,
			     &x, &y)) == NULL ||
      (stru->menu->player_img =
       mlx_xpm_file_to_image(stru->mlx->ptr, TEXTURE_PLAYER, &x, &y)) == NULL)
    return (-1);
  return (0);
}

void	init_option(t_struct *stru)
{
  stru->minimap->disp_map = 1;
  stru->minimap->map_size = 7;
  stru->inter->wall_thick = 1;
  stru->inter->anti_aliasing = 0.001;
  stru->player->zoom = 0.5;
  stru->player->angle_speed = 0.02;
  stru->player->base_speed = 0.01;
  stru->player->run_speed = 0.03;
}

void	init_menu(t_struct *stru)
{
  stru->menu->in_menu = 0;
  stru->menu->in_option = 0;
  stru->menu->in_graphic = 0;
  stru->menu->in_player = 0;
  stru->menu->texture_mod = 0;
}

void	init_player(t_struct *stru)
{
  stru->player->x0 = P_SPAWN_X;
  stru->player->y0 = P_SPAWN_Y;
  stru->player->angle_x = 0;
  stru->player->angle_y = 2;
  stru->movement->running = 0;
  stru->movement->backward = 0;
  stru->movement->forward = 0;
  stru->movement->left = 0;
  stru->movement->right = 0;
  stru->movement->angle_down = 0;
  stru->movement->angle_up = 0;
  stru->movement->angle_left = 0;
  stru->movement->angle_right = 0;
}

void	init_texture(t_struct *stru)
{
  stru->top->t_u = 0;
  stru->top->t_v = 0;
  stru->wall->w_u = 0;
  stru->wall->w_v = 0;
  stru->floor->f_u = 0;
  stru->floor->f_v = 0;
}
