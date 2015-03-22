/*
** movement.c for wolf3d in /home/boulay_b/Rendu/MUL_2014_wolf3d
**
** Made by arnaud boulay
** Login   <boulay_b@epitech.net>
**
** Started on  Fri Dec 19 17:56:49 2014 arnaud boulay
** Last update Thu Jan  1 04:51:00 2015 arnaud boulay
*/

#include <math.h>
#include "my.h"

void	teleportation(t_struct *stru)
{
  if ((int)stru->player->x0 == 0 && (int)stru->player->y0 == 10)
    stru->player->x0 = 17;
  else if ((int)stru->player->x0 == 18 && (int)stru->player->y0 == 10)
    stru->player->x0 = 1;
}

void	translation(t_struct *stru)
{
  if (stru->movement->running == 1)
    stru->player->speed = stru->player->run_speed;
  if (stru->movement->backward == 1 &&
      g_map[(int)(stru->player->y0 - sin(stru->player->angle_x) *
		  stru->player->speed)]
      [(int)(stru->player->x0 - cos(stru->player->angle_x) *
	     stru->player->speed)] != 1)
    {
      teleportation(stru);
      stru->player->x0 -= cos(stru->player->angle_x) * stru->player->speed;
      stru->player->y0 -= sin(stru->player->angle_x) * stru->player->speed;
    }
  if (stru->movement->forward == 1 &&
      g_map[(int)(stru->player->y0 + sin(stru->player->angle_x) *
		  stru->player->speed)]
      [(int)(stru->player->x0 + cos(stru->player->angle_x) *
	     stru->player->speed)] != 1)
    {
      teleportation(stru);
      stru->player->x0 += cos(stru->player->angle_x) * stru->player->speed;
      stru->player->y0 += sin(stru->player->angle_x) * stru->player->speed;
    }
}

void	straf(t_struct *stru)
{
  stru->player->angle_x += P_ANGLE_STRAF;
  if ((stru->movement->left == 1) &&
      (g_map[(int)(stru->player->y0 + sin(stru->player->angle_x) *
		   stru->player->speed)]
       [(int)(stru->player->x0 + cos(stru->player->angle_x) *
	      stru->player->speed)] != 1))
    {
      teleportation(stru);
      stru->player->x0 += cos(stru->player->angle_x) * stru->player->speed;
      stru->player->y0 += sin(stru->player->angle_x) * stru->player->speed;
    }
  stru->player->angle_x -= P_ANGLE_STRAF;
  stru->player->angle_x -= P_ANGLE_STRAF;
  if (stru->movement->right == 1 &&
      (g_map[(int)(stru->player->y0 + sin(stru->player->angle_x) *
		   stru->player->speed)]
       [(int)(stru->player->x0 + cos(stru->player->angle_x) *
	      stru->player->speed)] != 1))
    {
      teleportation(stru);
      stru->player->x0 += cos(stru->player->angle_x) * stru->player->speed;
      stru->player->y0 += sin(stru->player->angle_x) * stru->player->speed;
    }
  stru->player->angle_x += P_ANGLE_STRAF;
}

void	rotation(t_struct *stru)
{
  if (stru->movement->angle_down == 1 && stru->player->angle_y < P_ANGLE_MAX_Y)
    stru->player->angle_y += stru->player->angle_speed;
  if (stru->movement->angle_up == 1 && stru->player->angle_y > P_ANGLE_MIN_Y)
    stru->player->angle_y -= stru->player->angle_speed;
  if (stru->movement->angle_left == 1)
    stru->player->angle_x += stru->player->angle_speed;
  if (stru->movement->angle_right == 1)
    stru->player->angle_x -= stru->player->angle_speed;
  if (stru->player->angle_x > 6.2)
    stru->player->angle_x = 0;
  if (stru->player->angle_x < 0)
    stru->player->angle_x = 6.2;
}
