PROGRAM = sharkhead-clone
CC      = gcc
CFLAGS  = -g -Wall -Wextra -lm -std=c99
LDLIBS  = -lglut -lGLU -lGL -lSOIL

$(PROGRAM): main.c
	$(CC) -o $(PROGRAM) main.c $(CFLAGS) $(LDLIBS)

.PHONY: clean 

clean:
	-rm *.o $(PROGRAM) *core