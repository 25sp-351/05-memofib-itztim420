CC = gcc
CFLAGS = -Wall -std=c99

TARGET = fibo

SRC = cache.c main.c

OBJ = $(SRC:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)

run: $(TARGET)
	./$(TARGET) 10

.PHONY: all clean run