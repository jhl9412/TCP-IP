OBJS1 = main.o calculate.o error_handling.o 
OBJS2 = input.o
TARGET1 = server 
TARGET2 = input
cc = gcc
CFLAGS = -g
LDFLAGS = -lserver
LIB = libserver.a

all : $(TARGET1) $(TARGET2)
$(TARGET1):$(OBJS1) $(LIB)
	$(cc) -o $@ $< $(LDFLAGS) -L./ -I./ 
$(TARGET2):$(OBJS2)
	$(cc) -o $@ $< 

%.o:%.c
	$(cc) -c -o  $@ $< $(CFLAGS)

$(LIB):$(OBJS1)
	ar rscv $@ calculate.o error_handling.o 

clean:
	rm *.o $(TARGET1) $(TARGET2) *.a
