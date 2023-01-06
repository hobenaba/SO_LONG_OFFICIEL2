CC = cc 

CFLAGS = -Wall -Wextra -Werror 

SRCS = ft_check.c ft_dostrlen.c ft_mywindow.c so_long.c themap.c ft_which_image.c ft_which_pointer.c  ft_put_img.c ft_which_key.c \
		floodfill.c ft_find_player.c

NAME = so_long

OBJS = $(SRCS:.c=.o)

all : $(NAME)

libft/libft.a :
	make -C libft

$(NAME) : $(OBJS) libft/libft.a
	$(CC) $(CFLAGS)  $(SRCS) -o  $(NAME) -lmlx -framework OpenGL -framework AppKit libft/libft.a libft/ft_printf/libftprintf.a

clean : 
	rm -rf $(OBJS)
	make clean -C libft

fclean : clean
	rm -rf $(NAME) libft/libft.a libft/ft_printf/libftprintf.a

re : fclean all
