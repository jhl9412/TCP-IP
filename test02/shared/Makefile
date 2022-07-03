OBJS1 = main.o calculate.o error_handling.o 
OBJS2 = input.o
MAIN  = main.c
TARGET1 = server 
TARGET2 = input
cc = gcc
CFLAGS = -g
LDFLAGS = -lserver
LIB = libserver.so
UPATH = /home/ubuntu/ljh/test02/shared

all : $(TARGET1) $(TARGET2)
$(TARGET1): $(OBJS1) $(LIB)
	$(cc) -o $@ $< $(LDFLAGS) -L./ 
$(TARGET2):$(OBJS2)
	$(cc) -o $@ $< 

%.o:%.c server.h
	$(cc) -fPIC -c -o  $@ $< $(CFLAGS) 

$(LIB):$(OBJS1)
	$(cc) -shared -o $@ calculate.o error_handling.o

export:
	export LD_LIBRARY_PATH=$(UPATH)

clean:
	rm *.o *.so $(TARGET1) $(TARGET2)
