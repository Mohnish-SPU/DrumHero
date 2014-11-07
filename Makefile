#MakeFile
#

CC = gcc
LDFLAGS = `pkg-config --cflags --libs gtk+-2.0` -lsong -lm -lpthread
CFLAGS = -g

all:
	$(CC) main.c -o main `pkg-config --cflags --libs gtk+-2.0` -lsong -lm -lpthread

#main: main.o graphics.o
#	$(CC) $(LDFLAGS) main.c -o $@

#main.o: main.c graphics.h
#	$(CC) -c $(CFLAGS) $< -o $@ $(LDFLAGS)

#graphics.o:graphics.h graphics.c
#	$(CC) -c $(CFLAGS) $< -o $@ $(LDFLAGS)
	
.PHONY:clean

clean:
	rm -rf main
	rm -rf *.o
