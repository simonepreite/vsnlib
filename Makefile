CC=gcc
BUILDDIR=build/

all: clean bdircreat vnslibc

bdircreat:
	mkdir -p build

vnslib-all: vnslibc vnslibs
		$(CC) -o $(BUILDDIR)vnslib $(BUILDDIR)vnslibc.o $(BUILDDIR)vnslibs.o

vnslibc:	vnslibc.c vnslib.h
		$(CC) -c -o build/vnslibc.o vnslibc.c

vnslibs:	vnslibs.c vnslib.h
		$(CC) -c -o build/vnslibs.o vnslibs.c

clean:
		rm -rf ./build
