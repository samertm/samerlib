CC=gcc
CFLAGS=-c -Wall -g -fpic
HEADERDIR=/usr/local/include/samerlib
LIBDIR=/usr/local/lib
INSTALL=install -D

all: libstack.so libqueue.so libbtree.so libmap.so

install: all
	$(INSTALL) queue.h $(HEADERDIR)/queue.h
	$(INSTALL) stack.h $(HEADERDIR)/stack.h
	$(INSTALL) btree.h $(HEADERDIR)/btree.h
	$(INSTALL) map.h   $(HEADERDIR)/map.h
	$(INSTALL) libqueue.so $(LIBDIR)/libqueue.so
	$(INSTALL) libstack.so $(LIBDIR)/libstack.so
	$(INSTALL) libbtree.so $(LIBDIR)/libbtree.so
	$(INSTALL) libmap.so   $(LIBDIR)/libmap.so
	ldconfig

test: test.c
	$(CC) -g -o test test.c -lstack -lqueue -lmap

libbtree.so: btree.o
	$(CC) -shared -o libbtree.so btree.o

btree.o: btree.c btree.h
	$(CC) $(CFLAGS) btree.c

libqueue.so: queue.o
	$(CC) -shared -o libqueue.so queue.o

queue.o: queue.c queue.h
	$(CC) $(CFLAGS) queue.c

libstack.so: stack.o
	$(CC) -shared -o libstack.so stack.o

stack.o: stack.c stack.h
	$(CC) $(CFLAGS) stack.c

libmap.so: map.o
	$(CC) -shared -o libmap.so map.o -lqueue

map.o: map.c map.h
	$(CC) $(CFLAGS) map.c

clean:
	rm *.o *.so
