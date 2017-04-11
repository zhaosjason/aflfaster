CC = ../afl-clang
CXX = ../afl-clang++

INCLUDES =

CFLAGS = -g -Wall -O0 $(INCLUDES)
CXXFLAGS = -g -Wall $(INCLUDES)

LDFLAGS = -g
LDLIBS = --coverage


#beginning
test: test1
	../afl-fuzz -i input -o output ./test1 @@

test1: test1.o
	AFL_HARDEN=1 $(CC) $(LDFLAGS) test1.o -o test1
test1.o:
	AFL_HARDEN=1 $(CC) $(CFLAGS) -c test1.c -o test1.o

.PHONY: clean
clean:
	rm -f *.o a.out core test1 *.a
