NAME = fractol
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I/usr/include -Imlx_linux -O3
PFLAGS = -Lmlx_linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o
RM = rm -f
AR = ar rcs
DIR_OBJ = obj
DIR_SRC = src
SOURCES = burningship.c \
          draw.c \
          julia.c \
          key_hooks.c \
		  main.c \
		  mandelbrot.c \
		  mouse_hooks.c \
		  utils.c \
		  tricorn.c
LIBFT = libft
MINLIBX = minilibx-linux
HEADER = inc
SRCS = $(addprefix $(DIR_SRC)/,$(SOURCES))
OBJS = $(addprefix $(DIR_OBJ)/,$(SOURCES:.c=.o))
NORM = norminette ./$(DIR_SRC) ./$(LIBFT) ./$(HEADER)
COLOUR_GREEN=\033[0;32m
COLOUR_RED=\033[0;31m
COLOUR_BLUE=\033[0;34m
COLOUR_END=\033[0m

all: $(NAME)
$(NAME): $(OBJS)
	@echo "$(COLOUR_BLUE)Creating libft.a and copying it to root directory.$(COLOUR_END)"
	@make -C $(LIBFT)
	@cp $(LIBFT)/libft.a .
	@echo "$(COLOUR_BLUE)Creating libmlx_Linux.a and copying it to root directory.$(COLOUR_END)"
	@make -C $(MINLIBX)
	@cp $(MINLIBX)/libmlx_Linux.a .
	@echo "$(COLOUR_BLUE)Creating $(NAME).$(COLOUR_END)"
	@$(CC) $(OBJS) libft.a libmlx_Linux.a $(PFLAGS) $(NAME)
	@echo "$(COLOUR_GREEN)$(NAME) created.$(COLOUR_END)"

$(DIR_OBJ)/%.o: $(DIR_SRC)/%.c
	@echo "Compiling $< into $@.\n"
	@mkdir -p $(DIR_OBJ)
	$(CC) $(CFLAGS) -I $(HEADER) -c $< -o $@
	@echo "$(COLOUR_GREEN)Compiled.$(COLOUR_END)"

clean:
	@echo "$(COLOUR_BLUE)Cleaning object files.$(COLOUR_END)"
	$(RM) -r $(DIR_OBJ)/*.o
	@echo "$(COLOUR_GREEN)Cleaned.$(COLOUR_END)"

fclean: clean
	@echo "$(COLOUR_BLUE)Cleaning object files, $(NAME) and libft.$(COLOUR_END)"
	$(RM) $(NAME) libft.a libmlx_Linux.a
	@make -C $(LIBFT) fclean
	@make -C $(MINLIBX) clean
	@echo "$(COLOUR_GREEN)Cleaned.$(COLOUR_END)"

re: fclean all

.PHONY: all clean fclean re
