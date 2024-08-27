CC = gcc
CFLAGS = -Wall -Wextra -std=c11
LDFLAGS = -lflint

SRC = hppk_encryption.c
OBJ = $(SRC:.c=.o)
HEADERS = hppk_encryption.h

TARGET = libencrypt.so

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(TARGET) $(LDFLAGS)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)
