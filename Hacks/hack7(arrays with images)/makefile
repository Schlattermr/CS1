#
# makefile for image utilities C library
#

CC = gcc
FLAGS = -Wall --std=gnu99 -g 
INCLUDES = -lm

imageDriver: imageUtils.o imageDriver.c
	$(CC) $(FLAGS) imageUtils.o imageDriver.c -o imageDriver $(INCLUDES)

imageUtils.o: imageUtils.c imageUtils.h
	$(CC) $(FLAGS) -c imageUtils.c -o imageUtils.o $(INCLUDES)

clean:
	rm -f *~ *.o
