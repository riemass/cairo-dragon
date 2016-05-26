
all: main.c
	gcc main.c -o dragon_breath `pkg-config --cflags --libs cairo`
