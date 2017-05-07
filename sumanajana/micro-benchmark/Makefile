CC = ../../afl-gcc
CXX = ../../afl-g++

CFLAGS = -g -Wall -O2 
CXXFLAGS = -g -Wall

LDFLAGS = -g
LDLIBS = --coverage

#beginning
test: micro
	../../afl-fuzz -i input -o output ./$< @@

micro: micro.o
	AFL_HARDEN=1 $(CC) $(LDFLAGS) $< -o $@

micro.o: micro.c
	AFL_HARDEN=1 $(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -f *.o micro *.a *.gc*
