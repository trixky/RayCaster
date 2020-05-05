NAME = ray_caster

MK = make

MN = miniLibX

OPT = -lm -lmlx -framework OpenGL -framework AppKit

SRCS =	./srcs/bmp.c\
		./srcs/build_frame.c\
		./srcs/build_frame_if.c\
		./srcs/build_frame_x.c\
		./srcs/build_frame_y.c\
		./srcs/close.c\
		./srcs/close_tools.c\
		./srcs/ft_set_line_map.c\
		./srcs/generate_ray_obj.c\
		./srcs/generate_ray_obj_x_object.c\
		./srcs/generate_ray_obj_x_object_dir.c\
		./srcs/generate_ray_obj_y_object.c\
		./srcs/generate_ray_obj_y_object_dir.c\
		./srcs/generate_ray_wall.c\
		./srcs/get_next_line.c\
		./srcs/get_next_line_utils.c\
		./srcs/gun.c\
		./srcs/key_hook.c\
		./srcs/lstadd_front.c\
		./srcs/lstclear.c\
		./srcs/lstnew.c\
		./srcs/main.c\
		./srcs/parser.c\
		./srcs/parser_tools_1.c\
		./srcs/parser_tools_2.c\
		./srcs/parser_tools_3.c\
		./srcs/parser_tools_4.c\
		./srcs/parser_tools_5.c\
		./srcs/start_check.c\
		./srcs/start_init.c\
		./srcs/tools_1.c\
		./srcs/tools_2.c\
		./srcs/tools_3.c\
		./srcs/tools_4.c\
		./srcs/vie.c\
		./srcs/infinit.c

OBJECTS = $(SRCS:.c=.o)

FLAGS = -Wall -Wextra -Werror

CC = gcc

all : $(NAME)

%.o:%.c
	$(CC) $(FLAGS) -c $< -o $@

$(NAME) : $(OBJECTS)
	$(MK) -C $(MN)
	$(CC) $(FLAGS) $(OPT) $(SRCS) -o $@

.PHONY : clean all fclean re bonus

clean : 
	rm -f $(OBJECTS)
	$(MK) clean -C $(MN)

fclean : clean
	rm -f $(NAME)

re : fclean all
