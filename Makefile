# Welcomre to Mamat, 044101
#
# This is the project's Makefile. It contains the instructions for compiling
# the projects C files, and then link the generated objects into an executable.
# This simple file will compile "main.c" to "main.o" and then link it (with C
# runtime library) to the executable "prog.exe".
#
# To compile, open the terminal in the folder that contains
# this file and run "make".
#
# To clean, open the terminal in the folder that contains
# this file and run "make clean".
#
# All eclipse projects in this machine are under /home/mamat/Documents/

CC     = gcc
CCLINK = $(CC)
CFLAGS = -Wall -g -std=c99
OBJS   = ransom.c


prog.exe: $(OBJS)
	$(CCLINK) $(OBJS) -o prog.exe

ransom.o: ransom.c
	$(CC) $(CFLAGS) -c  ransom.c

clean:
	rm -fr *.exe $(OBJS)
