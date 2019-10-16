objects = main.o

CC = g++

OPTIONS = -lpthread

a.out: $(objects)
	$(CC) -o a.out $(objects)

main.o: main.cpp BBSTree.h
	$(CC) -c main.cpp -o main.o $(OPTIONS)

.PHONY: clean

clean:
	rm -f a.out *.o