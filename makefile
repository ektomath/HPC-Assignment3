all: newton

newton: newton.c
	gcc -o newton newton.c -O2 -march=native -lpthread -lm

clean:
	rm newton