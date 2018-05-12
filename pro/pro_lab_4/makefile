.PHONY: clean

main: vector.o thread.o main.o
	gcc -o main vector.o thread.o main.o -pthread --std=c11

main.o: main.c
	gcc -c main.c --std=c11

thread.o: thread.c thread.h
	gcc -c thread.c thread.h at_struct.h --std=c11

vector.o: vector.c vector.h
	gcc -c vector.c vector.h --std=c11

clean:
	rm -vf *.o main
