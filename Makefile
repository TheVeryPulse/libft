CC := gcc
SRC_DIR := ./src
INC_DIR := ./inc
LIB_DIR := ./lib
OBJ_DIR := ./build

CFLAGS := -Wall -Wextra -Werror -I $(INC_DIR) -g

FILES := \
	src/ctype/ft_isalnum.c \
	src/ctype/ft_isalpha.c \
	src/ctype/ft_isascii.c \
	src/ctype/ft_isdigit.c \
	src/ctype/ft_islower.c \
	src/ctype/ft_isprint.c \
	src/ctype/ft_isspace.c \
	src/ctype/ft_isupper.c \
	src/ctype/ft_isxdigit.c \
	src/ft_format_string_add_args.c \
	src/ft_format_string.c \
	src/ft_itoa.c \
	src/ft_putchar_fd.c \
	src/ft_putendl_fd.c \
	src/ft_putnbr_fd.c \
	src/ft_putstr_fd.c \
	src/ft_split.c \
	src/ft_striteri.c \
	src/ft_strjoin.c \
	src/ft_strmapi.c \
	src/ft_strtrim.c \
	src/ft_substr.c \
	src/get_next_line.c \
	src/get_next_line_utils.c \
	src/linked_list/ft_lstadd_back.c \
	src/linked_list/ft_lstadd_front.c \
	src/linked_list/ft_lstclear.c \
	src/linked_list/ft_lstdelone.c \
	src/linked_list/ft_lstiter.c \
	src/linked_list/ft_lstlast.c \
	src/linked_list/ft_lstmap.c \
	src/linked_list/ft_lstnew.c \
	src/linked_list/ft_lstsize.c \
	src/linked_list/ft_lst_test.c \
	src/stdio/ft_dprintf_part1.c \
	src/stdio/ft_dprintf_part2.c \
	src/stdio/ft_printf_all.c \
	src/stdio/ft_printf.c \
	src/stdio/ft_printf_c.c \
	src/stdio/ft_printf_d.c \
	src/stdio/ft_printf_p.c \
	src/stdio/ft_printf_s.c \
	src/stdio/ft_printf_u.c \
	src/stdio/ft_printf_x.c \
	src/stdlib/ft_abs.c \
	src/stdlib/ft_atof.c \
	src/stdlib/ft_atoi.c \
	src/stdlib/ft_calloc.c \
	src/string/ft_bzero.c \
	src/string/ft_memchr.c \
	src/string/ft_memcmp.c \
	src/string/ft_memcpy.c \
	src/string/ft_memmove.c \
	src/string/ft_memset.c \
	src/string/ft_strchr.c \
	src/string/ft_strdup.c \
	src/string/ft_strlcat.c \
	src/string/ft_strlcpy.c \
	src/string/ft_strlen.c \
	src/string/ft_strncmp.c \
	src/string/ft_strndup.c \
	src/string/ft_strnstr.c \
	src/string/ft_strrchr.c \
	src/string/ft_tolower.c \
	src/string/ft_toupper.c

OFILES := $(patsubst src/%.c, build/%.o, $(FILES))

NAME := $(LIB_DIR)/libft.a

# build object files and archive the static library
all: $(NAME)

# build the library with the required .o files
$(NAME): $(OFILES)
	@mkdir -p $(@D)
	@ar rcs $@ $(OFILES)
	@echo "\033[0;32m\n>>> $@\n\033[0m"

# build .o files from .c files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "\033[0;32m* $^\033[0m"

# remove all .o files
clean:
	rm -rf $(OBJ_DIR)

# remove static library as well as all .o files
fclean: clean
	rm -f $(NAME)

# remove all files, then rebuild the library
re: fclean all

# compile everything 
bonus: $(NAME) clean

.PHONY: all clean fclean re msg
