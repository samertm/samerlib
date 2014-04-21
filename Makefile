CC=gcc
CFLAGS=-c -Wall -g

test: test.c
	$(CC) -g -o test test.c -lstack

all: libstack.so

install: all
	install stack.h /usr/local/include/samerlib/stack.h
	install libstack.so /usr/local/lib/libstack.so

libstack.so: stack.o
	$(CC) -shared -o libstack.so stack.o

stack.o: stack.c
	$(CC) $(CFLAGS) -fpic stack.c

clean:
	rm *.o *.so
