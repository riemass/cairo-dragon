CC=gcc
CFLAGS=$(shell pkg-config --cflags --libs cairo)

all: main.c
	$(CC) main.c $(CFLAGS) -o dragon_curve
