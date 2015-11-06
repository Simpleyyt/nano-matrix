all: matrix.c main.c array.c
	gcc -o matrix $^ -lm

clean:
	rm -f matrix
