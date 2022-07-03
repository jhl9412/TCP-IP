OBJS = main.o print.o input.o
TARGET = test
CC = gcc
CFLAGS = -g

$(TARGET) : $(OBJS)
	$(CC) -o $@ $^ $(CFLAGS)
.c.o:
	$(CC) -c -o $@ $<
clean : 
	rm -f *.o test
