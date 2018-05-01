.PHONY: clean run build

build: main

main: main.o thread.o
	gcc -pthread -o main main.o thread.o --std=c11

main.o: main.c thread.h
	gcc -pthread -c main.c --std=c11

thread.o: thread.c thread.h
	gcc -pthread -c thread.c --std=c11

clean:
	rm -rvf *.o main
