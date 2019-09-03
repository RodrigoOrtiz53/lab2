# cs335 lab2
# to compile your project, type make and press enter

all: lab2

lab2: lab2.c
	gcc lab2.c -Wall -olab2 -lm

clean:
	rm -f lab2
	rm -f *.o

