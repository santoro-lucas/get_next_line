SRC = get_next_line.c
CFLAGS = -Wall -Wextra -Werror

all: 
	$(CC) $(CFLAGS) $(SRC)

test: all
	./a.out
	$(RM) a.out