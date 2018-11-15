all: main.c wow.h
	gcc main.c

run:
	./a.out

clean:
	rm *.o
