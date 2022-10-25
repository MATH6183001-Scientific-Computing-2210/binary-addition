CC = gcc

all: main.out

main.out: myutils.o my_cra.o main.o
	${CC} -o main.out main.o myutils.o my_cra.o -lm

my_cra.o: my_cra/my_cra.c
	${CC} -Wall -c my_cra/my_cra.c -o my_cra.o -I.

main.o: main.c
	${CC} -Wall -c main.c -o main.o

myutils.o: utils/myutils.c
	${CC} -Wall -c utils/myutils.c -o myutils.o 

clean:
	rm *.o 
	rm *.out