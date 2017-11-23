CC=gcc
BUILDDIR=build/

all: clean bdircreat vnslib-all

bdircreat:
	mkdir -p build

vnslib-all: vnslibc vnslibs
		gcc -shared  -o build/libvnslib.so build/vnslibc.o build/vnslibs.o
		##ar rv build/vnslib.a build/vnslibc.o build/vnslibs.o
		##ranlib build/vnslib.a

vnslibc:	vnslibc.c vnslib.h
		$(CC) -fPIC -c -o build/vnslibc.o vnslibc.c

vnslibs:	vnslibs.c vnslib.h
		$(CC) -fPIC -c -o build/vnslibs.o vnslibs.c

clean:
		rm -rf ./build
