CC=cc
FLAG_CC=-ldl -lpthread -llwipv6 -lvsn -g
BUILDDIR=./build/
OBJ=$(BUILDDIR)minlibnetlink.o
FLAG_PREP=-c -o


all: test4 test6

test4: buildlib $(OBJ)
	$(CC) $(FLAG_PREP) $(BUILDDIR)test4.o test4_vsnlib.c
	$(CC) -o $(BUILDDIR)test4.exe $(BUILDDIR)test4.o $(OBJ) $(FLAG_CC)

test6: buildlib $(OBJ)
	$(CC) $(FLAG_PREP) $(BUILDDIR)test6.o test6_vsnlib.c
	$(CC) -o $(BUILDDIR)test6.exe $(BUILDDIR)test6.o $(OBJ) $(FLAG_CC)

buildlib:
	mkdir -p $(BUILDDIR)
	$(CC) $(FLAG_PREP) $(BUILDDIR)minlibnetlink.o minlibnetlink.c

clean:
	rm -rf build
