CC=gcc

BUILDDIR := build

rem:
	$(CC) src/main.c -o $(BUILDDIR)/$@
