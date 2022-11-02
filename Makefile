CC = gcc

all: main.out

main.out: myutils.o main.o
	${CC} -o main.out *.o -lm

my_cra.o: my_cra/my_cra.c
	${CC} -Wall -c my_cra/my_cra.c -o my_cra.o -I.

my_cla.o: my_cla/my_cla.c
	${CC} -Wall -c my_cla/my_cla.c -o my_cla.o -I.

main.o: main.c
	${CC} -Wall -c main.c -o main.o

myutils.o: utils/myutils.c
	${CC} -Wall -c utils/myutils.c -o myutils.o 

liststudentid:
	find . -type d -regex "\./[0-9][0-9]*.*" -maxdepth 1 

readfromfile:
	while read p; do echo "$p"; done < list_students.txt


clean:
	rm -f *.o 
	rm -f *.out
	find . | grep -E "(/__MACOSX)" | xargs rm -rf