CC = ../afl-gcc
CXX = ../afl-g++

INCLUDES =
LIB_SRC = libs
ZLIB_SRC = $(LIB_SRC)/zlib-1.2.11

CFLAGS = -g -Wall -O2 
CXXFLAGS = -g -Wall

LDFLAGS = -g
LDLIBS = --coverage

all: zlib

#beginning
test: test1
	../afl-fuzz -i input -o output ./test1 @@

test1: test1.o
	AFL_HARDEN=1 $(CC) $(LDFLAGS) test1.o -o test1
test1.o:
	AFL_HARDEN=1 $(CC) $(CFLAGS) -c test1.c -o test1.o

zlib: zpipe.c
	$(CC) $(CFLAGS) -I$(ZLIB_SRC) $< $(ZLIB_SRC)/libz.a -o $@

.PHONY: clean
clean:
	rm -f *.o a.out core test1 *.a *.gc* zlib
