CC=gcc
BUILDDIR=build/

all: clean bdircreat vsnlib-all

bdircreat:
	mkdir -p build

vsnlib-all: vsnlibc vsnlibs
		gcc -shared  -o build/libvsnlib.so build/vsnlibc.o build/vsnlibs.o
		##ar rv build/vsnlib.a build/vsnlibc.o build/vsnlibs.o
		##ranlib build/vsnlib.a

vsnlibc:	vsnlibc.c vsnlib.h
		$(CC) -fPIC -c -o build/vsnlibc.o vsnlibc.c

vsnlibs:	vsnlibs.c vsnlib.h
		$(CC) -fPIC -c -o build/vsnlibs.o vsnlibs.c

clean:
		rm -rf ./build
