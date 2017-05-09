CC = ../../afl-clang-fast

FUZZER = ../../afl-fuzz

LIB_SRC = ../libs
ZLIB_SRC = $(LIB_SRC)/zlib-1.2.11

CFLAGS = -g -Wall -O2 

all: test

test: zpipe 
	AFL_I_DONT_CARE_ABOUT_MISSING_CRASHES=1 \
	$(FUZZER) -i input -o output ./zpipe -d @@ /dev/null
	
# Assumes you're calling from sumanajana/zlib/
zlib:
	@echo "<<<<<<<<<<<< THIS DOESN'T WORK >>>>>>>>>>>>"
	cd $(ZLIB_SRC)
	CC=../$(CC) CFLAGS="$(CFLAGS)" ./configure
	make -j4
	cd ../../zlib

zpipe: zpipe.c $(ZLIB_SRC)/libz.a
	$(CC) $(CFLAGS) -I$(ZLIB_SRC) $< $(ZLIB_SRC)/libz.a -o $@

.PHONY: clean
clean:
	rm -f *.o *.a *.gc* zpipe
