CC=gcc
BUILDDIR=build/

all: clean bdircreat vsnlib-all

bdircreat:
	mkdir -p build

vsnlib-all: vsnlib
		gcc -shared  -o build/libvsn.so build/vsnlib.o

vsnlib:	vsnlib.c vsnlib.h
		$(CC) -fPIC -c -o build/vsnlib.o vsnlib.c


clean:
		rm -rf ./build
