CC = ../../afl-clang-fast
CFLAGS = -g -Wall -O2 

FUZZER = ../../afl-fuzz

test: micro
	$(FUZZER) -i input -o output ./$< @@

micro: micro.o
	AFL_HARDEN=1 $(CC) $(LDFLAGS) $< -o $@

micro.o: micro.c
	AFL_HARDEN=1 $(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -f *.o micro *.a *.gc*
