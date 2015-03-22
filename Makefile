##
## Makefile for wolf3d in /home/boulay_b/Rendu/MUL_2014_wolf3d
##
## Made by arnaud boulay
## Login   <boulay_b@epitech.net>
##
## Started on  Mon Dec 15 22:51:54 2014 arnaud boulay
## Last update Sun Jan  4 15:32:56 2015 arnaud boulay
##

NAME	= wolf3d

SRCSFO	= sources/

SRCS	= $(SRCSFO)main.c \
	  $(SRCSFO)my_pixel_put_to_image.c \
	  $(SRCSFO)gere.c \
	  $(SRCSFO)calc.c \
	  $(SRCSFO)draw.c \
	  $(SRCSFO)minimap.c \
	  $(SRCSFO)movement.c \
	  $(SRCSFO)menu.c \
	  $(SRCSFO)option.c \
	  $(SRCSFO)init.c \
	  $(SRCSFO)tools.c \
	  $(SRCSFO)texture.c

OBJS	= $(SRCS:.c=.o)

CFLAGS	= -Iinclude -I/usr/include/X11 -Wall -Wextra -Werror -O3

LDFLAGS	= -lm -L/usr/lib64/ -lXext -lX11 -lmlx_$(HOSTTYPE)

all: $(NAME)

$(NAME): $(OBJS)
	 cc -o $(NAME) $(OBJS) $(CFLAGS) $(LDFLAGS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
