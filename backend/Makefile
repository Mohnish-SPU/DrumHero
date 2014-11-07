#MakeFile
#

CC = gcc

all:
	$(CC) -Wall PageOne.c -o PageOne `pkg-config --cflags --libs gtk+-2.0` -lsong -lm 

.PHONY:clean

clean:
	rm -rf PageOne
	rm -rf *.o
