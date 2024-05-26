all: main

main: main.c function.c
	gcc main.c function.c -o main -lm

clean:
	rm -f main
