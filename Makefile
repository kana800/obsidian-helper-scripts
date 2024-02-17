CC=gcc

BUILDDIR := build
REMINDERDIR := reminder
JOURNALDIR := journal

rem:
	$(CC) $(REMINDERDIR)/main.c -o $(BUILDDIR)/$@

jrnl: 
	$(CC) $(JOURNALDIR)/main.c -o $(BUILDDIR)/$@
