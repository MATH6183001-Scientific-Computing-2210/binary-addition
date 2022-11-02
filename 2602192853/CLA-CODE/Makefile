CC = gcc

all: main.out

main.out:  2602192853.o main.o
	${CC} -o main.out main.o  2602192853.o -lm

2602192853.o: 2602192853/2602192853.c
	${CC} -Wall -c 2602192853/2602192853.c -o 2602192853.o -I.





clean:
	rm *.o 
	rm *.out