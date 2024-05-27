CC = gcc
CFLAGS = -Wall -Wextra -Werror -pedantic -std=c99 -g
SOURCES = main.c queue.c queue_helpers.c
OBJECTS = $(SOURCES:.c=.o)
TARGET = queue

.PHONY: clean

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJECTS) $(LFLAGS) $(LIBS)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(TARGET) $(OBJECTS)