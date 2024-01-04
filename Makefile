CC := gcc
SRC_DIR := ./src
INC_DIR := ./inc
LIB_DIR := ./lib
BIN_DIR := ./bin

CFLAGS := -Wall -Wextra -Werror -I $(INC_DIR)
FILE_NAMES := \
	ft_atoi.c \
	ft_bzero.c \
	ft_calloc.c \
	ft_isalnum.c \
	ft_isalpha.c \
	ft_isascii.c \
	ft_isdigit.c \
	ft_islower.c \
	ft_isprint.c \
	ft_isspace.c \
	ft_isupper.c \
	ft_itoa.c \
	ft_lstadd_front.c \
	ft_lstadd_back.c \
	ft_lstclear.c \
	ft_lstdelone.c \
	ft_lstiter.c \
	ft_lstlast.c \
	ft_lstmap.c \
	ft_lstnew.c \
	ft_lstsize.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_memset.c \
	ft_putchar_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \
	ft_putstr_fd.c \
	ft_split.c \
	ft_strchr.c \
	ft_strdup.c \
	ft_striteri.c \
	ft_strjoin.c \
	ft_strlcat.c \
	ft_strlcpy.c \
	ft_strlen.c \
	ft_strmapi.c \
	ft_strncmp.c \
	ft_strnstr.c \
	ft_strrchr.c \
	ft_strtrim.c \
	ft_substr.c \
	ft_tolower.c \
	ft_toupper.c \
	\
	ft_printf.c \
	ft_printf_all.c \
	ft_printf_c.c \
	ft_printf_s.c \
	ft_printf_p.c \
	ft_printf_d.c \
	ft_printf_u.c \
	ft_printf_x.c \
	ft_abs.c \
	\
	get_next_line.c \
	get_next_line_utils.c
SRC_FILES := $(addprefix $(SRC_DIR)/, $(FILE_NAMES))
OBJ_FILES := $(patsubst $(SRC_DIR)/%.c, $(BIN_DIR)/%.o, $(SRC_FILES))

NAME := $(LIB_DIR)/libft.a

# build object files and archive the static library
all: $(NAME)

# build the library with the required .o files
$(NAME): $(OBJ_FILES)
	@mkdir -p $(LIB_DIR)
	ar rcs $@ $^

# build .o files from .c files
$(BIN_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# remove all .o files
clean:
	rm -f $(BIN_DIR)/*.o

# remove static library as well as all .o files
fclean: clean
	rm -f $(NAME)

# remove all files, then rebuild the library
re: fclean all

# compile everything 
bonus: $(NAME) clean

.PHONY: all clean fclean re
