# Calculadora integrales y derivadas enfocadas a polinomios

CC = gcc
CFLAGS = -Wall -Wextra -lm

TARGET = calculadora

SOURCES = main.c polinomio.c parser.c

OBJECTS = $(SOURCES:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJECTS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TARGET)

clean-o:
	rm -f $(OBJECTS)
