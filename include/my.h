/*
** my.h for wolf3d in /home/boulay_b/Work/minilibx/image
**
** Made by arnaud boulay
** Login   <boulay_b@epitech.net>
**
** Started on  Sun Nov 23 16:42:55 2014 arnaud boulay
** Last update Sun Jan  4 15:22:47 2015 arnaud boulay
*/

#ifndef	MY_H_
# define MY_H_

enum			e_key
  {
    SHIFT = 65505,
    ESCAPE = 65307,
    UP = 65362,
    DOWN = 65364,
    LEFT = 65361,
    RIGHT = 65363,
    KEY_M = 109,
    KEY_A = 97,
    KEY_Z = 122,
    KEY_S = 115,
    KEY_Q = 113,
    KEY_D = 100
  };

enum			e_size
  {
    W_SIZE_X = 800,
    W_SIZE_Y = 600,
    I_SIZE_X = 800,
    I_SIZE_Y = 600,
    M_SIZE_X = 19,
    M_SIZE_Y = 22
  };

enum			e_color
  {
    MINIMAP_PLAYER_COLOR = 0xFF0000,
    MINIMAP_TELEPORT_COLOR = 0x00FF00,
    MINIMAP_WALL_COLOR = 0x000000,
    MINIMAP_VOID_COLOR = 0xFFFFFF,
    WALL_COLOR = 0x606060,
    FLOOR_COLOR = 0x238341,
    TOP_COLOR = 0x198CFF,
  };

enum			e_player
  {
    P_SPAWN_X = 9,
    P_SPAWN_Y = 10
  };

#define TEXTURE_TOP	("./xpm/space2.xpm")
#define TEXTURE_WALL	("./xpm/tan_paper.xpm")
#define TEXTURE_FLOOR	("./xpm/grass.xpm")
#define TEXTURE_MENU	("./xpm/menu_base.xpm")
#define TEXTURE_OPTION	("./xpm/menu_option.xpm")
#define TEXTURE_GRAPHIC	("./xpm/menu_graphic.xpm")
#define TEXTURE_PLAYER	("./xpm/menu_player.xpm")
#define P_ANGLE_MAX_Y	((double)M_PI * 300 / 180)
#define P_ANGLE_MIN_Y	((double)M_PI * 60 / 180)
#define P_ANGLE_STRAF	((double)M_PI * 90 / 180)

extern int		g_map[M_SIZE_Y][M_SIZE_X];

typedef union		u_color
{
  unsigned int		color;
  unsigned char		bgra[sizeof(unsigned int)];
}			t_color;

typedef struct		s_mlx
{
  void			*ptr;
  void			*img;
  void			*window;
  char			*data;
  int			bpp;
  int			sizeline;
  int			endian;
}			t_mlx;

typedef struct		s_inter
{
  double		vdx;
  double		vdy;
  double		dist;
  double		wall_thick;
  double		anti_aliasing;
}			t_inter;

typedef struct		s_fov
{
  double		x1;
  double		y1;
  double		xr;
  double		yr;
  double		xf;
  double		yf;
}			t_fov;

typedef struct		s_movement
{
  char			forward;
  char			backward;
  char			left;
  char			right;
  char			angle_left;
  char			angle_right;
  char			angle_up;
  char			angle_down;
  char			running;
}			t_movement;

typedef struct		s_player
{
  double		x0;
  double		y0;
  double		angle_x;
  double		angle_y;
  double		speed;
  double		zoom;
  double		base_speed;
  double		run_speed;
  double		angle_speed;
}			t_player;

typedef struct		s_minimap
{
  int			map_x;
  int			map_y;
  int			map_size;
  char			disp_map;
}			t_minimap;

typedef struct		s_menu
{
  void			*base_img;
  void			*option_img;
  void			*graphic_img;
  void			*player_img;
  char			in_menu;
  char			in_option;
  char			in_graphic;
  char			in_player;
  char			texture_mod;
}			t_menu;

typedef struct		s_wall
{
  char			*w_data;
  void			*w_img;
  int			w_bpp;
  int			w_sizeline;
  int			w_endian;
  int			w_x;
  int			w_y;
  double		w_u;
  double		w_v;
}			t_wall;

typedef struct		s_top
{
  char			*t_data;
  void			*t_img;
  int			t_bpp;
  int			t_sizeline;
  int			t_endian;
  int			t_x;
  int			t_y;
  double		t_u;
  double		t_v;
}			t_top;

typedef struct		s_floor
{
  char			*f_data;
  void			*f_img;
  int			f_bpp;
  int			f_sizeline;
  int			f_endian;
  int			f_x;
  int			f_y;
  double		f_u;
  double		f_v;
}			t_floor;

typedef struct		s_struct
{
  struct s_mlx		*mlx;
  struct s_player	*player;
  struct s_fov		*fov;
  struct s_inter	*inter;
  struct s_movement	*movement;
  struct s_minimap	*minimap;
  struct s_menu		*menu;
  struct s_top		*top;
  struct s_floor	*floor;
  struct s_wall		*wall;
}			t_struct;

int			gere_expose(t_mlx *mlx);
int			gere_mouse(int button, int x, int y, t_struct *stru);
int			gere_key_released(int key, t_struct *stru);
int			gere_key_pressed(int key, t_struct *stru);
int			load_textures(t_struct *stru);
int			load_menu(t_struct *stru);
void			my_putstr(char *str);
void			translation(t_struct *stru);
void			rotation(t_struct *stru);
void			straf(t_struct *stru);
void			quit(t_struct *stru);
void			menu(t_struct *stru);
void			button_in_menu(t_struct *stru, int x, int y);
void			button_in_option(t_struct *stru, int x, int y);
void			button_in_player(t_struct *stru, int x, int y);
void			button_in_graphic(t_struct *stru, int x, int y);
void			option_in_player(t_struct *stru, int x, int y);
void			option_in_graphic(t_struct *stru, int x, int y);
void			calc_fov(t_struct *stru);
void			disp_minimap(t_struct *stru);
void			draw_image(t_struct *stru, int x);
void			draw_minimap(t_struct *stru);
void			init_menu(t_struct *stru);
void			init_option(t_struct *stru);
void			init_player(t_struct *stru);
void			init_texture(t_struct *stru);
void			my_pixel_put_to_image(t_mlx *mlx, int x, int y, unsigned int color);
unsigned int		get_top_pixel_color(t_struct *stru, int x, int y);
unsigned int		get_wall_pixel_color(t_struct *stru, int x, int y);
unsigned int		get_floor_pixel_color(t_struct *stru, int x, int y);

#endif /* !MY_H_ */
