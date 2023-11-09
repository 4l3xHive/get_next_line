SRCS = $(wildcard *.c)
FLAGS = -Wall -Wextra -Werror -D BUFFER_SIZE=42
all: $(SRCS)
        gcc $^ -o test -I.