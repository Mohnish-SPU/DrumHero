#MakeFile
#

CC = gcc
LDFLAGS =-lm
CFLAGS =-g

all:
	$(CC) main.c -o DrumHero `pkg-config --cflags --libs gtk+-2.0` -lsong -lm -lpthread

.PHONY:clean

clean:
	rm -rf DrumHero
	rm -rf *.o
