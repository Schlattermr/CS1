#
# makefile for image and color utilities C library
#
#

CC = gcc -std=gnu99
FLAGS = -Wall
INCLUDES = -lm

imageDriver: imageUtils.o colorUtils.o imageDriver.c
	$(CC) $(FLAGS) $(INCLUDES) imageUtils.o colorUtils.o imageDriver.c -o imageDriver $(INCLUDES)

imageUtils.o: imageUtils.c imageUtils.h
	$(CC) $(FLAGS) $(INCLUDES) -c imageUtils.c -o imageUtils.o

colorUtilsTester: colorUtils.o colorUtilsTester.c
	$(CC) $(FLAGS) colorUtils.o colorUtilsTester.c -o colorUtilsTester $(INCLUDES)

colorUtils.o: colorUtils.c colorUtils.h
	$(CC) $(FLAGS) $(INCLUDES) -c colorUtils.c -o colorUtils.o

clean:
	rm -f *~ *.o
