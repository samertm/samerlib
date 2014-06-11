CC=gcc
CFLAGS=-c -Wall -g -fpic
HEADERDIR=/usr/local/include/samerlib
LIBDIR=/usr/local/lib
INSTALL=install -D

all: libstack.so libqueue.so libbtree.so

install: all
	$(INSTALL) queue.h $(HEADERDIR)/queue.h
	$(INSTALL) stack.h $(HEADERDIR)/stack.h
	$(INSTALL) btree.h $(HEADERDIR)/btree.h
	$(INSTALL) libqueue.so $(LIBDIR)/libqueue.so
	$(INSTALL) libstack.so $(LIBDIR)/libstack.so
	$(INSTALL) libbtree.so $(LIBDIR)/libbtree.so
	ldconfig

test: test.c
	$(CC) -g -o test test.c -lstack -lqueue

libbtree.so: btree.o
	$(CC) -shared -o libbtree.so btree.o

btree.o: btree.c
	$(CC) $(CFLAGS) btree.c

libqueue.so: queue.o
	$(CC) -shared -o libqueue.so queue.o

queue.o: queue.c
	$(CC) $(CFLAGS) queue.c

libstack.so: stack.o
	$(CC) -shared -o libstack.so stack.o

stack.o: stack.c
	$(CC) $(CFLAGS) stack.c

clean:
	rm *.o *.so
