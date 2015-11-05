all: matrix.c main.c
	gcc -o matrix $^

clean:
	rm -f matrix
