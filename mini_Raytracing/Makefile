NAME =			miniRT

LIB =	./includes/

D_SRCS =		./srcs/

D_OBJS =		./

LIBMLX =		libmlx.dylib \
				libmlx.a


SRC  =  main.c \
				raytracing/rendering.c\
				vector/vector.c\
				vector/vector2.c\
				vector/vector3.c\
				colors/colors.c\
				colors/colors2.c\
				colors/colors3.c\
				colors/colors4.c\
				parsing/parse_aux.c \
				parsing/parsing.c\
				parsing/parsing2.c\
				parsing/parse.c\
				parsing/parse2.c\
				parsing/parse3.c\
				gnl/get_next_line.c\
				gnl/get_next_line_utils.c\
				camera/camera.c\
				camera/checkCam.c\
				camera/config.c\
				camera/rotation.c\
				intersections/intersections.c\
				intersections/int_spheres.c\
				intersections/int_plans.c\
				intersections/int_squares.c\
				intersections/int_triangles.c\
				intersections/int_cylinders.c\
				light/illumination.c\
				utils/error.c\
				utils/no_leak.c\
				utils/ft_strtod.c\
				utils/image_bmp.c\

GCC =			gcc

FRAM = 			libmlx.a libmlx.dylib libft.a -framework OpenGL -framework AppKit

SANITIZE =		-fsanitize=address

FLAGS =			-Wall -Wextra -Werror

RM =			rm -rf
				
SRCS =			$(addprefix $(D_SRCS), $(SRC))

COMPIL =		$(FLAGS) $(SANITIZE)

OBJS =			$(SRCS:.c=.o)

all:			$(NAME)

$(NAME) :		$(OBJS)
				@make -C ./minilibx_mms
				@make -C ./minilibx_opengl
				@make -C ./libft
				@cp ./minilibx_mms/libmlx.dylib libmlx.dylib
				@cp ./minilibx_opengl/libmlx.a libmlx.a
				@cp ./libft/libft.a libft.a
				$(GCC) $(COMPIL) -I $(LIB) $(FRAM) $(OBJS) -o $(NAME)

%.o: %.c
				@gcc $(FLAGS) -I $(LIB) -c $< -o $@

bonus:

norm:
				norminette $(D_SRCS)
				norminette $(LIB)

clean:
				$(RM) $(OBJS)

fclean:			clean
				@make clean -C ./minilibx_mms
				@make clean -C ./minilibx_opengl
				@make clean -C ./libft
				$(RM) libmlx.dylib
				$(RM) libmlx.a
				$(RM) libft.a
				$(RM) $(NAME)

re:				fclean all

.PHONY:			all, clean, fclean, re, bonus
