CC=gcc

BUILDDIR := build
JOURNALDIR := journal

all: jrnl

jrnl: 
	$(CC) $(JOURNALDIR)/main.c -o $(BUILDDIR)/$@
