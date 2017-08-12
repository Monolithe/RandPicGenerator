build/randpic: build/main.o build/bmpimg.o
	gcc -o build/randpic build/main.o build/bmpimg.o

build/main.o: main.c
	gcc -o build/main.o -c main.c

build/bmpimg.o: src/bmpimg.c
	gcc -o build/bmpimg.o -c src/bmpimg.c
