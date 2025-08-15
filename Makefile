CC = gcc
CFLAGS = -Wall -Wextra -std=c99
TARGET = caesar
SRC = src/main.c src/Methods/caesar.c

.PHONY: all clean run

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)
