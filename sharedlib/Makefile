OBJS = main.o print.o input.o
TARGET = test
CC = gcc
CFLAGS = -g
LDFLAGS = -lljh

$(TARGET) : $(OBJS)
	$(CC) -o $@ $^ $(CFLAGS) -L.$(LDFLAGS)

.c.o:
	$(CC) -c -o $@ $<
clean : 
	rm -f *.o test
