# Created date: 2021-04-06
default: 1cvik_25_02.o functions.o
	gcc 1cvik_25_02.o functions.o -o 1cvik

clean:
	rm *.exe *.o

1cvik_25_02.o: 1cvik_25_02.c
	gcc -c -o 1cvik_25_02.o 1cvik_25_02.c -O2 -Wall

functions.o: functions.c 1cvikh.h
	gcc -c -o functions.o functions.c -O2 -Wall

run: 1cvik_25_02.o functions.o
	gcc 1cvik_25_02.o functions.o -o 1cvik
	./1cvik
	rm *.exe *.o