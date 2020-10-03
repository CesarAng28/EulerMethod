Implementation: Implementation.o Euler.o Files.o
	gcc -o Implementation Implementation.o Euler.o Files.o

Implementation.o: Implementation.c
	gcc -c Implementation.c

Euler.o: Euler.c
	gcc -c Euler.c

Files.o: Files.c
	gcc -c Files.c

clean:
	rm *.o
