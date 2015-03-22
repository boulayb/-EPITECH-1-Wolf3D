/*
** option.c for wolf3d in /home/boulay_b/Rendu/MUL_2014_wolf3d
**
** Made by arnaud boulay
** Login   <boulay_b@epitech.net>
**
** Started on  Sun Dec 28 22:58:40 2014 arnaud boulay
** Last update Sun Dec 28 23:02:50 2014 arnaud boulay
*/

#include "my.h"

void	option_in_graphic(t_struct *stru, int x, int y)
{
  if (x > 510 && x < 520 && y > 300 &&
      y < 310 && stru->minimap->map_size + 1 <= 10)
    ++stru->minimap->map_size;
  else if (x > 575 && x < 585 && y > 300 &&
	   y < 310 && stru->minimap->map_size - 1 >= 1)
    --stru->minimap->map_size;
  else if (x > 510 && x < 520 && y > 250 &&
	   y < 260 && stru->inter->wall_thick + 0.1 <= 2)
    stru->inter->wall_thick += 0.1;
  else if (x > 575 && x < 585 && y > 250 &&
	   y < 260 && stru->inter->wall_thick - 0.1 >= 0.5)
    stru->inter->wall_thick -= 0.1;
  else if (x > 510 && x < 520 && y > 350 &&
	   y < 360 && stru->inter->anti_aliasing + 0.005 <= 0.1)
    stru->inter->anti_aliasing += 0.005;
  else if (x > 575 && x < 585 && y > 350 &&
	   y < 360 && stru->inter->anti_aliasing - 0.005 >= 0.001)
    stru->inter->anti_aliasing -= 0.005;
}

void	option_in_player(t_struct *stru, int x, int y)
{
  if (x > 515 && x < 525 && y > 355 && y < 365 &&
      stru->player->zoom + 0.1 <= 1)
    stru->player->zoom += 0.1;
  else if (x > 565 && x < 575 && y > 355 && y < 365 &&
	   stru->player->zoom - 0.1 >= 0.1)
    stru->player->zoom -= 0.1;
  else if (x > 515 && x < 525 && y > 165 && y < 175 &&
	   stru->player->base_speed + 0.01 <= 0.1)
    stru->player->base_speed += 0.01;
  else if (x > 565 && x < 575 && y > 165 && y < 175 &&
	   stru->player->base_speed - 0.01 >= 0.01)
    stru->player->base_speed -= 0.01;
  else if (x > 515 && x < 525 && y > 230 && y < 240 &&
	   stru->player->run_speed + 0.01 <= 1)
    stru->player->run_speed += 0.01;
  else if (x > 565 && x < 575 && y > 230 && y < 240 &&
	   stru->player->run_speed - 0.01 >= 0.01)
    stru->player->run_speed -= 0.01;
  else if (x > 515 && x < 525 && y > 290 && y < 300 &&
	   stru->player->angle_speed + 0.01 <= 0.1)
    stru->player->angle_speed += 0.01;
  else if (x > 565 && x < 575 && y > 290 && y < 300 &&
	   stru->player->angle_speed - 0.01 >= 0.01)
    stru->player->angle_speed -= 0.01;
}
